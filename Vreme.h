#pragma once
class Vreme
{
private:
	int sat, minut;
public:
	Vreme();
	Vreme(int s, int m);
	void setSat(int s);
	void setMinut(int m);
	int getSat();
	int getMinut();
	Vreme operator+(const Vreme& other) const;
	static Vreme unosVremenaPocetka();
	static Vreme unosVremenaTrajanja();
	void ispisiVreme();
};

