#pragma once
#include "Przedmiot.h"
class Tarcza :public Przedmiot
{
	int pancerz;
public:
	int getPancerz(){ return pancerz; }
	Tarcza(string, string, int, int, int, int);
};

