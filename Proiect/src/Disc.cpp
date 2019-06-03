#include "Disc.h"
#include "Articol.h"

Disc::Disc(std::string tit, int bucEx, int bucDisp, std::string prog):Articol(tit, bucEx, bucDisp)
{
    program = prog;
}

Disc::~Disc()
{
    //dtor
}
void Disc::setProg(std::string pr) {
    program = pr;
}
