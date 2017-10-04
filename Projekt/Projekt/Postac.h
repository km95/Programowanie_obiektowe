#pragma once
#include "Statystyki.h"
#include "Przedmiot.h"

class Postac :public Statystyki
{
protected:
	string Klasa;
	double odpornosc;
	double skalowanie_sily;
	double skalowanie_zrecznosci;
	int Prawa_reka_id;
	int Lewa_reka_id;
	int Zbroja_id;
	int Kasa;
	int Punkty_statystyk;
	string nick;
	double obrazenia_otrzymane;
	int arena;
public:
	virtual void wypisz_staty() = 0;
	virtual void atak(Postac &, Przedmiot**) = 0;
	virtual void przyjmij_obrazenia(double, Przedmiot**) = 0;
	virtual int Pancerz(Przedmiot ** E) = 0;
	virtual int sredni_atak(Przedmiot ** E) = 0;
	friend void arena(Postac &, Przedmiot**);
	friend void Save(Postac &);
	friend void Load(Postac *&);
	friend void fun(Postac &, Postac &, Przedmiot**);
	void odnowa_HP();
	void Lvlareny();
	void Drop(Postac &);
	void warta(int);
	void Sprawdz_Max_Exp();
	int GetPunkty_statystyk();
	double getodpornosc(){ return odpornosc; }
	void setobrazenia_otrzymane(double A){ obrazenia_otrzymane = A; };
	void Podnies_statystyki();
	void poraszka();
	void Sklep(Przedmiot**,Postac &);
	void Kup_Bron(Postac &,int, int);
	void Kup_Zbroje(Postac &, int, int);
	string Getnick();
	void Funkcja_sklepu(Przedmiot** , Postac &, int);
	double getobrazenia_otrzymane(){ return obrazenia_otrzymane; }

};

