// Alexander Kaiser, AD22
// Abgabe: Umsetzung eines Klassendiagramms

//Klassen für Geometrie

class CAnzeige;

class CPunkt{

private:
    double x;
    double y;

public:
    CPunkt();
    CPunkt(double x, double y);
    double getX();
    void setX(double);
    double getY();
    void setY(double);
};

class CLinie{

private:
    CPunkt P1;
    CPunkt P2;
    CAnzeige* Anzeige;

public:
    CLinie(CPunkt P1, CPunkt P2);
    CPunkt getP1();
    void setP1(CPunkt);
    CPunkt getP2();
    void setP2(CPunkt);
    void RufeAnzeige();
};

class CRechteck{

private:
    CPunkt P1;
    CPunkt P2;
    CPunkt P3;
    CPunkt P4;
    CAnzeige* Anzeige;

public:
    CRechteck(CPunkt P1, CPunkt P2, CPunkt P3, CPunkt P4);
    CPunkt getP1();
    void setP1(CPunkt);
    CPunkt getP2();
    void setP2(CPunkt);
    CPunkt getP3();
    void setP3(CPunkt);
    CPunkt getP4();
    void setP4(CPunkt);
    void RufeAnzeige();
};

class CKreis{

private:
    CPunkt P;
    double Radius;
    CAnzeige* Anzeige;

public:
    CKreis(CPunkt P, double Radius);
    CPunkt getP();
    void setP(CPunkt);
    double getRadius();
    void setRadius(double);
    void RufeAnzeige();
};

class CAnzeige{

private:
    double flaecheKreis;
    double flaecheRechteck;
    double laengeLinie;

public:
    CAnzeige();
    void Flaeche(CKreis kreis);
    void Flaeche(CRechteck rechteck);
    void Laenge(CLinie linie);
};

