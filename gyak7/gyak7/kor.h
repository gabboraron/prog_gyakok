#ifndef KOR_H_INCLUDED
#define KOR_H_INCLUDED
#include "pont.h"
#define PI 3.1415965

class Kor{
private:
    Pont kp;
    double r;
    double tavolsag(const Pont&) const;
public:
    enum KorHiba {HibasSugar};
    Kor() {r=0;}
    Kor(double a, double b, double c);
    Kor(const Pont& p, double c): kp(p), r(c) {if(c<0) throw HibasSugar;}
    void Kiir()const;
    double Terulet() {return r*r*PI;}
    bool RajtaVane(const Pont&) const;
};

#endif // KOR_H_INCLUDED
