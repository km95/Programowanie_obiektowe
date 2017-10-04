#pragma once
#include "Przedmiot.h"
class Zbroja :public Przedmiot
{
	int pancerz;
public:
	int getPancerz(){ return pancerz; }
	Zbroja(string, string, int, int, int, int);
};

