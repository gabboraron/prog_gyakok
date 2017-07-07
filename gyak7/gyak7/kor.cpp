#include "kor.h"
#include <cmath>

using namespace std;

Kor::Kor(double a, double b, double c)
{
        if(c<0) throw HibasSugar;
        kp.SetXY(a,b);
        r=c;
}

/*Kor::Kor(const Pont& p, double c)
{
    kp.SetXY(p.GetX(),p.GetY());
    if(c<0) throw HibasSugar;
    r = c;
}
*/
void Kor::Kiir()const
{
    cout<<"Kozeppont: ";
    kp.Kiir();
    cout<<" Sugar:"<<r;
}

double Kor::tavolsag(const Pont& p) const
{
    return sqrt(
                (kp.GetX()-p.GetX())*(kp.GetX()-p.GetX()) +
                (kp.GetY()-p.GetY())*(kp.GetY()-p.GetY())
                );
}

bool Kor::RajtaVane(const Pont& p) const
{
    return(tavolsag(p) <= r);
}
