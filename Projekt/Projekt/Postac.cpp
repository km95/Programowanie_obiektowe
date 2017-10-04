#include "Postac.h"
#include "Paladyn.h"
#include "Barbazynca.h"
#include "Wojownik.h"
#include "Error.h"
#include "Przeciwnik_areny.h"
void Postac::odnowa_HP()
{
	HP = MaxHP;
}
void Postac::Lvlareny()
{
	arena += 1;
}
//***************************************************************************************************************************************************************************************************
void Postac::Drop(Postac &Potwor)
{
	Exp += Potwor.Exp;
	Kasa = Kasa + Potwor.Kasa;
	cout << "Kasa: " << Potwor.Kasa;
	cout << "	Exp: " << Potwor.Exp;
}
//***************************************************************************************************************************************************************************************************
void Postac::Sprawdz_Max_Exp()
{
	if (Exp >= MaxExp)
	{
		MaxExp *= 2;
		Exp = 0;
		level += 1;
		Punkty_statystyk += 1;
		cout << "	Osi¹gno³eœ nowy poziom";
	}
	else
	{

	}
}
//***************************************************************************************************************************************************************************************************
void Postac::warta(int w)
{
	Kasa += (10 * w);
}
//***************************************************************************************************************************************************************************************************
int Postac::GetPunkty_statystyk()
{
	return Punkty_statystyk;
}
//***************************************************************************************************************************************************************************************************
string Postac::Getnick()
{
	return nick;
}
//***************************************************************************************************************************************************************************************************
void Postac::Podnies_statystyki()
{
	int ile= Wyjatki_na_dodanie_statystyk();
	switch (ile)
	{
	case 1:
		MaxHP += 25;
		Punkty_statystyk -= 1;
		break;
	case 2:
		Sila += 1;
		Punkty_statystyk -= 1;
		break;
	case 3:
		Zrecznosc += 1;
		Punkty_statystyk -= 1;
		break;
	}
}
//***************************************************************************************************************************************************************************************************

void Postac::poraszka()
{
	cout << "Pora¿ka!!! Teraz s³ono za to zap³acisz:\n";
	HP = MaxHP;
	Exp = 0;
	Kasa -= 100;
	cout << "HP :" << HP << "\nExp: " << Exp << "\nKasa: " << Kasa << "\nDalej: ";
}
//***************************************************************************************************************************************************************************************************

