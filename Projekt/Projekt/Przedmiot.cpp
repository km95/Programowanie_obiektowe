#include "Przedmiot.h"


Przedmiot::Przedmiot()
{

}
Przedmiot::Przedmiot(string n, string t, int c, int i)
{
	nazwa = n;
	typ = t;
	cena = c;
	id = i;
}
string Przedmiot::getnazwa()
{
	return nazwa;
}