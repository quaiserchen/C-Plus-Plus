// Alexander Kaiser, AD22
// Abgabe: Umsetzung eines Klassendiagramms

#define _USE_MATH_DEFINES

#include "geometrie.h"
#include <cmath>
#include <iostream>
#include <iomanip>

using namespace std;

//Methoden für CPunkt
CPunkt::CPunkt()
{
    this->x = 0;
    this->y = 0;
}

CPunkt::CPunkt(double x, double y)
{
    this->x = x;
    this->y = y;
}

double CPunkt::getX()
{
    return this->x;
}

void CPunkt::setX(double x)
{
   this->x = x;
}

double CPunkt::getY()
{
    return this->y;
}

void CPunkt::setY(double y)
{
   this->y = y;
}

//Methoden für CLinie
CLinie::CLinie(CPunkt P1, CPunkt P2)
{
    this->P1 = P1;
    this->P2 = P2;
}

CPunkt CLinie::getP1()
{
    return this->P1;
}

void CLinie::setP1(CPunkt P1)
{
   this->P1 = P1;
}

CPunkt CLinie::getP2()
{
    return this->P2;
}

void CLinie::setP2(CPunkt P2)
{
   this->P2 = P2;
}

void CLinie::RufeAnzeige()
{
    CAnzeige laengeLinie;
    laengeLinie.Laenge(*this);
}



//Methoden für Rechteck
CRechteck::CRechteck(CPunkt P1, CPunkt P2, CPunkt P3, CPunkt P4)
{
    this->P1 = P1;
    this->P2 = P2;
    this->P3 = P3;
    this->P4 = P4;
}

CPunkt CRechteck::getP1()
{
    return this->P1;
}

void CRechteck::setP1(CPunkt P1)
{
   this->P1 = P1;
}

CPunkt CRechteck::getP2()
{
    return this->P2;
}

void CRechteck::setP2(CPunkt P2)
{
   this->P2 = P2;
}

CPunkt CRechteck::getP3()
{
    return this->P3;
}

void CRechteck::setP3(CPunkt P3)
{
   this->P3 = P3;
}

CPunkt CRechteck::getP4()
{
    return this->P4;
}

void CRechteck::setP4(CPunkt P4)
{
   this->P4 = P4;
}

void CRechteck::RufeAnzeige()
{
    CAnzeige flaecheRechteck;
    flaecheRechteck.Flaeche(*this);
}

//Methoden für Kreis
CKreis::CKreis(CPunkt P, double Radius)
{
    this->P = P;
    this->Radius = Radius;
}
CPunkt CKreis::getP()
{
    return this->P;
}

void CKreis::setP(CPunkt P)
{
   this->P = P;
}

double CKreis::getRadius()
{
    return this->Radius;
}

void CKreis::setRadius(double Radius)
{
   this->Radius = Radius;
}

void CKreis::RufeAnzeige()
{
    CAnzeige flaecheKreis;
    flaecheKreis.Flaeche(*this);
}

//Methoden für Anzeige
CAnzeige::CAnzeige()
{
    this->flaecheKreis = 0;
    this->flaecheRechteck = 0;
    this->laengeLinie = 0;
}

void CAnzeige::Flaeche(CKreis kreis)
{
    double flaecheKreis = M_PI * pow(2, kreis.getRadius());
    cout << "Flaeche Kreis: Pi * " << kreis.getRadius() << " = " << fixed << setprecision(2) << flaecheKreis << " (LE hoch 2)" << endl;

}

void CAnzeige::Flaeche(CRechteck rechteck)
{
    CPunkt P1= rechteck.getP1();
    CPunkt P3= rechteck.getP3();
    double xAbstandR = P3.getX() - P1.getX();
    double yAbstandR = P3.getY() - P1.getY();
    double flaecheRechteck = xAbstandR * yAbstandR;
    cout << "Flaeche Rechteck: " << xAbstandR << " * " << yAbstandR  << " = " << fixed << setprecision(2) << flaecheRechteck << " (LE hoch 2)" << endl;
}

void CAnzeige::Laenge(CLinie linie)
{
    CPunkt P1 = linie.getP1();
    CPunkt P2 = linie.getP2();
    double P3x = P2.getX()-P1.getX();
    double P3y = P2.getY()-P1.getY();
    // bei der Quadratberechnung wollte ich eigentlich pow() benutzen, aber pow(2, 5) hat immer einen
    // falschen Wert ausgegeben (32), deswegen die etwas unschönere Variante
    double laenge = sqrt((P3x * P3x) + (P3y * P3y));
    cout << "Laenge Linie: sqrt(" << P3x << " hoch 2  + " << P3y  << " hoch 2) = " << fixed << setprecision(2) << laenge << " (LE)" << endl;
}


