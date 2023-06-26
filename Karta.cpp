#include "Karta.h"
#include<iostream>
#include<map>

Karta::Karta()
{
	this->brojRezervisanihSedista = 0;
	this->rezervisanaSedista = NULL;
	this->pocetakProjekcije = Vreme();
	this->trajanjeProjekcije = Vreme();
	this->imeProjekcije = "";
	this->tipKarte = "";
	this->cena = 0;
}

Karta::Karta(int brRezSedista, Mesto* rezSedista, Vreme pocProj, Vreme trajanjeProj, string imeProj, string tipKarte)
{
	this->brojRezervisanihSedista = brRezSedista;
	this->rezervisanaSedista = rezSedista;
	this->pocetakProjekcije = pocProj;
	this->trajanjeProjekcije = trajanjeProj;
	this->imeProjekcije = imeProj;
	this->tipKarte = tipKarte;

	std::map<std::string, int> cenovnik;
	cenovnik["Regular"] = 300;
	cenovnik["Love"] = 500;
	cenovnik["VIP"] = 1000;

	if (tipKarte == "Regular")
		this->cena = this->brojRezervisanihSedista * cenovnik["Regular"];
	else if(tipKarte == "Love")
		this->cena = this->brojRezervisanihSedista * cenovnik["Love"];
	else 
		this->cena = this->brojRezervisanihSedista * cenovnik["VIP"];
}

void Karta::setBrojRezervisanihSedista(int brRezSedista)
{
	this->brojRezervisanihSedista = brRezSedista;
}

void Karta::setRezervisanaSedista(Mesto* rezSedista)
{
	this->rezervisanaSedista = rezSedista;
}

void Karta::setPocetakProjekcije(Vreme pocProj)
{
	this->pocetakProjekcije = pocProj;
}

void Karta::setTrajanjeProjekcije(Vreme trajanjeProj)
{
	this->trajanjeProjekcije = trajanjeProj;
}

void Karta::setImeProjekcije(string imeProj)
{
	this->imeProjekcije = imeProj;
}

void Karta::setTipKarte(string tipKarte)
{
	this->tipKarte = tipKarte;
}

void Karta::setCena(int cena)
{
	this->cena = cena;
}

int Karta::getCena()
{
	return this->cena;
}

int Karta::getBrojRezervisanihSedista()
{
	return this->brojRezervisanihSedista;
}

Mesto* Karta::getRezervisanaSedista()
{
	return this->rezervisanaSedista;
}

Vreme Karta::getPocetakProjekcije()
{
	return this->pocetakProjekcije;
}

Vreme Karta::getTrajanjeProjekcije()
{
	return this->trajanjeProjekcije;
}

string Karta::getImeProjekcije()
{
	return this->imeProjekcije;
}

string Karta::getTipKarte()
{
	return this->tipKarte;
}

Karta Karta::kreirajKartu()
{
	string imeProjekcije, tipKarte;
	int izborTipKarte, brRezSedista = 0;
	Mesto* rezSedista = NULL;
	std::cout << "\nUnesite ime projekcije : ";
	cin.ignore();
	getline(cin,imeProjekcije);
	do {
		std::cout << "Unesite tip sedista (1. Regular, 2. Ljubavna sedista, 3. VIP) : ";
		std::cin >> izborTipKarte;
		if (izborTipKarte < 1 || izborTipKarte > 3)
			std::cout << "Pogresan izbor, pokusajte ponovo!"<<std::endl;
	} while (izborTipKarte < 1 || izborTipKarte > 3);
	switch (izborTipKarte) {
		case 1: {
			tipKarte = "Regular";
			break;
		}case 2: {
			tipKarte = "Ljubavna sedista";
			break;
		}
		case 3: {
			tipKarte = "VIP";
			break;
		}
		default:
			std::cout << "Neocekivana greska pri odredjivanju tipa karte.";
			exit(1);
	}
	
	Vreme pocProj = Vreme::unosVremenaPocetka();
	
	Vreme trajanjeProj = Vreme::unosVremenaTrajanja();

	do {
		std::cout << "Unesite broj sedista koje zelite da rezervisete : ";
		std::cin >> brRezSedista;
		if (brRezSedista <= 0)
			std::cout << "Broj rezervisanih sedista mora biti veci od 0";
	} while (brRezSedista <= 0);
	
	char zeljeniRed;
	int zeljenoSediste;

	do {
		std::cout << "Unesite zeljeni red(A-H) : ";
		std::cin >> zeljeniRed;
		std::cout << "Unesite zeljenoSediste(1-15) : ";
		std::cin >> zeljenoSediste;
		if (zeljenoSediste <= 0 || zeljenoSediste > 15) {
			std::cout << "Sedista moraju biti izmedju 1 i 15!";
		}
		if (zeljeniRed < 'A' || zeljeniRed >'H') {
			std::cout << "\nRed mora biti izmedju A i H!\n\n";
		}
	} while (zeljenoSediste <= 0 || zeljenoSediste > 15 || zeljeniRed < 'A' || zeljeniRed >'H');

	rezSedista = Mesto::popuniSedista(brRezSedista, zeljeniRed, zeljenoSediste);
	
	return Karta(brRezSedista, rezSedista, pocProj, trajanjeProj, imeProjekcije, tipKarte);
}
