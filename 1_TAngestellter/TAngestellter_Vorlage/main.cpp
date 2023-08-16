#include <iostream>
#include <stdio.h>
#include "angestellter.h"

using namespace std;

int main(int argc, char* argv[])
{
  // Objekt der Klasse TAngestellter erzeugen (statisch)
  TAngestellter alex("Kaiser", "Alex", 450000);

  cout << "Name: " << alex.getVorname() << " " << alex.getName() << ", Gehalt: " << alex.getGehalt() <<endl;

  TAngestellter dieter;
  dieter.setName("Denker");
  dieter.setVorname("Dieter");
  dieter.setGehalt(5);

  //test test

  cout << "Name: " << dieter.getVorname() << " " << dieter.getName() << ", Gehalt: " << dieter.getGehalt() <<endl;

  // Warten auf Tastendruck
  getchar();
  return 0;
}







