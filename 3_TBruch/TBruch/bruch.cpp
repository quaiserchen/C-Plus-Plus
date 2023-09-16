#include "bruch.h"
#include <iostream>

using namespace std;


//CBruch::CBruch();

CBruch::CBruch(long z, long n)
{

    zaehler = z;
    nenner = n;
}

CBruch::CBruch(double d) //nochmal machen!
{

    cout << "Double = " << d << endl;
    zaehler = d;
    nenner = 1;

    cout << static_cast<int>(zaehler) << endl;

    while(zaehler != static_cast<int>(zaehler))
    {
        cout << "d = " << d << " nenner = " << nenner << endl;
        d *= 10;
        nenner *= 10;
    }

    zaehler = d;
}

void CBruch::kuerze()
{

    long x = zaehler;
    long y = nenner;
    int c;
    if ( x < 0 ) x = -x;
    if ( y < 0 ) y = -y;
    while ( y != 0 )
    {
        c = x % y;
        x = y;
        y = c;
    }
    this->zaehler = this->zaehler/x;
    this->nenner = this->nenner/x;
}

int ggt(long x, long y)
{
    int c;
    if ( x < 0 ) x = -x;
    if ( y < 0 ) y = -y;
    while ( y != 0 )
    {
        c = x % y;
        x = y;
        y = c;
    }
    return x;
}

void CBruch::getBruch()
{

    cout << zaehler << "/" << nenner ;
}

CBruch CBruch::operator+(CBruch Bruch)
{
    int tempNenner = this->nenner * Bruch.nenner;
    int tempErweiterungszahl = tempNenner / this->nenner;
    int tempZaehler1 = this->zaehler * tempErweiterungszahl;
    tempErweiterungszahl = tempNenner/ Bruch.nenner;
    int tempZaehler2 = Bruch.zaehler * tempErweiterungszahl;
    int neuerZaehler = tempZaehler1 + tempZaehler2;
    CBruch tempBruch(neuerZaehler, tempNenner);
    tempBruch.kuerze();
    return tempBruch;
}

CBruch CBruch::operator-(CBruch Bruch)
{
    int tempNenner = this->nenner * Bruch.nenner;
    int tempErweiterungszahl = tempNenner / this->nenner;
    int tempZaehler1 = this->zaehler * tempErweiterungszahl;
    tempErweiterungszahl = tempNenner/ Bruch.nenner;
    int tempZaehler2 = Bruch.zaehler * tempErweiterungszahl;
    int neuerZaehler = tempZaehler1 - tempZaehler2;
    CBruch tempBruch(neuerZaehler, tempNenner);
    tempBruch.kuerze();
    return tempBruch;
}

CBruch CBruch::operator*(CBruch Bruch)
{
    int tempZaehler = this->zaehler * Bruch.zaehler;
    int tempNenner = this->nenner * Bruch.nenner;
    CBruch tempBruch(tempZaehler, tempNenner);
    tempBruch.kuerze();
    return tempBruch;
}

CBruch CBruch::operator/(CBruch Bruch)
{
    int tempZaehler = this->zaehler * Bruch.nenner;
    int tempNenner = this->nenner * Bruch.zaehler;
    CBruch tempBruch(tempZaehler, tempNenner);
    tempBruch.kuerze();
    return tempBruch;
}
