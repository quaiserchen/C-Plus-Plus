#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <string>

using namespace std;

// Funktionen
bool CheckPassword(string str) {
  // Länge überprüfen
  if (str.length() < 8) {
    cout << "Passwort muss mindestens 8 Zeichen enthalten !!!\n";
  }

  // Weitere Kriterien überprüfen
  int upper = 0;
  int lower = 0;
  int digit = 0;
  int special = 0;

  // Eingabe zeichenweise durchlaufen
  for (int i=0; i<str.length(); i++) {
    // Grossbuchstaben zählen
    if (isupper(str[i]))
      upper++;
    // Kleinbuchstaben zählen
    if (islower(str[i]))
      lower++;
    // Ziffern zählen
    if (isdigit(str[i]))
      digit++;
    // Sonderzeichen zählen
    if (!isalnum(str[i]))
      special++;
  }
  
  // Kriterien überprüfen
  if (upper == 0 || lower == 0 || digit == 0 || special == 0) {
    // Fehlermeldung
    if (upper == 0)
      printf("Passwort muss mindestens 1 Grossbuchstaben enthalten !!!\n");
    if (lower == 0)
      printf("Passwort muss mindestens 1 Kleinbuchstaben enthalten !!!\n");
    if (digit == 0)
      printf("Passwort muss mindestens 1 Ziffer enthalten !!!\n");
    if (special == 0)
      printf("Passwort muss mindestens 1 Sonderzeichen enthalten !!!\n");
    return false;
  }
	return true;
}


int main(int argc, char* argv[])
{
  // Stringvariable deklarieren und initialisieren
  string strEingabe("");

  // Passwort einlesen
  cout<<"Passwort eingeben: ";
  cin>>strEingabe;
  
  // Passwort überprüfen
	if (CheckPassword(strEingabe))
	  cout << "Passwort ok";

  return 0;
}



