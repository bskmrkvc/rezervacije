#pragma once
class Mesto
{
private:
	char red;
	int sediste;
public:
	Mesto();
	Mesto(char r, int s);
	void setRed(char r);
	void setSediste(int s);
	char getRed();
	int getSediste();
	static Mesto* popuniSedista(int n, char zeljeniRed, int zeljenoSediste);
	void ispisiSediste();
	static void ispisiSedista(Mesto* sedista, int brojSedista);
};

