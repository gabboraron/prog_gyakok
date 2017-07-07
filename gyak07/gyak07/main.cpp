#include <iostream>
#include <vector>
#include "Pont.h"
#include "Kor.h"
#include "feltolt.h"

using namespace std;

//Feladat:
//Pont és Kör típus megvalósítása osztállyal
//Pont: két valós szám (a koordináták)
//Kör: egy Pont (a középpont) és a sugár (pozitív kell legyen)

//Osztályokat tesztelõ függvény
void Teszt();

//Feladatot megoldó függvény
void Feladat();

//Feladat: van-e olyan kör, amelyik mindegyik pontot tartalmazza
bool LinKer(const vector<Kor>&,const vector<Pont>&, int&);
bool OptEldont(const Kor&,const vector<Pont>&);

int main()
{
    cout << "Osztalyok I." << endl;
    //Teszt();
    Feladat();

    return 0;
}

void Teszt()
{
    Pont p1;
    Pont p2(1.2,-3.5);
    cout<<"p1=("<<p1.GetX()<<","<<p1.GetY()<<")\n";
    p2.Kiir(); cout<<endl;
    p1.SetXY(-1,0);
    p1.Kiir(); cout<<endl;
    try{
        Kor k1;
        k1.Kiir(); cout<<endl;
        Kor k2(1,1,5);
        k2.Kiir(); cout<<endl;
        Kor k3(p2,1);
        k3.Kiir(); cout<<endl;
        //Kor k4(p2,-3);
        //k2,p1 rajta van
        //k3, p1 nincs rajt
        if(k3.RajtaVane(p1))
            cout<<"Rajta van\n";
        else
            cout<<"Nincs rajta\n";
    }catch(Kor::KorHiba err)
    {
        cout<<"Negativ sugaru kort nem lehet letrehozni!\n";
    }
    vector<Pont> x;
    x.resize(10);
    vector<Kor> y(100);

}

void Feladat()
{
    vector<Pont> p;
    vector<Kor> z;
    string fajlnev;
    bool l1,l2;
    try{
        l1=true;
        cout<<"Adja meg a pontokat tartalmazo fajl nevet:";
        cin>>fajlnev;
        feltoltPont(p,fajlnev);
    }catch(feltoltHiba err)
    {
        cout<<"Nem sikerult "<<fajlnev<<" bemeneti fajl megnyitasa!\n";
        l1=false;
    }
    try{
        l2=true;
        cout<<"Adja meg a koroket tartalmazo fajl nevet:";
        cin>>fajlnev;
        feltoltKor(z,fajlnev);
    }
    catch(feltoltHiba err)
    {
        cout<<"Nem sikerult "<<fajlnev<<" bemeneti fajl megnyitasa!\n";
        l2=false;
    }
    catch(Kor::KorHiba)
    {
        cout<<fajlnev<<" fajlban negativ sugaru kort talaltam!\n";
        l2=false;
    }
    if(l1 && l2){
        //Feladat megoldasa
        bool l; int ind;
        l=LinKer(z,p,ind);
        if(l)
        {
            cout<<ind+1<<". kor tartalmazza valamennyi pontot.\n";
            z[ind].Kiir(); cout<<endl;
        }else{
            cout<<"Nincs olyan kor, amelyik az osszes pontot tartalmazza";
        }
    }
}


bool LinKer(const vector<Kor>& k,const vector<Pont>& p, int& ind)
{
    bool l=false;
    for(int i=0; !l && i<(int)k.size(); ++i)
    {
        l=OptEldont(k[i],p);
        ind=i;
    }
    return l;
}

bool OptEldont(const Kor& k,const vector<Pont>& p)
{
  bool l=true;
  for(int i=0; l && i<(int)p.size(); ++i)
  {
      l=k.RajtaVane(p[i]);
  }
  return l;
}
