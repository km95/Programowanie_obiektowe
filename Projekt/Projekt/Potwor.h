#pragma once
#include "Postac.h"
class Potwor :public Postac
{
	float dodatkowy_atak;
	int level;
	enum { Goblin, Pies, Wilk, Smok, Leszy, Gryf, Kraken, Salamandra, Lisz, Duch, Zombie, Szkielet, Utopiec };
public:
	Potwor();
	Potwor(int);
	//Potwor(int, int);
	~Potwor();
	void przyjmij_obrazenia(double, Przedmiot**);
	void wypisz_staty();
	void atak(Postac &, Przedmiot**);
	int Pancerz(Przedmiot ** E);
	int sredni_atak(Przedmiot ** E);

};

