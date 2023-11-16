// Alexander Kaiser, AD22
// Abgabe: Umsetzung eines Klassendiagramms

#define _USE_MATH_DEFINES

#include "geometrie.h"

int main()
{
    //Linie anlegen und Länge ausgeben
    CPunkt lp1(7, 1);
    CPunkt lp2(12, 5);
    CLinie linie(lp1, lp2);
    linie.RufeAnzeige();

    //Rechteck anlegen und Fläche ausgeben
    CPunkt rp1(4, 3);
    CPunkt rp2(6, 3);
    CPunkt rp3(6, 6);
    CPunkt rp4(4, 6);
    CRechteck rechteck(rp1, rp2, rp3, rp4);
    rechteck.RufeAnzeige();


    //Kreis anlegen und Fläche ausgeben
    CPunkt kp(8, 8);
    double kr = 2;
    CKreis kreis(kp, kr);
    kreis.RufeAnzeige();

}

