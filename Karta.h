#pragma once
#include <string>
#include "Vreme.h"
#include "Mesto.h"
#include <string>
using namespace std;
class Karta
{
protected:
	int brojRezervisanihSedista;
	Mesto* rezervisanaSedista;
	Vreme pocetakProjekcije;
	Vreme trajanjeProjekcije;
	string imeProjekcije;
	string tipKarte;
	int cena;
public:
	Karta();
	Karta(int brRezSedista, Mesto* rezSedista, Vreme pocProj, Vreme trajanjeProj, string imeProj, string tipKarte);
	void setBrojRezervisanihSedista(int brRezSedista);
	void setRezervisanaSedista(Mesto* rezSedista);
	void setPocetakProjekcije(Vreme pocProj);
	void setTrajanjeProjekcije(Vreme trajanjeProj);
	void setImeProjekcije(string imeProj);
	void setTipKarte(string tipKarte);
	void setCena(int cena);
	int getCena();
	int getBrojRezervisanihSedista();
	Mesto* getRezervisanaSedista();
	Vreme getPocetakProjekcije();
	Vreme getTrajanjeProjekcije();
	string getImeProjekcije();
	string getTipKarte();
	static Karta kreirajKartu();
};

