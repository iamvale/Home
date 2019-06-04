#include "Articol.h"
#include<stdlib.h>
#include<string>

Articol::Articol()
{
    //ctor
}

Articol::Articol(std::string tit, int bucEx, int bucDisp):titlu{tit},bucExist{bucEx}, bucDisponibile{bucDisp}
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

int Articol::getBucExist() {
    return bucExist;
}

void Articol::setBucExist(int bucEx) {
   bucExist = bucEx;
}

int Articol::getBucDisp() {
    return bucDisponibile;
}

void Articol::setBucDisp(int bucDisp) {
   bucDisponibile = bucDisp;
}

//bool Articol::operator>(Articol& sortAlfa)
//{
//    return getTitlu() > sortAlfa.getTitlu();
//}
std::string Articol::getAll()
{
    return titlu;
}

