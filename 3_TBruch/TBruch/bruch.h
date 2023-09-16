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

   //Konstruktor für Double-Werte
   CBruch(double d);

   //Funktion zum kürzen
   void kuerze();

   void getBruch();

   CBruch operator+(CBruch Bruch);
   CBruch operator-(CBruch Bruch);
   CBruch operator*(CBruch Bruch);
   CBruch operator/(CBruch Bruch);
};
