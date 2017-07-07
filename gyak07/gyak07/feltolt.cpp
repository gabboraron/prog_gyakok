#include <iostream>
#include <fstream>
#include "feltolt.h"

using namespace std;

void feltoltPont(std::vector<Pont>& p, const std::string& fname) throw (feltoltHiba)
{
    ifstream inp;
    inp.open(fname.c_str());
    if (inp.fail()) throw hibasFajlnev;
    p.clear();
    double x,y;
    inp>>x>>y;
    while(!inp.fail())
    {
        Pont t(x,y);
        p.push_back(t);
        inp>>x>>y;
    }
    cout<<"A beolvasott pontok ("<<p.size()<<" darab):\n";
    for(int i=0; i<(int)p.size(); ++i)
    {
        p[i].Kiir();
        cout<<endl;
    }
    inp.close();
}

void feltoltKor(std::vector<Kor>& k, const std::string& fname) throw (feltoltHiba,Kor::KorHiba)
{
    ifstream inp;
    inp.open(fname.c_str());
    if (inp.fail()) throw hibasFajlnev;
    k.clear();
    double x,y,r;
    inp>>x>>y>>r;
    while(!inp.fail())
    {
        Pont t(x,y);
        try{
            Kor z(t,r);
            k.push_back(z);
        }catch(Kor::KorHiba err)
        {
            throw err;
        }
        inp>>x>>y>>r;
    }
    cout<<"A beolvasott korok ("<<k.size()<<" darab):\n";
    for(int i=0; i<(int)k.size(); ++i)
    {
        k[i].Kiir();
        cout<<endl;
    }
    inp.close();
}
