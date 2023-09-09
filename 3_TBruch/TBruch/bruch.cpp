#include "bruch.h"

using namespace std;


//CBruch::CBruch();

CBruch::CBruch(long z, long n)
{

    zaehler = z;
    nenner = n;
}

CBruch::CBruch(double d)
{

    zaehler = d;
    nenner = 1;

    while(zaehler != (int)zaehler)
    {

        zaehler *= 10;
        nenner *= 10;
    }



}
