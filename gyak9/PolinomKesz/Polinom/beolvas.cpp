#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "beolvas.h"

using namespace std;

//Feladat: Adatok beolvas�sa f�jlb�l, kiv�telkez�lessel
void Beolvas(vector <Polinom >& x)
{
    bool hiba;
    do{
        string tmp;
        string fajlnev;
        cout<<"\nBemenet fajl neve (Enter eseten: teszt.txt):"; getline(cin,fajlnev);
        if(fajlnev=="") fajlnev="teszt.txt";
        hiba=false;
        try{
            Feltolt(x,fajlnev);
        }catch(FileInputE err){
            hiba=true;
            switch (err){
                case Open_Error:
                    cout<<"Nem sikerult "<<fajlnev<<" fajlt megnyitni.\n";
                    break;
                case Size_Error:
                    cout<<"A fajlban hibas az adatok szama.\n";
                    break;
                case Data_Error:
                    cout<<"A fajlban hibas, vagy keves adat talalhato.\n";
            }
        }
        if(hiba){
             char ch;
             do{
                cout<<"\nProbaljam ujra a beolvasast? (i/n) ";
                getline(cin,tmp);
                if(tmp.size()>0) ch=tolower(tmp[0]); else ch='a';
             }while(ch!='i' && ch!='n');
                if(ch=='n') exit(1);
            }
        }while(hiba);

}

//Feladat: A param�terben kapott vektor ki�r�sa
void Kiir(const vector<Polinom> &x)
{
    cout<<"\nA beolvasott adatok:\n";
    for(int i=0; i<(int)x.size(); ++i){

            cout<<i+1<<". "<<x[i];


    }
    cout<<endl;
}


//Feladat: a kapott bemen� f�jlb�l felt�lti a param�terben kapott t�mb�t
//Hib�t dob, ha nem siker�lt a f�jlt megnyitni, vagy helytelen volt az adatok sz�ma
void Feltolt(vector<Polinom> &x, string& fn) throw (FileInputE)
{
    ifstream f(fn.c_str());
    if (f.fail())  throw Open_Error;
    int n;
    f>>n;
    if(f.fail() || n<1) throw Size_Error;
    x.resize(n);
    for (int i=0;i<n;++i){
        f>>x[i];
        if(f.fail()) throw Data_Error;
        }

    f.close();
}

//Feladat: 		Val�s sz�mot olvas be a billenty�zetr�l.
double  ReadReal(const string msg, const string errmsg)
{
    double a;
    bool hiba;
    string tmp;
    do{
        cout << msg;
        string str;
        cin >> a;
        hiba = cin.fail();
        if(hiba) {
            cout << errmsg << endl;
            cin.clear(); getline(cin, tmp);
        }
    }while(hiba);
    getline(cin, tmp);
    return a;
}
