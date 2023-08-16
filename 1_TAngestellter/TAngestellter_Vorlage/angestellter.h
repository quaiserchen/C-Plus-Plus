// Definition der Klasse TAngestellter
class TAngestellter
{
  private:
    // Attribute
    char *strName;
    char *strVorname;
    double dGehalt;
  public:
    //Konstruktor
    TAngestellter(const char *name="", const char *vorname="", double gehalt=0.0);

    //Dekonstruktor
    ~TAngestellter();

    // Methoden
    const char *getName();
    void setName(const char *name);
    const char *getVorname();
    void setVorname(const char *vorname);
    double getGehalt();
    void setGehalt(double);
};
