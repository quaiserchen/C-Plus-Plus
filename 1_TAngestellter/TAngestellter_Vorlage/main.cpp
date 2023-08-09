#include <iostream>
#include <stdio.h>
#include "angestellter.h"

using namespace std;

int main(int argc, char* argv[])
{
  // Objekt der Klasse TAngestellter erzeugen (statisch)
  TAngestellter hans;

  // Gehalt von hans setzen und wieder ausgeben mittels cout.
  hans.setGehalt(42000.00);
  cout << "Gehalt des Angestellten Hans: " << hans.getGehalt() << endl;
  
  // Das geht so nicht !!! dGehalt ist private
  //cout << "Gehalt des Angestellten Hans: " << hans.dGehalt << endl;

  // Warten auf Tastendruck
  getchar();
  return 0;
}






                        
