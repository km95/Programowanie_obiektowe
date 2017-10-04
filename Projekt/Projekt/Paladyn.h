#pragma once
#include "Postac.h"
class Paladyn :public Postac
{
public:
	Paladyn();
	Paladyn(string);
	~Paladyn();
	void wypisz_staty();
	void przyjmij_obrazenia(double, Przedmiot**);
	void atak(Postac &, Przedmiot**);
	int Pancerz(Przedmiot ** E);
	int sredni_atak(Przedmiot ** E);
};

