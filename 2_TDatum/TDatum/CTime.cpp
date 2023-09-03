#include <iostream>
#include <iomanip>
#include <ctime>
#include <stdlib.h>
#include "datum.h"

//TDatum von Alexander Kaiser, ITU2

using namespace std;


//Funktion, die 2 Datums miteinander vergleicht und dafür die überladenen Operatoren benutzt
void compare(TDatum datum1, TDatum datum2)
{
    if(datum1 == datum2)
    {
        cout << "Das erste und das zweite Datum sind gleich" <<endl << endl;
    }
    else if (datum1 < datum2)
    {
        cout << "Das erste Datum ist kleiner als das zweite Datum" <<endl << endl;
    }
    else if (datum1 > datum2)
    {
        cout << "Das erste Datum ist groesser als das zweite Datum" << endl << endl;
    }
}



int main()
{
    cout << "\033[1;32m" << "TDatum von Alexander Kaiser" << "\033[0m" << endl << endl;
    //Ausgabe heutiges Datum
    TDatum heute;
    heute.setDatum();
    cout << endl << "Heutiges Datum ueber Funktion: ";
    heute.getDatum();

    //Datum wird mit Default-Konstruktor erzeugt
    TDatum datum1;
    cout << endl << "Erstes Datum: ";
    datum1.getDatum();

    //Datum wird  über Konstruktor erzeugt:
    TDatum datum2(28, 2, 1913);
    cout << endl << "Zweites Datum: ";
    datum2.getDatum();

    //Datum über Methode:
    TDatum datum3;
    datum3.setDatum(1, 9, 2001);
    cout << endl << "Drittes Datum: ";
    datum3.getDatum();

    compare(datum2, datum3);

    //ein ungültiges Datum wird gesetzt:
    TDatum datum4(30, 2, 1875);
    cout << endl << "Viertes Datum: ";
    datum4.getDatum();

    cout << endl;
    system("pause");
    return 0;
}




