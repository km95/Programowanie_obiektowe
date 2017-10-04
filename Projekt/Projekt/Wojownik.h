#pragma once
#include "Postac.h"
class Wojownik :public Postac
{
public:
	Wojownik();
	Wojownik(string);
	~Wojownik();
	void wypisz_staty();
	void przyjmij_obrazenia(double, Przedmiot**);
	void atak(Postac &, Przedmiot**);
	int Pancerz(Przedmiot ** E);
	int sredni_atak(Przedmiot ** E);
};

