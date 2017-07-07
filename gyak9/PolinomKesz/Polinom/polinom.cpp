#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "polinom.h"

using namespace std;

double  ReadReal(istream& inp, const string msg, const string errmsg)
{
    double a;
    bool hiba;
    string tmp;
    do{
        cout << msg;
        string str;
        inp >> a;
        hiba = inp.fail();
        if(hiba) {
            cout << errmsg << endl;
            inp.clear(); getline(inp, tmp);
        }
    }while(hiba);
    getline(inp, tmp);
    return a;
}

istream& operator>>(istream& inp, Polinom& p)
{
    cout<<"Kerem a Polinom egyutthatoit\n";
    //cout<<"negyzetes tag egyutthatoja:"; inp>>p.a;
    p.a=ReadReal(inp,"negyzetes tag egyutthatoja:","valos szamot kerek\n");
    //cout<<"linearis tag egyutthatoja:"; inp>>p.b;
    p.b=ReadReal(inp,"linearis tag egyutthatoja:","valos szamot kerek\n");
    //cout<<"konstans tag:"; inp>>p.c;
    p.c=ReadReal(inp,"konstans tag:","valos szamot kerek\n");
    return inp;
}

ifstream& operator>>(ifstream& inp, Polinom& p)
{
    inp>>p.a>>p.b>>p.c;
    return inp;
}

ostream& operator<<(ostream& out, const Polinom& p)
{
    out<<p.a<<"*x^2 + "<<p.b<<"*x + "<<p.c<<endl;
    return out;
}

Polinom Polinom::operator*=(double q)
{
    a*=q;
    b*=q;
    c*=q;
    return *this;
}

//friend + operator

/*Polinom operator+(const Polinom& p1, const Polinom& p2)
{
    //Polinom uj;
    //uj.a=p1.a+p2.a;
    //uj.b=p1.b+p2.b;
    //uj.c=p1.c+p2.c;
    //Egyszerubben
    Polinom uj(p1.a+p2.a,p1.b+p2.b,p1.c+p2.c);
    return uj;
}*/

//Sajat + operátorral

Polinom Polinom::operator+(const Polinom& p)const
{
    Polinom uj(a+p.a,b+p.b,c+p.c);
    return uj;
}

Polinom Polinom::operator*(double x) const
{
    Polinom uj(a*x,b*x,c*x);
    return uj;
}

Polinom operator*(double x, const Polinom& p2)
{
    Polinom uj;
    uj.a=p2.a*x;
    uj.b=p2.b*x;
    uj.c=p2.c*x;
    return uj;
}

/*bool operator==(const Polinom& p1, const Polinom& p2)
{
    return p1.a==p2.a && p1.b==p2.b && p1.c==p2.c;
}
*/

bool Polinom::operator==(const Polinom& p) const
{
    return a==p.a && b==p.b && c==p.c;
}


double Polinom::Ertek(double x) const
{
    return ((a*x)+b)*x+c;
}









