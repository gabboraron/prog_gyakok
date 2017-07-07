#include <iostream>
#include <cmath>
#include "Kor.h"

using namespace std;

//Kör kiírása
void Kor::Kiir() const
{
    cout<<"Kozeppont: ";
    kp.Kiir();
    cout<<" Sugar:"<<r<<" ";
}

//Adott pont távolsága a kör középpontjától
//Privát függvény, kívülrõl nem hívható
double Kor::tavolsag(const Pont& p) const
{
    return sqrt((kp.GetX()-p.GetX())*(kp.GetX()-p.GetX())+
                (kp.GetY()-p.GetY())*(kp.GetY()-p.GetY()));
}

//Adott pont rajta van-e a körlemezen
bool Kor::RajtaVane(const Pont& p) const
{
    double d=tavolsag(p);
    return d<=r;
}
