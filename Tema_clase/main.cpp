#include <iostream>
#include "BecReglabil.h"

using namespace std;

int main()
{
    BecReglabil bec75(75, 0);
    BecReglabil bec100(100, 0);
    bec75.StareBec();
    bec100.StareBec();
    bec75.Aprinde();
    bec100.Aprinde();
    bec75.StareBec();
    bec100.StareBec();
    bec75.Stinge();
    bec100.Stinge();
    bec75.StareBec();
    bec100.StareBec();
    bec75.MaresteLumina(90);
    bec100.MaresteLumina(90);
    bec75.StareBec();
    bec100.StareBec();
    bec75.ReduceLumina(75);
    bec100.ReduceLumina(75);
    bec75.StareBec();
    bec100.StareBec();


    cout << "Hello world!" << endl;
    return 0;
}
