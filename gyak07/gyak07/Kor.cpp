#include <iostream>
#include <cmath>
#include "Kor.h"

using namespace std;

//K�r ki�r�sa
void Kor::Kiir() const
{
    cout<<"Kozeppont: ";
    kp.Kiir();
    cout<<" Sugar:"<<r<<" ";
}

//Adott pont t�vols�ga a k�r k�z�ppontj�t�l
//Priv�t f�ggv�ny, k�v�lr�l nem h�vhat�
double Kor::tavolsag(const Pont& p) const
{
    return sqrt((kp.GetX()-p.GetX())*(kp.GetX()-p.GetX())+
                (kp.GetY()-p.GetY())*(kp.GetY()-p.GetY()));
}

//Adott pont rajta van-e a k�rlemezen
bool Kor::RajtaVane(const Pont& p) const
{
    double d=tavolsag(p);
    return d<=r;
}
