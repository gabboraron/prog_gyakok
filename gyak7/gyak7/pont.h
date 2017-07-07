#ifndef PONT_H_INCLUDED
#define PONT_H_INCLUDED
#include <iostream>

class Pont{
private:
    //kivulrol nwm lathato valtozok
    double x,y;
public:
    //konstruktorok
    //Pont(double a, double b) {x=a; y=b;}
    Pont(double a, double b) :x(a),y(b) {}
    //Pont() {x=0; y=0;} //Pont p1; et kezeli le
    Pont(): x(0), y(0) {}
    //hol a pont
    //lekaerdezese x koordinatanak
    double GetX() const {return x;}
    double GetY() const {return y;}
    void SetX(double a) {x=a;}
    void SetY(double b) {y=b;}
    void SetXY(double a, double b) {x=a; y=b;}
    void Kiir() const{std::cout<<"("<<x<<" "<<y<<")";}
    //destruktor
    //~Pont() {std::cout<<x<<" "<<y<<" pont megszunt\n";}
};


#endif // PONT_H_INCLUDED
