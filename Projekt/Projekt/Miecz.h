#pragma once
#include "Przedmiot.h"
class Miecz :public Przedmiot
{
	int obrazenia_min;
	int obrazenia_max;
public:
	Miecz(string, string,int, int, int, int, int);
	int getMin(){ return obrazenia_min; }
	int getMax(){ return obrazenia_max; }
	int getSrednieobrazenia();
	~Miecz(){ cout << "Jestem sobie destruktorem miecza "; }
};

