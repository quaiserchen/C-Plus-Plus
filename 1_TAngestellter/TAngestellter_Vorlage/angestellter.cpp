#include "angestellter.h"
#include <cstring>

//Konstruktor-Implementierung
TAngestellter::TAngestellter(const char *name, const char *vorname, double gehalt)
{
    strName = new char[strlen(name) + 1];
    strVorname = new char[strlen(vorname) + 1];
    strcpy(strName, name);
    strcpy(strVorname, vorname);
    dGehalt = gehalt;
}

//Dekonstruktor-Implementierung
TAngestellter::~TAngestellter()
{
    delete[] strName;
    delete[] strVorname;
}

// Implementierung der Methoden für Name, Vorname und Gehalt
const char *TAngestellter::getName()
{
    return strName;
}

void TAngestellter::setName(const char *name)
{
    delete[] strName;
    strName = new char[strlen(name) + 1];
    strcpy(strName, name);
}

const char *TAngestellter::getVorname()
{
    return strVorname;
}

void TAngestellter::setVorname(const char *vorname)
{
    delete[] strVorname;
    strVorname = new char[strlen(vorname) + 1];
    strcpy(strVorname, vorname);
}

double TAngestellter::getGehalt(void)
{
  return dGehalt;
}

void TAngestellter::setGehalt(double dLohn)
{
  dGehalt = dLohn;
}
