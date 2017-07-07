#ifndef FELTOLT_H_INCLUDED
#define FELTOLT_H_INCLUDED
#include <vector>
#include <string>
#include "pont.h"
#include "kor.h"

enum feltoltHiba{hibasFajlnev};

void feltoltPont(std::vector<Pont>&, const std::string&) throw (feltoltHiba);
void feltoltKor(std::vector<Kor>&, const std::string&) throw (feltoltHiba);


#endif // FELTOLT_H_INCLUDED
