//Klasse TBruch

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

   //Konstruktor f�r Double-Werte
   CBruch(double d);

   //Funktion zum k�rzen
   void kuerze();

   void getBruch();

   CBruch operator+(CBruch Bruch);
   CBruch operator-(CBruch Bruch);
   CBruch operator*(CBruch Bruch);
   CBruch operator/(CBruch Bruch);
};
