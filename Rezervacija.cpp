#include "Rezervacija.h"
#include "Stek.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <queue>

Rezervacija::Rezervacija()
{
	this->brojRezervisanihSedista = 0;
	this->rezervisanaSedista = NULL;
	this->pocetakProjekcije = Vreme();
	this->trajanjeProjekcije = Vreme();
	this->imeProjekcije="";
	this->tipKarte="";
	this->cena = 0;
	this->podnosilac = "";
}

Rezervacija::Rezervacija(Karta k, std::string p)
{
	this->brojRezervisanihSedista = k.getBrojRezervisanihSedista();
	this->rezervisanaSedista = k.getRezervisanaSedista();
	this->pocetakProjekcije = k.getPocetakProjekcije();
	this->trajanjeProjekcije = k.getTrajanjeProjekcije();
	this->imeProjekcije = k.getImeProjekcije();
	this->tipKarte = k.getTipKarte();
	this->cena = k.getCena();
	this->podnosilac = p;
}

void Rezervacija::setPodnosilac(std::string p)
{
	this->podnosilac = p;
}

std::string Rezervacija::getPodnosilac()
{
	return this->podnosilac;
}

void Rezervacija::ispisiRezervaciju()
{
	std::cout << "\n--- Rezervacija ---" << std::endl;
	std::cout << "Podnosilac : " << this->podnosilac << std::endl;
	std::cout << "- Informacije o karti -" << std::endl;
	std::cout << "Ime projekcije : " << this->imeProjekcije << std::endl;
	std::cout << "Pocetak projekcije : "; this->pocetakProjekcije.ispisiVreme();
	std::cout << std::endl;
	std::cout << "Trajanje projekcije : "; this->trajanjeProjekcije.ispisiVreme();
	std::cout << std::endl;
	std::cout << "Broj rezervisanih sedista : " << this->brojRezervisanihSedista << std::endl;
	std::cout << "Cena : " << this->cena <<" rsd" << std::endl;
	std::cout << "Rezervisana sedista : ";
	Mesto::ispisiSedista(this->rezervisanaSedista, this->brojRezervisanihSedista);
	std::cout << std::endl;
	std::cout << "Tip karte : " << this->tipKarte << std::endl;
	std::cout << "Predvidjen kraj projekcije : ";
	(this->pocetakProjekcije + this->trajanjeProjekcije).ispisiVreme();
	std::cout << std::endl;
}

Rezervacija Rezervacija::kreirajRezervaciju()
{
	Karta k = Karta::kreirajKartu();

	string podnosilac;
	std::vector<std::string> splitovaniStringovi;
	cin.ignore();
	do {
		std::cout << "Unesite ime i prezime podnosioca rezervacije : ";
		
		std::getline(std::cin, podnosilac);

		// splitovanje ulaznog stringa
		std::istringstream iss(podnosilac);
		std::string splitovaniString;
		while (std::getline(iss, splitovaniString, ' ')) {
			splitovaniStringovi.push_back(splitovaniString);
		}

		// provera da li imamo minimum dva strigna
		if (splitovaniStringovi.size() < 2) {
			std::cout << "\nMolimo Vas unesite ime i prezime!\n" << std::endl;
			splitovaniStringovi.clear(); // ciscenje tokena za sledecu iteraciju
		}
	} while (splitovaniStringovi.size() < 2);

	std::cout << "\nRezervacija uspesno kreirana!\n";
	return Rezervacija(k, podnosilac);
}

