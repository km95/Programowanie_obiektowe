#pragma once
#include "Przedmiot.h"
class Miecz_dwureczny :public Przedmiot
{
	int obrazenia_min;
	int obrazenia_max;
public:
	int getMin(){ return obrazenia_min; }
	int getMax(){ return obrazenia_max; }
	int getSrednieobrazenia();
	Miecz_dwureczny(string, string, int, int, int, int, int);
};

