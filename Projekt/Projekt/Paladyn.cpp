#include "Paladyn.h"

Paladyn::Paladyn()
{

}
//***************************************************************************************************************************************************************************************************
Paladyn::Paladyn(string n)
{
	nick = n;
	Klasa = "Paladyn";
	level = 1;
	MaxExp = 500;
	Exp = 0;
	MaxHP = 100;
	HP = MaxHP;
	Sila = 10;
	Zrecznosc = 5;
	skalowanie_sily = 1.2;
	skalowanie_zrecznosci = 1.1;
	odpornosc = 1.2;
	Kasa = 100;
	Prawa_reka_id = 0;
	Lewa_reka_id = 15;
	Zbroja_id = 20;
	Punkty_statystyk = 0;
	arena = 1;
}

//***************************************************************************************************************************************************************************************************
Paladyn::~Paladyn()
{
}
//***************************************************************************************************************************************************************************************************

void Paladyn::wypisz_staty()
{
	cout << "Statystyki: " << endl;
	cout << "Klasa postaci: " << Klasa << endl;
	cout << "Posiadany poziom: " << level <<endl;
	cout << "Doswiadczenie: " << Exp << " / " << MaxExp << endl;
	cout << "Zycie: " << HP << " / " << MaxHP << endl;
	cout << "Sila: " << Sila << endl;
	cout << "Zrecznosc: " << Zrecznosc<< endl;
	cout << "Punkty statystyk: " << Punkty_statystyk << endl;
	cout << "Kasa: " << Kasa << endl;

}
//***************************************************************************************************************************************************************************************************
void Paladyn::atak(Postac  &Przeciwnik, Przedmiot ** E)
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
void Paladyn::przyjmij_obrazenia(double atak, Przedmiot **E)
{
	double redukcja_obrazen = Pancerz(E);
	atak = atak - redukcja_obrazen;
	if (atak > 0)
	{
		HP = HP - atak;
		obrazenia_otrzymane += atak;
	}
	else
		atak = 0;
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << nick;
	SetConsoleTextAttribute(hOut, FOREGROUND_GREEN);
	cout << " Otrzyma³: " << atak << " Obr " << endl << endl;
	SetConsoleTextAttribute(hOut, 0x0007);

}
int Paladyn::Pancerz(Przedmiot ** E)
{
	return ((odpornosc *E[Zbroja_id]->getPancerz()) + (E[Lewa_reka_id]->getPancerz()/2));
}
int Paladyn::sredni_atak(Przedmiot ** E)
{
	return((skalowanie_zrecznosci*Zrecznosc) + (skalowanie_sily*Sila) +(( E[Prawa_reka_id]->getMax() + E[Prawa_reka_id]->getMin())/2)+rand()%10);// + E[Prawa_reka_id]->getMin());
}