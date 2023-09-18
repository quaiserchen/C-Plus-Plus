#include <iostream>
#include "bruch.h"

using namespace std;

void neueZeile(){
    cout << endl;
}

int main()
{
cout << "+-------------------------------------------+" << endl;
cout << "|     CBruch von Alexander Kaiser, AD22     |" << endl;
cout << "+-------------------------------------------+" << endl << endl;


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
