#include "Audio.h"
#include "Articol.h"
#include<string>

Audio::Audio(std::string tit, int buc, double dur):Articol(tit, buc)
{
    durata = dur;
}

Audio::~Audio()
{
    //dtor
}


void Audio::setDurata(double d) {
    durata = d;
}

