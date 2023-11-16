/* Hauptprogramm CBruch von Alexander Kaiser, AD22 */
/* Anmerkung: */
/* Ich hatte noch versucht, die unten stehenden Funktionen "pruefeEingabe()" und "wandleEingabeUm()" */
/* mit in die Methoden zu packen, aber dann hat gar nichts mehr funktioniert */

#include <iostream>
#include "bruch.h"
#include <regex>
#include <string>

using namespace std;

regex patternBruch("\\d*/\\d*");
regex patternDouble("\\d*\\.\\d*");
regex patternLongInt("\\d*");

void zeigeNotitzZettelAn()
{
//Umwandlung von double
    cout << endl << "===== Umwandlung von double-Zahlen =====" << endl;
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

/* Überprüft einen String auf gültige Muster (X/X, XX.XX, XX) */
bool pruefeString(string e)
{
    if (regex_match(e, patternBruch) || regex_match(e, patternDouble) || regex_match(e, patternLongInt))
    {
        return true;
    }
    return false;
}

/* Wandelt einen String in einen Bruch um */
CBruch wandleStringUm(string e)
{
    /* Format (X/X) */
    if (regex_match(e, patternBruch))
    {
        size_t positionVomBruchStrich = e.find('/');
        long int z, n;
        if(positionVomBruchStrich != string::npos)
        {
            z = stol(e.substr(0, positionVomBruchStrich));
            n = stol(e.substr(positionVomBruchStrich + 1));
            CBruch stringZuBruch(z, n);
            return stringZuBruch ;
        }
    }
    /* Format XX.XX */
    else if(regex_match(e, patternDouble))
    {
        double stringZuDouble = stold(e);
        CBruch stringZuBruch(stringZuDouble);
        return stringZuBruch;
    }
    /* Format XX */
    else if(regex_match(e, patternLongInt))
    {
        double stringZuLongInt = stol(e);
        CBruch stringZuBruch(stringZuLongInt);
        return stringZuBruch;
    }
    /* Falls trotz Prüfung der String nicht umgewandelt werden kann */
    CBruch fehlerBeimUmwandeln(1, 1);
    return fehlerBeimUmwandeln;
}

bool pruefeEingabe(string e)
{
    cout << "+-------------------------------------------+" << endl;
    cout << "|     CBruch von Alexander Kaiser, AD22     |" << endl;
    cout << "+-------------------------------------------+" << endl << endl;

    string wertstringZuBruch, wert1string, wert2string;
    bool wertstringZuBruchOk = false, string1ok = false, string2ok = false;
    char bruchrechner;
    char funktionsauswahl;

    /* Menü zur Funktionsauswahl */
    cout << "Bitte Auswaehlen:" << endl << "1. Ausgabe der Notiz aus der Aufgabenstellung" << endl << "2. Umwandeln von String zu Bruch" << endl << "3. Brueche eingeben und Rechenoperation ausfuehren" << endl << "4. Programm  Beenden" << endl << endl << "Auswahl: ";
    cin >> funktionsauswahl;

    switch(funktionsauswahl)
    {
    case '1':
        /* gibt den Notizzettel aus der Aufgabenstellung aus */
        zeigeNotitzZettelAn();
        break;
    case '2':
        //Der Nutzer gibt einen String ein und dieser wird nach der überprüfung des Formats in einen Bruch umgewandelt
        while(wertstringZuBruchOk == false)
        {
            cout << "Bitte geben sie einen Wert ein(eine ganze Zahl, eine Kommazahl oder Bruch 'X/X'): ";
            cin >> wertstringZuBruch;
            wertstringZuBruchOk = pruefeString(wertstringZuBruch);
            if(wertstringZuBruchOk == false)
            {
                cout << endl << "UNGUELTIGE EINGABE!!!" << endl;
            }
            else
            {
                cout << endl << "Der eingegebene erste Wert lautet: " << wertstringZuBruch;
                CBruch wertstringZuBruchUmgewandelt = wandleStringUm(wertstringZuBruch);
                wertstringZuBruchUmgewandelt.kuerze();
                cout << " Umgewandelt in einen Bruch: " << wertstringZuBruchUmgewandelt.getBruch() << endl << endl;
            }
        }
        break;
    case '3':
        /* Der Nutzer gibt nacheinander 2 Werte als String ein, die einzeln auf ihr Format überprüft werden.und kann dann durch ein Menü */
        /* die beiden Brüche addieren, subtrahieren, multiplizieren oder dividieren. Das Ergebnis wird als (ggf. gekürzter) Bruch ausgegeben und der Nutzer kann */
        /* weitere Rechenoperationen durchführen, bis das Menü verlassen wird  */
        cout << "===== Bruchrechner =====" << endl;
        /* Eingabe und Überprüfung vom ersten Wert */
        while(string1ok == false)
        {
            cout << "Bitte geben sie den ersten Wert ein(eine ganze Zahl, eine Kommazahl oder Bruch 'X/X'): ";
            cin >> wert1string;
            string1ok = pruefeString(wert1string);
            if(string1ok == false)
            {
                cout << endl << "UNGUELTIGE EINGABE!!!" << endl;
            }
            else
            {
                cout << endl << "Der eingegebene erste Wert lautet: " << wert1string << endl;
            }
        }
        /* Eingabe und Überprüfung vom zweiten Wert */
        while(string2ok == false)
        {
            cout << "Bitte geben sie den zweiten Wert ein(eine ganze Zahl, eine Kommazahl oder Bruch 'X/X'): ";
            cin >> wert2string;
            string2ok = pruefeString(wert2string);
            if(string2ok == false)
            {
                cout << endl << "UNGUELTIGE EINGABE!!!" << endl;
            }
            else
            {
                cout << endl << "Der eingegebene zweite Wert lautet: " << wert2string << endl;
            }
        }
        /* Nutzer kann verschiedene Rechenoperationen mit den eingegebene Werten durchführen, bis Menü verlassen wird */
        while(true)
        {
            cout << "Bitte die gewuenschte Rechenoperation auswählen (+, -, *, /) oder 'E'/'e' um das Menue zu verlassen: ";
            cin >> bruchrechner;

            CBruch wert1Bruch = wandleStringUm(wert1string);
            CBruch wert2Bruch = wandleStringUm(wert2string);
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
        break;
    case '4':
        return 0;
    default:
        cout << endl << "Ungueltige Eingabe!!!" << endl;
        break;
    }
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