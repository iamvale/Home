#include "BecReglabil.h"
#include <iostream>

using namespace std;

BecReglabil::BecReglabil(unsigned short _putereMaxima, unsigned short _putereCurenta)
{
   if(_putereCurenta == 0)
        _aprins = false;
    else
        _aprins = true;
}

BecReglabil::~BecReglabil()
{
    //dtor
}

void BecReglabil::Aprinde()
{
    _aprins = true;
    _putereCurenta = _putereMaxima;
}

void BecReglabil::Stinge()
{
    _aprins = false;
    _putereCurenta = 0;

}

void BecReglabil::MaresteLumina(unsigned short _mareste)
{

    _putereCurenta += _mareste;

    if(_putereCurenta > _putereMaxima)
    {
        _putereCurenta = _putereMaxima;

    }
    _aprins = true;




}
void BecReglabil::ReduceLumina(unsigned short _reduce)
{

    _putereCurenta -= _reduce;

    if(_putereCurenta <0)
    {
         _putereCurenta = 0;
         // _aprins = false;

    }

    if(_putereCurenta == 0)
    {
         _aprins = false;
   }



}

void BecReglabil::StareBec()
{
    if(_aprins == true)
        cout << "Becul e aprins " << endl;
    //else
    if(_aprins == false)
        cout << "Becul e stins " << endl;

}


