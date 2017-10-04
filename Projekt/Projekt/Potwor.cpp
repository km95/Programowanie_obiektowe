#include "Potwor.h"
//Potwor::Potwor(int e, int enm)
//{
//	//Potwor::nx = e;
////	level = e;
//	// = new Potwor(level, Potwor::Gobliny);
//	switch (enm)
//	{
//		case Gobliny:
//			break;
//		case Psy:
//			break;
//	}
//}
Potwor::Potwor(int level)
{
	switch ((rand() % 15))
	{
	case Goblin:
		nick = "Goblin";
		break;
	case Pies:
		nick = "Pies";
		break;
	case Wilk:
		nick = "Wilk";
		break;
	case Smok:
		nick = "Smok";
		break;
	case Leszy:
		nick = "Leszy";
		break;
	case Gryf:
		nick = "Gryf";
		break;
	case Kraken:
		nick = "Kraken";
		break;
	case Salamandra:
		nick = "Salamandra";
		break;
	case Lisz:
		nick = "Lisz";
		break;
	case Duch:
		nick = "Duch";
		break;
	case Zombie:
		nick = "Zombie";
		break;
	case Szkielet:
		nick = "Szkielet";
		break;
	case Utopiec:
		nick = "Utopiec";
		break;
	default:
		nick = "Dzielny tabaluga";

	}
	dodatkowy_atak = 2 + (level / 10);
	HP = 8 * ((level*(rand() % 4 + 2)));
	Sila = ((level*(rand() % 3 + 2)));
	Zrecznosc = ((level*(rand() % 4 + 1)));
	Kasa = ((25 * level) + (rand() % 9 + 1));
	Exp = (level*(15 + (rand() % 5 + 1)));
	odpornosc = 1;
	obrazenia_otrzymane = 0;
}
int Potwor::Pancerz(Przedmiot ** E)
{
	return (odpornosc + rand()%10 );
}
int Potwor::sredni_atak(Przedmiot ** E)
{
	return((dodatkowy_atak + Sila) + (dodatkowy_atak+Zrecznosc) + rand() % 9 + 1);
}
Potwor::Potwor()
{
	dodatkowy_atak = 1.5;
	HP = 100;
	Sila = 1;
	Zrecznosc = 1;
	Kasa = 10;
	Exp = 10;
}
//***************************************************************************************************************************************************************************************************
Potwor::~Potwor()
{
}
//***************************************************************************************************************************************************************************************************
void Potwor::przyjmij_obrazenia(double atak,Przedmiot **E)
{
	int redukcja_obrazen = Pancerz(E);
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
	cout << " Otrzyma³: " << atak << " Obr " << endl;
	SetConsoleTextAttribute(hOut, 0x0007);
}
//***************************************************************************************************************************************************************************************************
void Potwor::atak(Postac  &Przeciwnik, Przedmiot **E)
{
	double atak = sredni_atak(E);
	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << nick;
	SetConsoleTextAttribute(hOut, FOREGROUND_RED);
	cout << " Zada³: " << atak << setw(21) << " Obr ";
	SetConsoleTextAttribute(hOut, 0x0007);
	Przeciwnik.przyjmij_obrazenia(atak, E);
}
//***************************************************************************************************************************************************************************************************
void Potwor::wypisz_staty()
{
	cout << "Statystyki: " << endl;
	cout << "HP: " << HP << endl;
	cout << "Sila: " << Sila << endl;
	cout << "Zrecznosc: " << Zrecznosc << endl;

}