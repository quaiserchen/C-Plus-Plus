#ifndef TFAHRZEUG_H_
#define TFAHRZEUG_H_

// Basisklasse
class TFahrzeug
{
  private:
  int iAnzahlRaeder;
  public:
	TFahrzeug();    // Default-Konstruktor
	TFahrzeug(int); // Konstruktor mit Parameter für Anzahl der Räder
	int getAnzahlRaeder();
	void setAnzahlRaeder(int iAnzahlRaeder);
};


// Abgeleitete Klasse
class TPKW : private TFahrzeug
{
  private:
	bool bIstSportwagen;
  public:
	TPKW();          // Default-Konstruktor
	TPKW(bool, int); // Konstruktor mit Parametern für Anzahl der Räder und IstSportwagen
	bool getIstSportwagen();
	void setIstSportwagen(bool bIstSportwagen);
};


// Abgeleitete Klasse
class TLKW : public TFahrzeug
{
  private:
	int iLadeflaecheInQuadratmetern;
  public:
	TLKW();         // Default-Konstruktor
	TLKW(int, int); // Konstruktor mit Parameter für Anzahl der Räder und LadeflaecheInQuadratmetern
	int getLadeflaecheInQuadratmetern() const;
	void setLadeflaecheInQuadratmetern(int iLadeflaecheInQuadratmetern);
};


#endif /* TFAHRZEUG_H_ */
