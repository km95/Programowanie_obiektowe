#include "Przeciwnik_areny.h"

Przeciwnik_areny::Przeciwnik_areny()
{

}
Przeciwnik_areny::Przeciwnik_areny(string nick_p, int level_p, int HP_p, int Sila_p, int Zrecznosc_p, int Kasa_p, int Prawa_reka_id_p, int Lewa_reka_id_p, int Zbroja_id_p)
{
	nick = nick_p;
	Klasa = "Wojownik areny";
	level = level_p;
	MaxHP = HP_p;
	HP = MaxHP;
	Sila = Sila_p;
	Zrecznosc = Zrecznosc_p;
	skalowanie_sily = 1;
	skalowanie_zrecznosci = 1;
	odpornosc = 1;
	Kasa = Kasa_p;
	Prawa_reka_id = Prawa_reka_id_p;
	Lewa_reka_id = Lewa_reka_id_p;
	Zbroja_id = Zbroja_id_p;
	Punkty_statystyk = 0;
	Exp = 0;
}
//***************************************************************************************************************************************************************************************************
Przeciwnik_areny::Przeciwnik_areny(string n)
{
	nick = n;
	Klasa = "Paladyn";
	level = 1;
	MaxExp = 50;
	Exp = 0;
	MaxHP = 100;
	HP = MaxHP;
	Sila = 10;
	Zrecznosc = 5;
	skalowanie_sily = 1.2;
	skalowanie_zrecznosci = 1;
	odpornosc = 1;
	Kasa = 100;
	Prawa_reka_id = 0;
	Lewa_reka_id = 15;
	Zbroja_id = 20;
	Punkty_statystyk = 0;

}

//***************************************************************************************************************************************************************************************************
Przeciwnik_areny::~Przeciwnik_areny()
{
}
//***************************************************************************************************************************************************************************************************

void Przeciwnik_areny::wypisz_staty()
{
	cout << "Statystyki: " << endl;
	cout << "Klasa postaci: " << Klasa << endl;
	cout << "Posiadany poziom: " << level << endl;
	cout << "Doswiadczenie: " << Exp << " / " << MaxExp << endl;
	cout << "Zycie: " << HP << " / " << MaxHP << endl;
	cout << "Sila: " << Sila << endl;
	cout << "Zrecznosc: " << Zrecznosc << endl;
	cout << "Punkty statystyk: " << Punkty_statystyk << endl;

}
//***************************************************************************************************************************************************************************************************
void Przeciwnik_areny::atak(Postac  &Przeciwnik, Przedmiot ** E)
{
	//cout << E[Prawa_reka_id]->getMin();
	int atak = sredni_atak(E); //+E[Prawa_reka_id]->getMin() );
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << nick;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << " Zada³: " << atak << setw(21) << " Obr ";
	SetConsoleTextAttribute(hOut, 0x0007);
	Przeciwnik.przyjmij_obrazenia(atak, E);
}
//***************************************************************************************************************************************************************************************************
void Przeciwnik_areny::przyjmij_obrazenia(double atak, Przedmiot **E)
{
	double redukcja_obrazen = (Zrecznosc*0.1);
	atak = atak - redukcja_obrazen;
	if (atak > 0)
	{
		HP = HP - atak;
		obrazenia_otrzymane += atak;
	}
	else
		atak = 0;;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << nick;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << " Otrzyma³: " << atak << " Obr " << endl << endl;
	SetConsoleTextAttribute(hOut, 0x0007);

}
int Przeciwnik_areny::Pancerz(Przedmiot ** E)
{
	return ((odpornosc *E[Zbroja_id]->getPancerz()));
}
int Przeciwnik_areny::sredni_atak(Przedmiot ** E)
{
	return((skalowanie_zrecznosci*Zrecznosc) + (skalowanie_sily*Sila) + ((E[Prawa_reka_id]->getMax() + E[Prawa_reka_id]->getMin()) / 2) + rand() % 10);
}