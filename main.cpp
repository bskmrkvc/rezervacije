#include<iostream>
#include"Rezervacija.h";

using namespace std;

#define MAX 1000
int brojKreiranihRezervacija = 0;
int brojRezervacija;
int izbor = 0;
Rezervacija* r;

int unosBrojaRezervacija() {
	int brojRezervacija;
	do {
		std::cout << "Koliko zelite rezervacija da napravite? : ";
		std::cin >> brojRezervacija;
		if (brojRezervacija<0 || brojRezervacija>MAX)
			std::cout << "Nedozvoljen broj rezervacija!\n";
	} while (brojRezervacija<0 || brojRezervacija > MAX);
	return brojRezervacija;
}

void proveraDaLiJeBrojRezervacija0(int brojRezervacija) {
	if (brojRezervacija == 0) {
		std::cout << "Broj rezervacija je 0, dovidjenja!";
	}
}

void glavniInterfejs() {
	r = new Rezervacija[brojRezervacija];

	while (true) {

			do {
				std::cout << "\nSta zelite da uradite?\n1. Kreiraj rezervaciju\n2. Upisi rezervacije u fajl\n3. Ispisi rezervacije na ekran\n0. Izlazak iz programa : ";
				std::cin >> izbor;
				fflush(stdin);
				if (izbor < 0 || izbor > 3)
					std::cout << "Greska, unesite validan izbor!\n";
			} while (izbor < 0 || izbor > 3);

			switch (izbor) {
				case 1: {
					if (brojKreiranihRezervacija >= brojRezervacija)
						std::cout << "\nNe mozete uneti vise rezervacija!\n";
					else
						*(r + (brojKreiranihRezervacija++)) = Rezervacija::kreirajRezervaciju();
					break;
				}
				case 2: {
					if (brojKreiranihRezervacija == 0) {
						std::cout << "\nNe mozete pristupiti ovoj opciji dok ne kreirate rezervaciju!\n";
						continue;
					}
					Rezervacija::upisiSveRezervacijeUFajl(r, brojKreiranihRezervacija);
					break;
				}
				case 3: {
					if (brojKreiranihRezervacija == 0) {
						std::cout << "\nNe mozete pristupiti ovoj opciji dok ne kreirate rezervaciju!\n";
						continue;
					}
					Rezervacija::ispisiSveRezervacijeNaEkran(r, brojKreiranihRezervacija);
					break;
				}
				case 0: {
					std::cout << "\nZelimo vam prijatan dan!\n";
					system("pause");
					exit(0);
				}
			}

		}
	
}

int main() {
	brojRezervacija = unosBrojaRezervacija();
	proveraDaLiJeBrojRezervacija0(brojRezervacija);

	glavniInterfejs();

	std::cout << "Kraj programa!\n";
	system("pause");
	return 0;
}