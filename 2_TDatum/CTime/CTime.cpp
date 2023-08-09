#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>

using namespace std;

int main()
{
  int iTag = 0;
  int iMonat = 0;
  int iJahr = 0;
  int iStunde = 0;
  int iMinute = 0;
  int iSekunde = 0;

  struct tm *zeit; // Zeiger auf Struktur vom Typ tm deklarieren
  time_t sec;      // Variable vom Datentyp time_t (long) deklarieren

  time(&sec);               // Aktuelle Systemzeit in Sekunden ermitteln
  zeit = localtime(&sec);   // Aktuelle Systemzeit in Struktur tm konvertieren

  iTag = zeit->tm_mday;       // Tag extrahieren
  iMonat = zeit->tm_mon+1;    // Monatextrahieren
  iJahr = zeit->tm_year+1900; // Jahr extrahieren
  iStunde = zeit->tm_hour;    // Stunde extrahieren
  iMinute = zeit->tm_min;     // Minute extrahieren
  iSekunde = zeit->tm_sec;    // Sekunde extrahieren

  // Aktuelles Datum + Uhrzeit ausgeben
  cout << setw(2)<< setfill('0') << right << iTag << '.';
  cout << setw(2)<< setfill('0') << right << iMonat << '.';
  cout << setw(4)<< setfill('0') << right << iJahr<< endl;
  cout << setw(2)<< setfill('0') << right << iStunde << ':';
  cout << setw(2)<< setfill('0') << right << iMinute << ':';
  cout << setw(2)<< setfill('0') << right<< iSekunde<< endl;
  system("pause");
  return 0;
}
