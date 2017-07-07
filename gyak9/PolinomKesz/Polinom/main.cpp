#include <iostream>
#include <vector>
#include "polinom.h"
#include "beolvas.h"

using namespace std;
int MaxKer(vector<Polinom>&, double);

int main()
{
    cout << "Tipus megvalositasa osztallyal II." << endl;
    //operatorok tesztelese
    Polinom p1;
    cin>>p1;
    cout<<"p1 polinom: "<<p1;
    p1*=3.0;
    cout<<"Konstanszoros polinom (*=3) : "<<p1<<endl;
    Polinom p2(1,1,10), p3(-1,-5,20), p4;
    p4=p2+p3;
    cout<<"osszeadas:\n"<<"p2= "<<p2<<"p3= "<<p3<<"p4= "<<p4<<endl;
    cout<<"osszeadas mashogy:"<<p2+p3<<endl;
    p1=p2*2;
    cout<<"p1=p2*2 utan p1 polinom: "<<p1;
    p4=2*p3;
    cout<<"p4=2*p3 utan p4 polinom: "<<p4<<endl;
    cout<<"p1 polinom: "<<p1;
    cout<<"p1 polinom helyettesitesi erteke az x=1 helyen:"<<p1.Ertek(1)<<endl;
    cout<<"p2 polinom: "<<p2;
    if(p1==p2) cout<<"Egyenlok\n"; else cout<<"Nem egyenlok\n";
    cout<<endl;
    Polinom p5(p4);
    cout<<"p4 polinom: "<<p4;
    cout<<"p5 polinom: "<<p5;
    if(p5==p4) cout<<"Egyenlok\n"; else cout<<"Nem egyenlok\n";

    //Feladatok:
    //a) Olvassunk be fájlból p tömbbe polinomokat.
    //b) Olvassunk be egy adott x értéket, és írjuk ki azt a polinomot, amelyiknek
    //   az adott x helyen a legnagyobb a helyettesítési értéke.
    //c) (Hf)Olvassunk be egy polinomot, és döntsük el, hogy van-e a polinomok
    //   között a beolvasott polinommal egyenlõ, ha igen hányadik.
    vector <Polinom> p;
    Beolvas(p);
    Kiir(p);
    double x=ReadReal("x erteke:","Valos szamot kerek!");
    int sorszam=MaxKer(p,x);
    cout<<sorszam+1<<". polinom helyettesitesi ertke a maximalis.\n";
    return 0;
}

int MaxKer(vector<Polinom>& t, double x)
{
    if(t.size()==0){
        cout<<"Ures tombre nincs ertelmezve a maximum kereses!\n";
        return -1;
    }
    double max=t[0].Ertek(x);
    int ind=0;
    cout<<"1. Erteke: "<<max<<endl;
    for(int i=1; i<(int)t.size(); ++i){
        double e=t[i].Ertek(x);
        cout<<i+1<<". Erteke: "<<e<<endl;
        if(e>max){
            max=e;
            ind=i;
        }
    }
    return ind;
}
