#include "Mesto.h"
#include<iostream>
#include<string>
Mesto::Mesto()
{
	this->red = '0';
	this->sediste = 0;
}

Mesto::Mesto(char r, int s)
{
	this->red = r;
	this->sediste = s;
}

void Mesto::setRed(char r)
{
	this->red = r;
}

void Mesto::setSediste(int s)
{
	this->sediste = s;
}

char Mesto::getRed()
{
	return this->red;
}

int Mesto::getSediste()
{
	return this->sediste;
}

Mesto* Mesto::popuniSedista(int brojSedista, char zeljeniRed, int zeljenoSediste)
{
	Mesto *p = new Mesto[brojSedista];
	int pomerajRed=1;
	int sedisteNoviRed = 1;
	for (int i = 0; i < brojSedista; i++)
	{
		if (zeljeniRed + pomerajRed > 'H') {
			std::cout << "\n\nDostignut je maksimum sale!\n\n";
			return p;
		}
		if (zeljenoSediste + i > 15) {
			
			if (sedisteNoviRed > 15) {
				sedisteNoviRed = 1;
				pomerajRed++;
			}
			else {
				*(p + i) = Mesto(zeljeniRed + pomerajRed, (sedisteNoviRed++));
			}
		}
		else *(p+i) = Mesto(zeljeniRed, zeljenoSediste + i);
	}
	return p;
}

void Mesto::ispisiSediste()
{
	if (this->red == '0' || this->sediste == 0) return;
	std::cout << this->red << "-" << this->sediste;
}

void Mesto::ispisiSedista(Mesto* sedista, int brojSedista){

	for (int i = 0; i < brojSedista; i++)
	{
		if (i == brojSedista - 1) {
			(sedista + i)->ispisiSediste();
		}
		else {
			(sedista + i)->ispisiSediste();
			std::cout << ", ";
		}	
	}
}
