#include <iostream>
#include <string>
//#include <stdexcept>

using namespace std;

// Eigene Fehlerklasse
class TError
{
  private:
    string Message;
  public:
    void SetMessage(string s){Message=s;};
    string GetMessage(){return Message;}
    TError(string s){Message=s;};
};

// Funktionen
float calc(int iZahl1, int iZahl2)
{
  // Zahl1 kleiner 0
  if (iZahl1 < 0)
	  throw (string)"Zahl1 kleiner 0";

  // Zahl2 kleiner 0
  if (iZahl2 < 0)
	  throw (string)"Zahl2 kleiner 0";

  // Zahl2 gleich 0
  if (iZahl2 == 0)
	  //throw (string)"Zahl2 gleich 0";
	  //throw 0;
	  throw TError("Division durch 0");
  // Alles ok.
  return (float) iZahl1 / (float) iZahl2;
}


int main(int argc, char* argv[])
{
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

  try
  {
    // Berechnung
    fErgebnis = calc(iZahl1, iZahl2);
    
    // Ausgabe
    cout << iZahl1 << " / " << iZahl2 << " = " << fErgebnis << endl;
  }

  // Ausnahmebehandlung  
  catch (string& s)
  {
	  cerr << s << endl;
  }
  
  catch (int i)
  {
	  cerr << i << endl;
  }
  
  catch (TError& e)
  {
	  cerr << e.GetMessage() << endl;
  }

  catch (...)
  {
	  cerr << "Unbekannter Fehler" << endl;
  }

  system("pause");
  return 0;
}

