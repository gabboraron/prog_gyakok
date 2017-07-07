#include <iostream>
#include <vector>
#include "pont.h"
#include "kor.h"
#include "feltolt.h"

using namespace std;

void teszt();
void feladat();

bool LinKer(const vector<Kor>&, const vector<Pont>&, int&);
bool OptEldont(const Kot&; const vector<Pont>&);//ha mindet akkor igaz ha nem akkor hamis

int main()
{
    /*
     feladat:
     típus megvalósítása osztállyal, pont és kör típus készítése,
     majd ezekkel a következõ feladat megoldása: adott n darab kör és m darab pont,
     van-e olyan kör, amelyik mindegyik pontot tartalmazza?
    */

    cout<<"Osztalyok1: "<<endl;
    //teszt();
    feladat();
    return 0;
}


void teszt()
{
    //pont letrehozasa
   Pont p1;
   Pont p2(1.2,-3.5);
   cout<<"p1: ("<<p1.GetX()<<", "<<p1.GetY()<<")\n";
   p1.SetXY(-1,-1);
   cout<<"p1: ("<<p1.GetX()<<", "<<p1.GetY()<<")\n";
   p2.Kiir();
    /* */
    cout<<"\n **** \n";
    Kor k1;
    k1.Kiir(); cout<<endl;
    Kor k2(1,1,5);
    k2.Kiir(); cout<<endl;
    Kor k3(p2,10);
    k3.Kiir(); cout<<endl;
    try{
        Kor k4(1,1,-2);
    } catch (Kor::KorHiba err)
    {
        cout<<"Negativ sugaru kort probalt letrehozni; \n";
    }
    cout<<"\n ++++ \n";
    if(k2.RajtaVane(p1)) cout<<"Rajta van\n"; else cout<<"Nincs rajta \n";
    Kor k5;
    if(k5.RajtaVane(p1)) cout<<"Rajta van\n"; else cout<<"Nincs rajta \n";
}

void feladat()
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

    if(l1 && l2){
        //Feladat megoldasa

    }
}
