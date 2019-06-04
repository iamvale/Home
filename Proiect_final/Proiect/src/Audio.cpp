#include "Audio.h"
#include "Articol.h"
#include<string>

Audio::Audio(std::string tit, int bucEx, int bucDisp, double dur):Articol(tit, bucEx, bucDisp)
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

