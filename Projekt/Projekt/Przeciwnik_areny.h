#pragma once
#include "Postac.h"
class Przeciwnik_areny :public Postac
{
public:
	Przeciwnik_areny();
	Przeciwnik_areny(string , int , int , int , int , int  ,int  ,int , int );
	Przeciwnik_areny(string);
	~Przeciwnik_areny();
	void wypisz_staty();
	void przyjmij_obrazenia(double, Przedmiot**);
	void atak(Postac &, Przedmiot**);
	int Pancerz(Przedmiot ** E);
	int sredni_atak(Przedmiot ** E);

};

