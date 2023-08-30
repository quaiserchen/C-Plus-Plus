#include "datum.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Konstruktor-Implementierung
TDatum::TDatum(int tag, int monat, int jahr)
{
    if(tag<32 && tag>0)
    {
        iTag = tag;
    }
    if(monat<13 && monat > 0)
    {
        iMonat = monat;
    }
    if(jahr<9999 && jahr>0)
    {
        iJahr = jahr;
    }

}

//Implementierung der Methoden für Tag, Monat und Jahr
TDatum::TDatum(void)
{
    iTag = 1;
    iMonat = 1;
    iJahr = 1970;
}

int TDatum::getTag(void)
{
    return iTag;
}

void TDatum::setTag(int tag)
{
    iTag = tag;
}
int TDatum::getMonat(void)
{
    return iMonat;
}

void TDatum::setMonat(int monat)
{
    iMonat = monat;
}
int TDatum::getJahr(void)
{
    return iJahr;
}

void TDatum::setJahr(int jahr)
{
    iJahr = jahr;
}

//Zusätzliche Funktionen
void TDatum::setDatum(void)
{
    int iTag = 0;
    int iMonat = 0;
    int iJahr = 0;

    struct tm *zeit; // Zeiger auf Struktur vom Typ tm deklarieren
    time_t sec;      // Variable vom Datentyp time_t (long) deklarieren

    time(&sec);               // Aktuelle Systemzeit in Sekunden ermitteln
    zeit = localtime(&sec);   // Aktuelle Systemzeit in Struktur tm konvertieren

    this -> iTag = zeit->tm_mday;       // Tag extrahieren
    this -> iMonat = zeit->tm_mon+1;    // Monatextrahieren
    this -> iJahr = zeit->tm_year+1900; // Jahr extrahieren
}

void TDatum::setDatum(int tag, int monat, int jahr)
{
    if(tag<32 && tag>0)
    {
        iTag = tag;
    }
    if(monat<13 && monat > 0)
    {
        iMonat = monat;
    }
    if(jahr<9999 && jahr>0)
    {
        iJahr = jahr;
    }
}

void TDatum::getDatum()
{
    cout << setw(2)<< setfill('0') << right << iTag << '.';
    cout << setw(2)<< setfill('0') << right << iMonat << '.';
    cout << setw(4)<< setfill('0') << right << iJahr<< endl;
}

bool TDatum::isEqual(TDatum Datum)
{
    if (this->getTag() == Datum.getTag() && this->getMonat() == Datum.getMonat() && this->getJahr() == Datum.getJahr())
    {
        return true;
    }
}

bool TDatum::isLess(TDatum Datum)
{
    bool isLess = false;
    if (this->getJahr() < Datum.getJahr())
    {
        isLess = true;
    }
    else if (this->getMonat() < Datum.getMonat() && this->getJahr() == Datum.getJahr())
    {
        isLess = true;
    }
    else if(this->getTag() < Datum.getTag() && this->getMonat() == Datum.getMonat() && this->getJahr() == Datum.getJahr())
    {
        true;
    }
    return isLess;
}

bool TDatum::isMore(TDatum Datum)
{
    bool isMore = false;
    if (this->getJahr() > Datum.getJahr())
    {
        isMore = true;
    }
    else if (this->getMonat() > Datum.getMonat() && this->getJahr() == Datum.getJahr())
    {
        isMore = true;
    }
    else if(this->getTag() > Datum.getTag() && this->getMonat() == Datum.getMonat() && this->getJahr() == Datum.getJahr())
    {
        isMore = true;
    }
    return isMore;
}
