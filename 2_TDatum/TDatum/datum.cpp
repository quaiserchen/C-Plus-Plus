#include "datum.h"
#include <ctime>
#include <stdlib.h>
#include <iostream>
#include <iomanip>

using namespace std;

//Konstruktor-Implementierung
TDatum::TDatum(int tag, int monat, int jahr)
{
    if (isDatumValid(tag, monat, jahr))
    {
        iTag = tag;
        iMonat = monat;
        iJahr = jahr;
    } else {
        cout << "-----------------------------------------------------------------------------" << endl;
        cout << "Das angegebene Datum ist ungueltig und wird deswegen auf den 1.1.1970 gesetzt" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        iTag = 1;
        iMonat = 1;
        iJahr = 1970;
    }
}

//Implementierung der Methoden für Tag, Monat und Jahr
TDatum::TDatum(void)
{
    iTag = 1;
    iMonat = 1;
    iJahr = 1970;
}

//Zusätzliche Funktionen
void TDatum::setDatum(void)
{

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
    if (isDatumValid(tag, monat, jahr))
    {
        iTag = tag;
        iMonat = monat;
        iJahr = jahr;
    } else {
        cout << endl << "-----------------------------------------------------------------------------" << endl;
        cout << "Das angegebene Datum ist ungueltig und wird deswegen auf den 1.1.1970 gesetzt" << endl;
        cout << "-----------------------------------------------------------------------------" << endl;
        iTag = 1;
        iMonat = 1;
        iJahr = 1970;
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
    if (this->iTag == Datum.iTag && this->iMonat == Datum.iMonat && this->iJahr == Datum.iJahr)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool TDatum::isLess(TDatum Datum)
{
    bool isLess = false;
    if (this->iJahr< Datum.iJahr)
    {
        isLess = true;
    }
    else if (this->iMonat < Datum.iMonat)
    {
        isLess = true;
    }
    else if(this->iTag < Datum.iTag)
    {
        isLess = true;
    }
    return isLess;
}

bool TDatum::isMore(TDatum Datum)
{
    bool isMore = false;
    if (this->iJahr > Datum.iJahr)
    {
        isMore = true;
    }
    else if (this->iMonat > Datum.iMonat)
    {
        isMore = true;
    }
    else if(this->iTag > Datum.iTag)
    {
        isMore = true;
    }
    return isMore;
}

bool TDatum::operator==(TDatum Datum)
{
    return this->isEqual(Datum);
}

bool TDatum::operator<(TDatum Datum)
{
    return this->isLess(Datum);
}

bool TDatum::operator>(TDatum Datum)
{
    return this->isMore(Datum);
}

bool TDatum::isDatumValid(int tag, int monat, int jahr)
{
    int t = tag;
    int m = monat;
    int j = jahr;
    bool sj = false;
    bool datumValid = false;

    //Bestimme, ob das Jahr ein Schaltjahr ist
    if(j % 400 == 0 || (j % 4 == 0 && j % 100 != 0))
    {
        sj = true;
    }

    //überprüfe das Datum abhängig davon, ob es in einem Schaltjahr liegt
    if (0 < m && m <= 12)
    {
        if ( m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 || m == 12)
        {
            if (0 < t && t <= 31)
            {
                datumValid = true;
            }
        }
        else if (m == 4 || m == 6 || m == 9 || m == 11)
        {
            if (0 < t && t <=30)
            {
                 datumValid = true;
            }
        }
        else if (m == 2)
        {
            switch(sj)
            {
            case false:
                if (0 < t && t <= 28)
                {
                     datumValid = true;
                }
                break;
            case true:
                if (0 < t && t <= 29)
                {
                     datumValid = true;

                }
            break;

            }
        }
    }
    return datumValid;
}
