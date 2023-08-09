// Umsetzung einer 1:1 Assoziation ("hat-Beziehung")
// Klassensprecher - Schulklasse
class TKlassensprecher
{
  private:
  	TSchulklasse *pSchulklasse; // Zeiger
  public:
  	TKlassensprecher();
}


class TSchulklasse
{
  private:
  	TKlassensprecher *pKlassensprecher; // Zeiger
  public:
  	TSchulklasse();
}


// Umsetzung einer 1:* Assoziation ("hat-Beziehung")
// Buch - Ausleiher
class TBuch
{
  private:
  	TAusleiher *pAusleiher; // Zeiger
  public:
  	TBuch();
}


class TAusleiher
{
  private:
  	TBuch *pBuchliste; // z.B. Verkettete Liste
  public:
  	TAusleiher();
}


// Umsetzung einer 1:1 Aggregation (schwache "besteht aus-Beziehung")
// Notebook - Festplatte
class TNotebook
{
  private:
  	// ...
  public:
  	TNotebook();
}


class TFestplatte
{
  private:
  	// ...
  public:
  	TFestplatte();
}

// Umsetzung einer 1:* Aggregation (schwache "besteht aus-Beziehung")
// Firma - Mitarbeiter
class TFirma
{
  private:
  	// ...
  public:
  	TFirma();
}


class TMitarbeiter
{
  private:
  	// ...
  public:
  	TMitarbeiter();
}


// Umsetzung einer 1:* Komposition (starke "besteht aus Beziehung")
// Bankfiliale - Konto
class TBankfiliale
{
  private:
  	TKonto Konten[Max]; // Statisches Array
  	TListe Konten;      // Dynamische Liste
  public:
  	TBankfiliale();
}


class TKonto
{
  private:
  	// ...
  public:
  	TKonto();
}






