#include <string>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include "seqoutfile.h"

//Feladat:    Eredm�ny f�jl megnyit�sa
//Bemenet:    string fname - sz�veges �llom�ny neve
//Kimenet:    ofstream g   - l�trehozott szekvenci�lis output f�jl
SeqOutFile::SeqOutFile(std::string fname)
{
    if ( fname.size()<1 ) {
        std::cout<< "Add meg a kimenet fajl nevet:" ;
        std::cin>>fname;
    }
    g.open(fname.c_str());
    if ( g.fail() ){
        std::cout<< "Nem sikerult letrehozni a fajlt" <<std::endl;
        char ch; std::cin>>ch;
        exit(2);
    }
}

//Feladat:    V�laszol� adatainak ki�r�sa a szekvenci�lis outputf�jlba
//Bemenet:    Tabella dy   - v�laszol� adatai
//            ofstream g  - felm�r�s adatait tartalmaz� szekvenci�lis outputf�jl
//Kimenet:    ofstream g  - felm�r�s adatait tartalmaz� szekvenci�lis outputf�jl
void SeqOutFile::Write(const Tabella &dy)
{
    g<<std::setw(30)<<dy.name
    <<std::setw(5)<<dy.db
    <<std::setw(5)<<dy.nyert
    <<std::setw(5)<<dy.db-dy.nyert
    <<std::setw(6)<<dy.ossz_dobott
    <<std::setw(6)<<dy.ossz_kapott
    <<"\n";
}

