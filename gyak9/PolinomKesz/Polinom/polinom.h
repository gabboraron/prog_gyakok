#ifndef POLINOM_H_INCLUDED
#define POLINOM_H_INCLUDED

class Polinom{
    private:
        double a,b,c;
    public:
        Polinom():a(0),b(0),c(0) {}
        Polinom(double x, double y, double z): a(x),b(y),c(z) {}
        friend std::istream& operator>>(std::istream& inp, Polinom& p);
        friend std::ifstream& operator>>(std::ifstream& inp, Polinom& p);
        friend std::ostream& operator<<(std::ostream& out, const Polinom& p);
        Polinom operator*=(double q);
        //friend Polinom operator+(const Polinom& p1, const Polinom& p2);
        Polinom operator+(const Polinom& p)const;
        Polinom operator*(double x) const;
        friend Polinom operator*(double x, const Polinom& p2);
        //friend bool operator==(const Polinom& p1, const Polinom& p2);
        bool operator==(const Polinom& p) const;
        double Ertek(double x) const;

};

#endif // POLINOM_H_INCLUDED
