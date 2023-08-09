#include <iostream>
#include <string>

using namespace std;

// Funktionen
float calc(int iZahl1, int iZahl2) {
  // Zahl1 kleiner 0
  if (iZahl1 < 0) return -1;

  // Zahl2 kleiner 0
  if (iZahl2 < 0) return -2;

  // Zahl2 gleich 0
  if (iZahl2 == 0) return -3;

  // Alles ok.
  return (float) iZahl1 / (float) iZahl2;
}


int main(int argc, char* argv[]) {
  // Deklaration und Initialisierung von Variablen
  int iZahl1=0;
  int iZahl2=0;
  float fErgebnis=0.0;

  // Eingabe
  cout << "Geben Sie zwei positive ganze Zahlen ein!" << endl;
  cout << "Zahl1: ";
  cin >> iZahl1;
  cout << "Zahl2: ";
  cin >> iZahl2;

  // Berechnung
  fErgebnis = calc(iZahl1, iZahl2);

  // Ausnahmebehandlung
  if (fErgebnis == -1)
	  cout << "Zahl1 kleiner 0 !" << endl;

  if (fErgebnis == -2)
	  cout << "Zahl2 kleiner 0 !" << endl;

  if (fErgebnis == -3)
	  cout << "Division durch 0 !" << endl;

  // Alles ok -> Ausgabe
  if (fErgebnis > 0)
	  cout << iZahl1 << " / " << iZahl2 << " = " << fErgebnis << endl;

  system("pause");
  return 0;
}

