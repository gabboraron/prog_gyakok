#ifndef KOR_H_INCLUDED
#define KOR_H_INCLUDED
#include "Pont.h"
#define PI 3.14159265

class Kor
{
private:
    Pont kp;
    double r;
    double tavolsag(const Pont& p) const;
public:
    enum KorHiba {HibasSugar};
    Kor(): r(0) {}
    //Invari�ns tulajdons�g: sug�r nem leht negat�v
    //Konstruktorok ellen�rzik, hib�t dobnak, ha nem teljes�l
    Kor(double a, double b, double c)throw (KorHiba): kp(a,b), r(c)
    { if (c<0) throw HibasSugar;}
    Kor(const Pont& p, double c)throw (KorHiba) : kp(p),r(c)
    { if (c<0) throw HibasSugar;}
    void Kiir() const;
    double Terulet() const {return r*r*PI;}
    bool RajtaVane(const Pont& p) const;
};


#endif // KOR_H_INCLUDED