void Postac::Sklep(Przedmiot** I,Postac &P)
{
	cout << "Przedmioty jakie posiadasz: \n\n";
	cout << left << "Prawa rêka: " << setw(35) << I[Prawa_reka_id]->getnazwa() << "		Œrednie obrazenia: " << I[Prawa_reka_id]->getSrednieobrazenia();
	if (P.Klasa == "Paladyn")
		cout << "\nLewa rêka: " << setw(35) << I[Lewa_reka_id]->getnazwa() << "		Pancerz: " << I[Lewa_reka_id]->getPancerz();
	else
		if (P.Klasa == "Barbazynca")
			cout << "\nLewa rêka: " << setw(35) << I[Lewa_reka_id]->getnazwa() << "		Œrednie obrazenia:  " << I[Lewa_reka_id]->getSrednieobrazenia();
	cout << "\nZbroja: " << setw(35) << I[Zbroja_id]->getnazwa() << "		Pancerz: " << I[Zbroja_id]->getPancerz() << endl;
	cout << "\nCzego potrzebujesz kmiocie ?\nDalej "; _getch();
	switch (Wyjatki_wybor_sklep_menu())
	{
	case 1:
		if (P.Klasa == "Paladyn")
		{
			system("cls");
			for (int i = 0; i < 5; i++)
				cout << i + 1 << " - " << setw(25) << I[i]->getnazwa() << " Œrednie obrazenia : " <<setw(6)<< I[i]->getSrednieobrazenia() << "Cena: " << I[i]->getcena() << endl;
			cout << "6 - Wyjœcie  \n";
			cout <<"Kasa: " <<P.Kasa<<endl;
			cout << "Wybierz: ";
				_getch();
				int wybor = Wyjatki_wybor_sklep_menu_w_menu();
				if (wybor != 6)
				{
					Funkcja_sklepu(I, P, (wybor));
				}
				else
					cout << "Ale jesteœ niezdecydowany.\nDalej";
		}
		else
			cout << "Œlepy jesteœ?! To jest tylko dla Paladyna wynocha!!!\n";
		break;
	case 2:
		if (P.Klasa == "Wojownik")
		{
			system("cls");
			for (int i = 5; i < 10; i++)
				cout << i - 4 << " - " << setw(25) << I[i]->getnazwa() << " Œrednie obrazenia : " << setw(6) << I[i]->getSrednieobrazenia() << "Cena: " << I[i]->getcena() << endl;
			cout << "6 - Wyjœcie  \n";
			cout << "Kasa: " << P.Kasa << endl;
			cout << "Wybierz:";
			_getch();
			int wybor = Wyjatki_wybor_sklep_menu_w_menu();
			if (wybor != 6)
			{
				Funkcja_sklepu(I, P, (wybor + 5));
			}
			else
				cout << "Ale jesteœ niezdecydowany.\nDalej";

		}
		else
			cout << "Œlepy jesteœ?! To jest tylko dla Wojownika wynocha!!!\n";
		break;
	case 3:
		if (P.Klasa == "Barbazynca")
		{
			system("cls");
			for (int i = 10; i < 15; i++)
				cout << i - 9 << " - " << setw(25) << I[i]->getnazwa() << " Œrednie obrazenia : " << setw(6) << I[i]->getSrednieobrazenia() << "Cena: " << I[i]->getcena() << endl;
			cout << "6 - Wyjœcie  \n";
			cout << "Kasa: " << P.Kasa << endl;
			cout << "Wybierz: ";
			_getch();
			int wybor = Wyjatki_wybor_sklep_menu_w_menu();
			if (wybor != 6)
			{
				Funkcja_sklepu(I, P, (wybor + 10));
			}
			else
				cout << "Ale jesteœ niezdecydowany.\nDalej";
		}
		else
			cout << "Œlepy jesteœ?! To jest tylko dla Barbazyncy wynocha!!!\n";
		break;
	case 4:
		if (P.Klasa == "Paladyn")
		{
			system("cls");
			for (int i = 15; i < 20; i++)
				cout << i - 14 << " - " << setw(25) << I[i]->getnazwa() << " Pancerz : " << setw(6) << I[i]->getPancerz() << "Cena: " << I[i]->getcena() << endl;
			cout << "6 - Wyjœcie  \n";
			cout << "Kasa: " << P.Kasa << endl;
			cout << "Wybierz: ";
			_getch();
			int wybor = Wyjatki_wybor_sklep_menu_w_menu();
			if (wybor != 6)
			{
				Funkcja_sklepu(I, P, (wybor + 15));
			}
			else
				cout << "Ale jesteœ niezdecydowany.\nDalej";
		}
		else
			cout << "Œlepy jesteœ?! To jest tylko dla Paladyna wynocha!!!\n";
		break;
	case 5:
	{
			  system("cls");
			  for (int i = 20; i < 25; i++)
				  cout << i - 19 << " - " << setw(25) << I[i]->getnazwa() << " Pancerz : " << setw(6) << I[i]->getPancerz() << "Cena: " << I[i]->getcena() << endl;
			  cout << "6 - Wyjœcie  \n";
			  cout << "Kasa: " << P.Kasa << endl;
			  cout << "Wybierz: ";
			  _getch();
			  int wybor = Wyjatki_wybor_sklep_menu_w_menu();
			  if (wybor != 6)
			  {
				  Funkcja_sklepu(I, P, (wybor + 20));
			  }
			  else
				  cout << "Ale jesteœ niezdecydowany.\nDalej";
	}
		break;
	case 6:cout << "Mam nadzieje ¿e zginiesz!";
		break;
	}
}
void Postac::Kup_Bron(Postac &P, int bron, int cena )
{
	if (P.Klasa == "Paladyn")
		{
			P.Prawa_reka_id = bron;
			P.Kasa -= cena;
		}
	else
		{

			P.Prawa_reka_id = bron;
			P.Lewa_reka_id = bron;
			P.Kasa -= cena;
		}
}
void Postac::Kup_Zbroje(Postac &P, int zbroja, int cena)
{
	if (zbroja >= 20)
	{
		P.Zbroja_id = zbroja;
		P.Kasa -= cena;
	}
	else
	{
		P.Lewa_reka_id = zbroja;
		P.Kasa -= cena;
	}
}
void Postac::Funkcja_sklepu(Przedmiot** I, Postac &P, int i)
{
	if (i >= 15)
	{
		if (P.Kasa >= I[i - 1]->getcena())
		{
			P.Kup_Zbroje(P, I[i - 1]->getId(), I[i - 1]->getcena());

			cout << "No nareszcie.";
		}
		else

			cout << "Ty chyba sobie ¿artyjesz ¿e za tyle pieniêdzy dostaniesz ten przedmiot !\nDalej";
	}
	else
	{

		if (P.Kasa >= I[i - 1]->getcena())
		{
			P.Kup_Bron(P, I[i - 1]->getId(), I[i - 1]->getcena());
			system("cls");
			cout << "No nareszcie.";
		}
		else
			cout << "Ty chyba sobie ¿artyjesz ze za tyle pieniêdzy dostaniesz ten przedmiot !\nDalej";
	}
}
//***************************************************************************************************************************************************************************************************
void Save(Postac &P)
{
	fstream plik;
	string nazwa = "Save.csv";
	plik.open(nazwa, ios::out);
	if (plik.good())
	{
		plik << P.Klasa << endl
			<< P.nick << endl
			<< P.MaxHP << endl
			<< P.HP << endl
			<< P.level << endl
			<< P.Sila << endl
			<< P.Zrecznosc << endl
			<< P.MaxExp << endl
			<< P.Exp << endl
			<< P.Prawa_reka_id << endl
			<< P.Lewa_reka_id << endl
			<< P.Zbroja_id << endl
			<< P.Kasa << endl
			<< P.odpornosc << endl
			<< P.skalowanie_sily << endl
			<< P.skalowanie_zrecznosci << endl
			<< P.Punkty_statystyk << endl
			<< P.arena;
			plik.close();
	}
	else cout << "Nie udalo sie zapisac " << endl;

}
//***************************************************************************************************************************************************************************************************
void Load(Postac *&P)
{
	fstream plik;
	string nazwa = "Save.csv";
	plik.open(nazwa, ios::in);
	if (plik.good())
	{
		string Klasa, nick, MaxHP, HP, level, Sila, Zrecznosc, MaxExp, Exp, Prawa_reka_id, Lewa_reka_id, Zbroja_id, Kasa, odpornosc, skalowanie_sily, skalowanie_zrecznosci, punkty_statystyk,arena;
		while (!plik.eof())
		{
			getline(plik, Klasa);
			getline(plik, nick);
			getline(plik, MaxHP);
			getline(plik, HP);
			getline(plik, level);
			getline(plik, Sila);
			getline(plik, Zrecznosc);
			getline(plik, MaxExp);
			getline(plik, Exp);
			getline(plik, Prawa_reka_id);
			getline(plik, Lewa_reka_id);
			getline(plik, Zbroja_id);
			getline(plik, Kasa);
			getline(plik, odpornosc);
			getline(plik, skalowanie_sily);
			getline(plik, skalowanie_zrecznosci);
			getline(plik, punkty_statystyk);
			getline(plik, arena);
			if (Klasa == "Paladyn")
				P = new Paladyn();
			else
				if (Klasa == "Barbazynca")
				P = new Barbazynca();
				else
					P = new Wojownik();
			P->Klasa = Klasa;
			P->nick = nick;
			P->MaxHP = atoi(MaxHP.c_str());
			P->HP = atoi(HP.c_str());
			P->level = atoi(level.c_str());
			P->Sila = atoi(Sila.c_str());
			P->Zrecznosc = atoi(Zrecznosc.c_str());
			P->MaxExp = atoi(MaxExp.c_str());
			P->Exp = atoi(Exp.c_str());
			P->Prawa_reka_id = atoi(Prawa_reka_id.c_str());
			P->Lewa_reka_id = atoi(Lewa_reka_id.c_str());
			P->Zbroja_id = atoi(Zbroja_id.c_str());
			P->Kasa = atoi(Kasa.c_str());
			P->odpornosc = atoi(odpornosc.c_str());
			P->skalowanie_sily = atoi(skalowanie_sily.c_str());
			P->skalowanie_zrecznosci = atoi(skalowanie_zrecznosci.c_str());
			P->Punkty_statystyk = atoi(punkty_statystyk.c_str());
			P->arena = atoi(arena.c_str());
		}

		plik.close();
	}
	else
		cout << "\nBlad podczas odczytu do pliku!\n";
}
//***************************************************************************************************************************************************************************************************
void fun(Postac &P , Postac & A, Przedmiot** E)
{
	P.setobrazenia_otrzymane(0);
	cout << setw(25) << left << P.Getnick() << setw(16) << "VS" << A.Getnick() << endl << endl;
	cout << "Si³a: " << setw(35) << P.getSila() << "Si³a: " << A.getSila() << endl;
	cout << "Zrêcznoœæ: " << setw(30) << P.getZrecznosc() << "Zrêcznoœæ: " << A.getZrecznosc() << endl;
	cout << "Pancerz: " << setw(32) << P.Pancerz(E) << "Pancerz: " << A.Pancerz(E) << endl;
	cout << "Œredni atak: " << setw(28) << P.sredni_atak(E) << "Œredni atak: " << A.sredni_atak(E) << endl;
	cout << "Twoje HP: " << setw(31) << P.getHP() << "Przeciwnika HP:" << A.getHP() << endl << endl;
	do
	{

		cout << endl; P.atak(A, E); cout << endl;
		if (A.getHP()>0)
			A.atak(P, E);
		Sleep(500);
		//						   cout << "Przeciwnika HP:" << potwor->getHP() << "		Twoje HP: " << postac[0]->getHP() << endl << endl;
	} while (((P.getHP()) >= 0) && ((A.getHP()) >= 0));
	if (P.getHP() > 0)
	{
		cout << "\nZada³eœ " << P.getobrazenia_otrzymane() << " Obra¿eñ" << "\nStraci³es HP: " << P.getobrazenia_otrzymane() << "\nPozosta³o HP: " << P.getHP() << endl << endl;
		cout << "\nWygrales!!!!!!!\nNagroda:" << endl;
		P.Lvlareny();
		P.Drop(A);
		P.Sprawdz_Max_Exp();
	}
	else
	{
		P.poraszka();
	}
	_getch();
}
void arena(Postac & P, Przedmiot** E)
{
	cout << P.arena;
	system("cls");
	cout << "Teraz ju¿ za póŸno nie ma odwrotu!\nBedziesz musia³ walczyc\nDalej\n"; _getch();

	switch (P.arena)
	{
	case 1:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Tomek", 1, 100, 10, 10, 500, 5, 5, 20);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 2:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Wredny s¹siad", 3, 200, 11, 10, 1500, 5, 5, 20);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 3:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Teœciowa", 5, 300, 12, 10, 3500, 5, 5, 20);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 4:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Buka", 1, 400, 13, 13, 4500, 6, 6, 21);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 5:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Gargamel", 10, 500, 14, 10, 8500, 6, 7, 21);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 6:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Arktos", 15, 700, 15, 10, 15000, 7, 7, 22);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 7:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Geralt z Rivii ", 20, 900, 16, 10, 20000, 7, 7, 22);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 8:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Pani z dziekanatu", 25, 950, 17, 10, 30000, 8, 8, 23);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 9:
	{
			  Postac *Przeciwnik = new Przeciwnik_areny("Bezimienny", 30, 995, 18, 15, 80000, 8, 8, 23);
			  fun(P, *Przeciwnik, E);
			  delete  Przeciwnik;
	}
		break;
	case 10:
	{
			   Postac *Przeciwnik = new Przeciwnik_areny("Gang puchatka", 40, 1000, 19, 10, 250000, 9, 9, 24);
			   fun(P, *Przeciwnik, E);
			   delete  Przeciwnik;
	}
		break;
	default:
		system("cls");
		cout << "Zosta³es juz mistrzem, nikt nie chce z toba walczyæ\n"; _getch();
	}
	
}