
class TDatum
{
private:
    //Attribute
    int iTag;
    int iMonat;
    int iJahr;
public:
    //Konstruktor mit 3 Werten
    TDatum(int t, int m, int j);

    //Default-Konstruktor
    TDatum(void);

    //Methoden
    int getTag();
    void setTag(int);
    int getMonat();
    void setMonat(int);
    int getJahr();
    void setJahr(int );

    void setDatum(void);
    void setDatum(int iTag, int iMonat, int iJahr);
    void getDatum(void);

    bool isEqual(TDatum Datum);
    bool isLess(TDatum Datum);
    bool isMore(TDatum Datum);
};
