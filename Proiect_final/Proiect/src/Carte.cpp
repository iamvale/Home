#include "Carte.h"
#include "Articol.h"
#include<string>

Carte::Carte()
{

}

Carte::Carte(std::string tit, int bucEx, int bucDisp, std::string edit):Articol(tit, bucEx, bucDisp)
{
    editura = edit;

}

Carte::~Carte()
{
    //dtor
}


void Carte::setEditura(std::string e) {
    editura = e;
}

