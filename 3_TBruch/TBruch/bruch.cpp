//Methoden für TBruch, Alexander Kaiser, AD22
#include "bruch.h"
#include <iostream>
#include <string>

using namespace std;

//Defaltkonstruktor
CBruch::CBruch()
{
    zaehler = 0;
    nenner = 0;
}
// Konstruktor mit 2 long int Variablen
CBruch::CBruch(long z, long n)
{
    zaehler = z;
    nenner = n;
}
// wandelt double-Zahl in Bruch um
CBruch::CBruch(double d)
{
    nenner = 1;

    while(d != (int)d)
    {
        d *= 10;
        nenner *= 10;
    }

    zaehler = d;

    // kürzt direkt den Bruch
    int teiler = ggt(zaehler, nenner);
    zaehler /= teiler;
    nenner /= teiler;
}
// zum Kürzen von Brüchen
void CBruch::kuerze()
{
    int teiler = ggt(this->zaehler, this->nenner);
    this->zaehler = this->zaehler/teiler;
    this->nenner = this->nenner/teiler;
}

int CBruch::ggt(long x, long y)
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
// gibt String des Bruches für die Ausgabe zurück
std::string CBruch::getBruch()
{
    std::string bruchString = std::to_string(zaehler) + "/" + std::to_string(nenner);
    if(nenner == 1)
    {
        bruchString += ", entspricht " + std::to_string(zaehler);
    }
    return bruchString;
}
// CBruch + CBruch
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
// Cbruch - CBruch
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
// CBruch * CBruch
CBruch CBruch::operator*(CBruch Bruch)
{
    int tempZaehler = this->zaehler * Bruch.zaehler;
    int tempNenner = this->nenner * Bruch.nenner;
    CBruch tempBruch(tempZaehler, tempNenner);
    tempBruch.kuerze();
    return tempBruch;
}
// CBruch / CBruch
CBruch CBruch::operator/(CBruch Bruch)
{
    int tempZaehler = this->zaehler * Bruch.nenner;
    int tempNenner = this->nenner * Bruch.zaehler;
    CBruch tempBruch(tempZaehler, tempNenner);
    tempBruch.kuerze();
    return tempBruch;
}
// CBruch + double
CBruch CBruch::operator+(double d)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = *this + tempDoubleZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// double + CBruch
CBruch operator+(double d, const CBruch &bruch)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = tempDoubleZuBruch + bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch * double
CBruch CBruch::operator-(double d)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = *this - tempDoubleZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// double - CBruch
CBruch operator-(double d, const CBruch &bruch)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = tempDoubleZuBruch - bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch * double
CBruch CBruch::operator*(double d)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = *this * tempDoubleZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// double * CBruch
CBruch operator*(double d, const CBruch &bruch)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = tempDoubleZuBruch * bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch / double
CBruch CBruch::operator/(double d)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = *this / tempDoubleZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// double / CBruch
CBruch operator/(double d, const CBruch &bruch)
{
    CBruch tempDoubleZuBruch(d);
    CBruch ergebnis = tempDoubleZuBruch / bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch + long
CBruch CBruch::operator+(long l)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = *this + tempLongZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// long + CBruch
CBruch operator+(long l, const CBruch &bruch)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = tempLongZuBruch + bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch - long
CBruch CBruch::operator-(long l)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = *this - tempLongZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// long - CBruch
CBruch operator-(long l, const CBruch &bruch)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = tempLongZuBruch - bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch * long
CBruch CBruch::operator*(long l)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = *this * tempLongZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// long * CBruch
CBruch operator*(long l, const CBruch &bruch)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = tempLongZuBruch * bruch;
    ergebnis.kuerze();
    return ergebnis;
}
// CBruch / long
CBruch CBruch::operator/(long l)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = *this / tempLongZuBruch;
    ergebnis.kuerze();
    return ergebnis;
}
// long / CBruch
CBruch operator/(long l, const CBruch &bruch)
{
    CBruch tempLongZuBruch(l, 1);
    CBruch ergebnis = tempLongZuBruch / bruch;
    ergebnis.kuerze();
    return ergebnis;
}


