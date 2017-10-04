#pragma once
#include "Postac.h"
class Barbazynca :public Postac
{
public:
	Barbazynca();
	Barbazynca(string);
	~Barbazynca();
	void wypisz_staty();
	void przyjmij_obrazenia(double, Przedmiot**);
	void atak(Postac &, Przedmiot**);
	int Pancerz(Przedmiot ** E);
	int sredni_atak(Przedmiot ** E);
};

