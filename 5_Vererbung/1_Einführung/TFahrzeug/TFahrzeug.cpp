#include <iostream>
using namespace std;

#include "TFahrzeug.h"

// Basisklasse
// Default-Konstruktor
TFahrzeug::TFahrzeug()
{
  this->iAnzahlRaeder = 4;
}

// Konstruktor mit Parameter für Anzahl der Räder
TFahrzeug::TFahrzeug(int iAnzahlRaeder)
{
  this->iAnzahlRaeder = iAnzahlRaeder;
}

// Zugriffsmethoden
int TFahrzeug::getAnzahlRaeder()
{
  return iAnzahlRaeder;
}

void TFahrzeug::setAnzahlRaeder(int iAnzahlRaeder)
{
  this->iAnzahlRaeder = iAnzahlRaeder;
}


// Abgeleitete Klasse TPKW
// Default-Konstruktor
TPKW::TPKW()
{
  setAnzahlRaeder(4);  // das geht immer
  //iAnzahlRaeder = 4; // das geht nur bei protected-Vererbung
  
  bIstSportwagen = false;
}


TPKW::TPKW(bool bIstSportwagen, int iAnzahlRaeder) :
                TFahrzeug(iAnzahlRaeder)
                             
{
  this->bIstSportwagen = bIstSportwagen;
}


bool TPKW::getIstSportwagen()
{
  return bIstSportwagen;
}


void TPKW::setIstSportwagen(bool bIstSportwagen)
{
  this->bIstSportwagen = bIstSportwagen;
}



// Abgeleitete Klasse TLKW
// Default-Konstruktor
TLKW::TLKW()
{
  setAnzahlRaeder(4);  // das geht immer
  //iAnzahlRaeder = 4; // das geht immer nur bei protected-Vererbung
  iLadeflaecheInQuadratmetern = 50;
}


TLKW::TLKW(int iLadeflaecheInQuadratmetern, int iAnzahlRaeder):TFahrzeug(iAnzahlRaeder)
{
  this->iLadeflaecheInQuadratmetern = iLadeflaecheInQuadratmetern;
}


int TLKW::getLadeflaecheInQuadratmetern() const
{
  return iLadeflaecheInQuadratmetern;
}


void TLKW::setLadeflaecheInQuadratmetern(int iLadeflaecheInQuadratmetern)
{
  this->iLadeflaecheInQuadratmetern = iLadeflaecheInQuadratmetern;
}





