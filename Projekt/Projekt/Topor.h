#pragma once
#include "Przedmiot.h"
class Topor :public Przedmiot
{
	int obrazenia_min;
	int obrazenia_max;
public:
	int getMin(){ return obrazenia_min; }
	int getMax(){ return obrazenia_max; }
	int getSrednieobrazenia();
	Topor(string, string, int, int, int, int, int);
};

