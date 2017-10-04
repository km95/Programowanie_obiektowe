#pragma once
#include "All.h"
class Statystyki 
{
protected:
	int MaxHP;
	double HP;
	int MaxExp;
	int Exp;
	int level;
	int Sila;
	int Zrecznosc;
public:
	Statystyki();
	Statystyki(double, int, int);
	~Statystyki();
	int getMaxHP(){ return MaxHP; };
	double getHP();
	int getSila();
	int getZrecznosc();
	void setHP(double);
	void setSila(int);
	void setZrecznosc(int);

	int getlevel();
};

