#ifndef BEOLVAS_H_INCLUDED
#define BEOLVAS_H_INCLUDED
#include <vector>
#include <string>
#include "polinom.h"

enum FileInputE { Open_Error, Size_Error, Data_Error};

void Beolvas(std::vector < Polinom >& x);
void Feltolt(std::vector<Polinom > &x, std::string& fn) throw (FileInputE);
void Kiir(const std::vector<Polinom> &x);
double  ReadReal(const std::string msg, const std::string errormsg);

#endif // BEOLVAS_H_INCLUDED
