#include "Carte.h"
#include "Articol.h"
#include<string>

Carte::Carte()
{

}

Carte::Carte(std::string tit, int buc, std::string edit):Articol(tit, buc)
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

