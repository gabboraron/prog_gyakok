#ifndef PONT_H_INCLUDED
#define PONT_H_INCLUDED
#include <iostream>

class Pont
{
private:
    double x,y;
public:
    //Konstruktorok a ponthoz
    //Pont() {x=0;y=0;}
    Pont() : x(0),y(0) {}
    //Pont(double a,double b) {x=a;y=b;}
    Pont(double a, double b): x(a), y(b) {}
    double GetX() const {return x;}
    double GetY() const {return y;}
    void SetX(double a) {x=a;}
    void SetY(double a) {y=a;}
    void SetXY(double a, double b) {x=a; y=b;}
    void Kiir() const {std::cout<<"("<<x<<","<<y<<")";}
    //Destruktor most nem kell, de ha k�v�ncsiak vagyunk hol h�vja meg a ford�t�program, pr�b�ljuk ki:
    //~Pont() {std::cout<<x<<" "<<y<<" pont megszunt\n";}
};


#endif // PONT_H_INCLUDED
