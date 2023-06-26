#pragma once
#include"Karta.h"
class Rezervacija : Karta
{
private:
	std::string podnosilac;
public:
	Rezervacija();
	Rezervacija(Karta k, std::string p);
	void setPodnosilac(std::string p);
	std::string getPodnosilac();
	void ispisiRezervaciju();
	static Rezervacija kreirajRezervaciju();
	static void upisiSveRezervacijeUFajl(Rezervacija *ptr, int brEl);
	static void ispisiSveRezervacijeNaEkran(Rezervacija* ptr, int brEl);
	static int poredi(const void* a, const void* b);
};