void Rezervacija::upisiSveRezervacijeUFajl(Rezervacija* ptr, int brEl)
{
	Rezervacija* sortiran = ptr;
	qsort(sortiran,
		brEl,
		sizeof(Rezervacija),
		Rezervacija::poredi);

	std::ofstream f("rezervacije.txt");

	if (f.is_open()) {
		for (int i = 0; i < brEl; i++) {
			// Upisivanje podataka u datoteku za svaku rezervaciju
			f << "***** Rezervacija " << i + 1 << " *****" << std::endl;
			f << "Podnosilac zahteva : " << (sortiran + i)->getPodnosilac() << std::endl;
			f << "- Informacije o karti -" << std::endl;
			f << "Ime projekcije : " << (sortiran + i)->imeProjekcije << std::endl;
			f << "Pocetak projekcije : "; 
			if ((sortiran+i)->getPocetakProjekcije().getMinut() < 10)
				f << (sortiran + i)->getPocetakProjekcije().getSat() << ":0" << (sortiran + i)->getPocetakProjekcije().getMinut();
			else
				f << (sortiran + i)->getPocetakProjekcije().getSat() << ":" << (sortiran + i)->getPocetakProjekcije().getMinut();
			f << std::endl;
			f << "Trajanje projekcije : "; 
			if ((sortiran + i)->getTrajanjeProjekcije().getMinut() < 10)
				f << (sortiran + i)->getTrajanjeProjekcije().getSat() << ":0" << (sortiran + i)->getTrajanjeProjekcije().getMinut();
			else
				f << (sortiran + i)->getTrajanjeProjekcije().getSat() << ":" << (sortiran + i)->getTrajanjeProjekcije().getMinut();
			f << std::endl;
			f << "Broj rezervisanih sedista : " << (sortiran + i)->brojRezervisanihSedista;
			f << std::endl;
			f << "Cena : " << (sortiran+i)->getCena() <<" rsd"<< std::endl;
			f << "Tip karte : " << (sortiran + i)->tipKarte << std::endl;
			f << "Predvidjen kraj projekcije : ";
			Vreme kraj = (sortiran + i)->getPocetakProjekcije() + (sortiran + i)->getTrajanjeProjekcije();
			if (kraj.getMinut() < 10)
				f << kraj.getSat() << ":0" << kraj.getMinut();
			else
				f << kraj.getSat() << ":" << kraj.getMinut();

			f << "\n----------------------------------------------------------\n";
		}

		f.close();
		std::cout << "\nRezervacije su uspesno upisane u datoteku rezervacije.txt." << std::endl;
	}
	else {
		std::cout << "\nGreska pri otvaranju datoteke 'rezervacija.txt'." << std::endl;
	}

}

void Rezervacija::ispisiSveRezervacijeNaEkran(Rezervacija* ptr, int brEl)
{
	std::cout << "\nDa li zelite ispis u rastucem ili opadajucem poretku po vremenu pocetka projekcije?\n";
	std::cout << "1. Rastuci, 2. Opadajuci : ";
	int opcija;
	do {
		std::cin >> opcija;
		if (opcija < 1 || opcija > 2)
			std::cout << "Unesite 1 ili 2!";
	} while (opcija < 1 || opcija > 2);

	Rezervacija* sortiran = ptr;
	qsort(sortiran,
		brEl,
		sizeof(Rezervacija),
		Rezervacija::poredi);

	Rezervacija temp;
	//RED - QUEUE
	if (opcija == 1) {
		std::queue<Rezervacija> red;
		//ubacivanje u red
		for (int i = 0; i < brEl; i++)
			red.push(*(sortiran + i));

		//ispis reda
		while (!red.empty()){
			temp = red.front();
			red.pop();
			temp.ispisiRezervaciju();
		}
	}
	//STEK
	else {
		Stek<Rezervacija> stek(brEl);
		//ubacivanje u stek
		for (int i = 0; i < brEl; i++)
			stek.Stavi(*(sortiran + i));

		//ispis steka
		while (stek.Uzmi(temp))
			temp.ispisiRezervaciju();

	}
}

int Rezervacija::poredi(const void* a, const void* b)
{
	return static_cast<int>((*(Rezervacija*)a).getPocetakProjekcije().getSat()*60+(*(Rezervacija*)a).getPocetakProjekcije().getMinut()
		- (*(Rezervacija*)b).getPocetakProjekcije().getSat() * 60 + (*(Rezervacija*)b).getPocetakProjekcije().getMinut());

}
