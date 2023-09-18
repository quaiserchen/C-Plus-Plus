//Klasse TBruch

#include <string>

class CBruch{

private:

    //Attribute
    long zaehler;

    long nenner;

public:

     //Default-Konstruktor
    CBruch(void);

    //Konstruktor mit 2 Werten
    CBruch(long z, long n);

   //Konstruktor für Double-Werte
   CBruch(double d);

   //Funktion zum kürzen
   void kuerze();

   // Funktion zur bestimmung des gemeinsamen Teilers
   int ggt(long z, long n);

   // Gibt den Bruch aus
   std::string getBruch();

   // zum Überladen der Operatoren, wenn mit zwei CBruch-Klassen gearbeited wird
   CBruch operator+(CBruch Bruch);
   CBruch operator-(CBruch Bruch);
   CBruch operator*(CBruch Bruch);
   CBruch operator/(CBruch Bruch);

   // überschreibt Operatoren für CBruch -> +-*/ -> double
   CBruch operator+(double d);
   CBruch operator-(double d);
   CBruch operator*(double d);
   CBruch operator/(double d);

   // überschreibt Operatoren für CBruch -> +-*/ -> long
   CBruch operator+(long l);
   CBruch operator-(long l);
   CBruch operator*(long l);
   CBruch operator/(long l);

};
    // überschreibt Operatoren für double -> +-*/ -> CBruch
    CBruch operator+(double d, const CBruch &bruch);
    CBruch operator-(double d, const CBruch &bruch);
    CBruch operator*(double d, const CBruch &bruch);
    CBruch operator/(double d, const CBruch &bruch);

// überschreibt Operatoren für double -> +-*/ -> CBruch
    CBruch operator+(long l, const CBruch &bruch);
    CBruch operator-(long l, const CBruch &bruch);
    CBruch operator*(long l, const CBruch &bruch);
    CBruch operator/(long l, const CBruch &bruch);
