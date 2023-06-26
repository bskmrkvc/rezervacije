#include "Vreme.h"
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include <sstream>
Vreme::Vreme()
{
	this->sat = 0;
	this->minut = 0;
}

Vreme::Vreme(int s, int m)
{
	this->sat = s;
	this->minut = m;
}

void Vreme::setSat(int s)
{
	this->sat = s;
}

void Vreme::setMinut(int m)
{

	this->minut = m;
}

int Vreme::getSat()
{
	return this->sat;
}

int Vreme::getMinut()
{
	return this->minut;
}

Vreme Vreme::operator+(const Vreme& other) const 
{
	Vreme rezultat;
	rezultat.minut = minut + other.minut;
	rezultat.sat = sat + other.sat;

	// Ako su minuti veci od 59, prebacujemo jedan sat
	// Ako je sat veci od 23, umanjujemo za 24
	if (rezultat.minut >= 60) {
		rezultat.sat++;
		rezultat.minut -= 60;
	}
	if (rezultat.sat >= 24) {
		rezultat.sat -= 24;
	}

	return rezultat;
	
}

Vreme Vreme::unosVremenaPocetka()
{
	int h=0, m=0;
	do {
		std::string vreme;
		std::vector<std::string> splitovanoVreme;
		std::cin.ignore();
		do {
			std::cout << "Unesite vreme pocetka projekcije u formatu HH:MM : ";

			std::getline(std::cin, vreme);

			// splitovanje ulaznog stringa
			std::istringstream iss(vreme);
			std::string splitovaniString;
			while (std::getline(iss, splitovaniString, ':')) {
				splitovanoVreme.push_back(splitovaniString);
			}

			// provera da li imamo minimum dva strigna
			if (splitovanoVreme.size() != 2) {
				std::cout << "\nMolimo Vas sate i minute u formatu HH:MM!\n" << std::endl;
				splitovanoVreme.clear(); // ciscenje tokena za sledecu iteraciju
			}
		} while (splitovanoVreme.size() != 2);

		h = stoi(splitovanoVreme[0]);
		m = stoi(splitovanoVreme[1]);

		if (h < 0 || h > 23 || m < 0 || m > 59)
			std::cout << "Greska u unosu vremena! Neispravan format.\n";
	} while (h < 0 || h > 23 || m < 0 || m > 59);

	return Vreme(h, m);
}

Vreme Vreme::unosVremenaTrajanja()
{
	int h = 0, m = 0;
	do {
		std::string vreme;
		std::vector<std::string> splitovanoVreme;
		//std::cin.ignore();
		do {
			std::cout << "Unesite vreme trajanja projekcije u formatu HH:MM : ";

			std::getline(std::cin, vreme);

			// splitovanje ulaznog stringa
			std::istringstream iss(vreme);
			std::string splitovaniString;
			while (std::getline(iss, splitovaniString, ':')) {
				splitovanoVreme.push_back(splitovaniString);
			}

			// provera da li imamo minimum dva strigna
			if (splitovanoVreme.size() != 2) {
				std::cout << "\nMolimo Vas sate i minute u formatu HH:MM!\n" << std::endl;
				splitovanoVreme.clear(); // ciscenje tokena za sledecu iteraciju
			}
		} while (splitovanoVreme.size() != 2);

		h = stoi(splitovanoVreme[0]);
		m = stoi(splitovanoVreme[1]);

		if (h < 0 || h > 23 || m < 0 || m > 59)
			std::cout << "Greska u unosu vremena! Neispravan format.\n";
	} while (h < 0 || h > 23 || m < 0 || m > 59);

	return Vreme(h, m);
}


void Vreme::ispisiVreme()
{
	if (minut < 10)
		std::cout << this->sat << ":0" << this->minut;
	else
		std::cout << this->sat << ":" << this->minut;
}

