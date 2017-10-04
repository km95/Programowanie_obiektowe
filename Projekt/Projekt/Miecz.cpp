#include "Miecz.h"


Miecz::Miecz(string n, string t,int l, int c, int i, int min, int max)
{
	
	nazwa = n;
	typ = t;
	wymaganylevel = l;
	cena = c;
	id = i;
	obrazenia_min = min;
	obrazenia_max = max;
}
int Miecz::getSrednieobrazenia()
{
	int srednia = (obrazenia_min + obrazenia_max) / 2;
	return srednia;
}

