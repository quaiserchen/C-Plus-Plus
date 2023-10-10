#include <iostream>
#include "bruch.h"
#include <regex>
#include <string>

using namespace std;

regex patternBruch("\\d*/\\d*");
regex patternDouble("\\d*\\.\\d*");
regex patternLongInt("\\d*");

void neueZeile()
{
    cout << endl;
}

bool pruefeEingabe(string e)
{
    if (regex_match(e, patternBruch) || regex_match(e, patternDouble) || regex_match(e, patternLongInt)){
        return true;
    }
}

void zeigeNotitzZettelAn(){
//Umwandlung von double
    cout << "===== Umwandlung von double-Zahlen =====" << endl;
    CBruch ausDoubleUmgewandelt(1.25);
    cout << "Bruch aus 1.25: " << ausDoubleUmgewandelt.getBruch() << endl << endl;

//Grundrechenarten
    cout << "===== Grundrechenarten =====" << endl;
    CBruch A(1,2);
    CBruch B(3,4);
    CBruch C;

    cout << "Bruch A: " << A.getBruch() << endl;
    cout << "Bruch B: " << B.getBruch() << endl << endl;

    C = A + B;
    cout << "C = A + B -> C  = " << C.getBruch() << endl;
    C = B - A;
    cout << "C = B - A -> C  = " << C.getBruch() << endl;
    C = A * B;
    cout << "C = A * B -> C  = " << C.getBruch() << endl;
    C = B / A;
    cout << "C = B / A -> C  = " << C.getBruch() << endl << endl;

//Überladen
    cout << "===== Ueberladen =====" << endl;
    C = A + 1.5;
    cout << "C = A + 1.5 -> C  = " << C.getBruch() << endl;
    C = 3.75 - B;
    cout << "C = 3.75 + B -> C  = " << C.getBruch() << endl;
    C = 10L + B;
    cout << "C = 10(long) + B -> C  = " << C.getBruch() << endl;
}

CBruch wandleEingabeUm(string e)
{
    if (regex_match(e, patternBruch))
    {
        size_t positionVomBruchStrich = e.find('/');
        long int z, n;
        if(positionVomBruchStrich != string::npos){
            z = stol(e.substr(0, positionVomBruchStrich));
            n = stol(e.substr(positionVomBruchStrich + 1));
            CBruch stringZuBruch(z, n);
            return stringZuBruch ;
        }
    }
    else if(regex_match(e, patternDouble))
    {
        double stringZuDouble = stold(e);
        CBruch stringZuBruch(stringZuDouble);
        return stringZuBruch;

    }
    else if(regex_match(e, patternLongInt))
    {
        double stringZuLongInt = stol(e);
        CBruch stringZuBruch(stringZuLongInt);
        return stringZuBruch;

    }
}



int main()
{
    cout << "+-------------------------------------------+" << endl;
    cout << "|     CBruch von Alexander Kaiser, AD22     |" << endl;
    cout << "+-------------------------------------------+" << endl << endl;

    char funktionsauswahl;
    cout << "Bitte Auswaehlen:" << endl << "1. Ausgabe der Notiz aus der Aufgabenstellung" << endl << "2. Umwandeln von String zu Bruch" << endl << "3. Brueche eingeben und Rechenoperation ausfuehren" << endl << "4. Programm  Beenden" << endl << endl << "Auswahl: ";
    cin >> funktionsauswahl;

    switch(funktionsauswahl){
    case '1':
        break;
    case '2':
        break;
    case '3':
        break;
    case '4':
        return 0;
    default:
        cout << endl << "ungueltige Eingabe!!!" << endl;
        break;
    }


    //zeigeNotitzZettelAn();

    //Nutzereingabe
    cout << "===== Nutzereingabe =====" << endl;
    string wert1string, wert2string;
    bool string1ok = false, string2ok = false;
    char bruchrechner;

while(string1ok == false){
    cout << "Bitte geben sie den ersten Wert ein(eine ganze Zahl, eine Kommazahl oder Bruch 'X/X'): ";
    cin >> wert1string;
    string1ok = pruefeEingabe(wert1string);
    if(string1ok == false){
        cout << endl << "UNGUELTIGE EINGABE!!!" << endl;
    } else {
        cout << endl << "Der eingegebene erste Wert lautet: " << wert1string << endl;
    }
}

while(string2ok == false){
    cout << "Bitte geben sie den zweiten Wert ein(eine ganze Zahl, eine Kommazahl oder Bruch 'X/X'): ";
    cin >> wert2string;
    string2ok = pruefeEingabe(wert2string);
    if(string2ok == false){
        cout << endl << "UNGUELTIGE EINGABE!!!" << endl;
    } else {
        cout << endl << "Der eingegebene zweite Wert lautet: " << wert2string << endl;
    }
}

    while(true)
    {
        cout << "Bitte die gewuenschte Rechenoperation auswählen (+, -, *, /) oder 'E'/'e' um das Menue zu verlassen: ";
        cin >> bruchrechner;

        CBruch wert1Bruch = wandleEingabeUm(wert1string);
        CBruch wert2Bruch = wandleEingabeUm(wert2string);
        CBruch ergebnisBruch;

        switch(bruchrechner)
        {
        case '+':
            ergebnisBruch = wert1Bruch + wert2Bruch;
            ergebnisBruch.kuerze();
            cout << wert1string << " + " << wert2string << " = " << ergebnisBruch.getBruch() << endl;
            break;
        case '-':
            ergebnisBruch = wert1Bruch - wert2Bruch;
            ergebnisBruch.kuerze();
            cout << wert1string << " - " << wert2string << " = " << ergebnisBruch.getBruch() << endl;
            break;
        case '*':
            ergebnisBruch = wert1Bruch * wert2Bruch;
            ergebnisBruch.kuerze();
            cout << wert1string << " * " << wert2string << " = " << ergebnisBruch.getBruch() << endl;
            break;
        case '/':
            ergebnisBruch = wert1Bruch / wert2Bruch;
            ergebnisBruch.kuerze();
            cout << wert1string << " / " << wert2string << " = " << ergebnisBruch.getBruch() << endl;
            break;
        case 'e':
        case 'E':
            return 0;
        default:
            cout << endl << "Ungueltig!!";
            break;
        }
    }




}