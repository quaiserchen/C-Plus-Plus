#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "datum.h"

//TDatum von Alexander Kaiser, ITU2

using namespace std;

int compare(TDatum datum1, TDatum datum2)
{
    if(datum1.isEqual(datum2))
    {
        cout << "Datum1 und Datum2 sind gleich" <<endl;
    }
    else if (datum1.isLess(datum2))
    {
        cout << "Datum1 ist kleiner als Datum2" <<endl;
    }
    else if (datum1.isMore(datum2))
    {
        cout << "Datum1 ist groesser als Datum2" << endl;
    }
}

int main()
{
    /*Ausgabe Standartdatum
    TDatum standart;
    cout << "Defaultkonstruktor: ";
    standart.getDatum();

    //Ausgabe Datum Konstruktor mit Parametern
    int iTag = 2, iMonat = 12, iJahr = 2023;
    TDatum konstPara(iTag, iMonat, iJahr);
    cout << endl << "Konstruktor mit Parametern: ";
    konstPara.getDatum();

    //Ausgabe Datum über Getter-Methoden
    int iTagG = 2, iMonatG = 11, iJahrG = 1823;
    TDatum setterdatum;
    setterdatum.setTag(iTagG);
    setterdatum.setMonat(iMonatG);
    setterdatum.setJahr(iJahrG);
    cout << endl << "Datum ueber Getter-Methoden: ";
    setterdatum.getDatum();*/

    //Ausgabe heutiges Datum
    TDatum heute;
    heute.setDatum();
    cout << endl << "Heutiges Datum ueber Funktion: ";
    heute.getDatum();
    /*
        //Ausgabe Datum über Funktion gesetzt
        int iTagF = 12, iMonatF = 12, iJahrF = 2007;
        TDatum funktion;
        funktion.setDatum(iTagF, iMonatF, iJahrF);
        cout << endl << "Bestimmtes Datum ueber Funktion: ";
        funktion.getDatum(); */


    int iTag1 = 2, iMonat1 = 11, iJahr1 = 2023;
    TDatum datum1(iTag1, iMonat1, iJahr1);
    cout << endl << "Erstes Datum: ";
    datum1.getDatum();

    int iTag2 = 2, iMonat2 = 11, iJahr2 = 2023;
    TDatum datum2(iTag2, iMonat2, iJahr2);
    cout << endl << "Zweites Datum: ";
    datum2.getDatum();

    compare(datum1, datum2);

    cout << endl;
    //system("pause");
    return 0;
}




