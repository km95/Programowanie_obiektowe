#pragma once
#include "Statystyki.h"
class Przedmiot
{
protected:
	string nazwa;
	string typ;
	int wymaganylevel;
	int cena;
	int id;
public:
	Przedmiot();
	Przedmiot(string, string, int, int);
	string getnazwa();
	int getcena(){ return cena; }
	int getId(){ return id; }
	virtual int getSrednieobrazenia(){ return 0; }
	virtual int getMin(){ return 0; }
	virtual int getMax(){ return 0; }
	virtual int getPancerz(){ return 0; }

};

