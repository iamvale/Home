#include "Articol.h"
#include<stdlib.h>
#include<string>

Articol::Articol()
{
    //ctor
}

Articol::Articol(std::string tit, int buc):titlu{tit},bucati{buc}
{

}


Articol::~Articol()
{
    //dtor
}

std::string Articol::getTitlu() {
    return titlu;
}

void Articol::setTitlu(std::string t) {
    titlu = t;
}

int Articol::getBucati() {
    return bucati;
}

void Articol::setBucati(int b) {
   bucati = b;
}

std::string Articol::getAll()
{
    return titlu;
}
