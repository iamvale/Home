#include "Revista.h"
#include "Articol.h"

Revista::Revista(std::string tit, int bucEx, int bucDisp, std::string tip):Articol(tit, bucEx, bucDisp)
{
    tipRev = tip;
}

Revista::~Revista()
{
    //dtor
}
void Revista::setTip(std::string tp) {
    tipRev = tp;
}
