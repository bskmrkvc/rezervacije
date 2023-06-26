#pragma once
template <class T>
class Stek
{
private:
	T* pstek;
	int velicina;
	int indeks;
	static const int MAX = 1000;
public:
	Stek(int = 16);
	~Stek() { delete[] pstek; }
	bool Stavi(const T&);
	bool Uzmi(T&);
	bool Prazan() const { return indeks == -1; }
	bool Pun() const { return indeks == velicina - 1; }
};
template <class T>
Stek<T>::Stek(int s)
{
	velicina = (s > 0 && s < MAX) ? s : 16;
	indeks = -1;
	pstek = new T[velicina];
}
template <class T>
bool Stek<T>::Stavi(const T& element)
{
	if (false == Pun())
	{
		pstek[++indeks] = element;
		return true;
	}
	return false;
}
template <class T>
bool Stek<T>::Uzmi(T& element)
{
	if (false == Prazan())
	{
		element = pstek[indeks--];
		return true;
	}
	return false;
}