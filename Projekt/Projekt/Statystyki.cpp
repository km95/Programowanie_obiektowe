#include "Statystyki.h"


Statystyki::Statystyki(double h, int s, int z)
{
	HP = h;
	Sila = s;
	Zrecznosc = z;
}
Statystyki::Statystyki()
{
	HP = 1;
	Sila = 1;
	Zrecznosc = 1;
}

Statystyki::~Statystyki()
{
}
//**********************************************
double Statystyki::getHP()
{
	return HP;
}
//**********************************************
int Statystyki::getSila()
{
	return Sila;
}
//**********************************************
int Statystyki::getZrecznosc()
{
	return Zrecznosc;
}
//***********************************************
void Statystyki::setHP(double h)
{
	HP = h;
}
//**********************************************
void Statystyki::setSila(int s)
{
	Sila = s;
}
//**********************************************
void Statystyki::setZrecznosc(int z)
{
	Zrecznosc = z;
}
//**********************************************
int Statystyki::getlevel()
{
	return level;
}