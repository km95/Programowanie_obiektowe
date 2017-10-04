#pragma once
#include "Error.h"
#include "All.h"
int Wyjatki_wczytaj()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "Wracasz do œwiata rozpaczy czy chcesz kontynuowaæ t¹ potworn¹ rozgrywkê?\nTa decyzja powie nam czy jesteœ prawdziwym wojownikiem.\n\n" << "1 - Tak\n\n" << "2 - Nie\n\nWybierz m¹drze: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 3) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}

//***************************************************************************************************************************************************************************************************
string Wyjatki_nick()
{
	string nick;
	bool err;

		do
		{
			err = false;
			try
			{
				system("cls");
				cout << "Witam ciê m³ody wojowniku wkroczy³eœ w³aœnie do œwiata, w którym przeciwnicy\ns¹ najgorsi z najgorszych. Wszystko mo¿e siê tu zda¿yæ, niczego nie mo¿na \nsiê tu spodziewaæ. Wielu przed tob¹ próbowa³o sprostaæ temu wyzwaniu.\n";
				cout << "Lekcewa¿yli swoich przeciwników, przez co polegli.";
				cout << "Od ciebie bije wielka \naura nieznanej mi mocy. S¹dzê, ¿e ty bêdziesz lepszy ni¿ ta ca³a reszta.";
				cout << "\n\nPowiedz jak ciê zw¹ : ";
				getline(cin, nick);

				if (nick.length() < 1) throw Error(Error::Nick);
				for (int i = 0; i<nick.length(); i++)
				if ((isdigit(nick[i])) || (!isalpha(nick[i]) && !(nick[i] == ' ' || nick[i] == '-'))) throw Error(Error::Nick);
				if (nick.length() > 15) throw Error(Error::Dlugosc);
			}
			catch (Error & e)
			{
				e.what();
				err = true;
			}

		} while (err);
	return nick;
}
//***************************************************************************************************************************************************************************************************
int Wyjatki_wybor_postaci()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "Kim jesteœ.\n\n";
			cout << "1 - Paladyn (Umie w³adaæ mieczami jednorêcznymi oraz pos³ugiwaæ tarcza)\n";
			cout << "2 - Barbazynca(Pos³uguje siê dwoma toporami)\n";
			cout<< "3 - Wojownik(Miecze dwurêczne nie s¹ mu straszne)\n";
			cout << "\nWybor postaci: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n>=4) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();
			err = true;
		}

	} while (err);
	return n;
}
//***************************************************************************************************************************************************************************************************
int Wyjatki_menu_rozgrywki()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "1 - Wyprawa\n" << "2 - Arena\n" << "3 - Sanktuarium\n" << "4 - Warta\n" << "5 - Sklep\n" << "6 - Statystyki\n" << "7 - Wyjscie\nWybierz: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 8) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();
			err = true;
		}

	} while (err);
	return n;
}
//***************************************************************************************************************************************************************************************************
int Wyjatki_podaj_warte()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "Jeœli myœlisz ze zarobisz tu kokosy to jesteœ w wielkim b³êdzie.\nZa godzine warty otrzymasz jedyne 10 z³ota. \nMaksymalnie mo¿esz iœæ na 24 h.\nIle godzin chcesz mieæ warty(1h = 10s)?: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n < 0 || n >= 25) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}
//***************************************************************************************************************************************************************************************************
int Wyjatki_wczytaj_podniesc_statystyki_wybor()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "Czy chcesz podnieœæ statystyki? \n1 - Tak\n2 - Nie\nWybierz: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 3) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}
int Wyjatki_na_dodanie_statystyk()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "1 - HP (+25 HP)\n2 - Si³a (+1 Si³y)\n3 - Zrecznoœæ (+1 Zrecznoœci)\nWybierz: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 4) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}
int Wyjatki_wybor_sklep_menu()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "Nie mam ca³ego dnia poœpiesz siê!\n\n1 - Miecze(Paladyn)\n2 - Miecze dwurêczne(Wojownik)\n3 - Topory(Barbazynca)\n4 - Tarcze(Paladyn)\n5 - Zbroje\n6 - Wyjscie\n\nWybor: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 7) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}
int Wyjatki_wybor_sklep_menu_w_menu()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "G³oœniej bo nie s³yszê.\nTo mówisz ¿e któr¹ rzecz chcesz ?\n6-Wyjscie\nPoprosze: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 7) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}
int decyzja_do_areny_wejscie()
{
	bool err;
	int n;
	string decyzja;
	do
	{
		err = false;
		try
		{
			system("cls");
			cout << "Napewno chcesz tam iœæ ? \n1 - Tak\n2 - Nie\nWybierz: ";
			getline(cin, decyzja);
			for (int i = 0; i < decyzja.length(); i++)
			if (!isdigit(decyzja[i])) throw Error(Error::Decyzja);

			n = atoi(decyzja.c_str());
			if (n <= 0 || n >= 3) throw Error(Error::Decyzja);
		}
		catch (Error & e)
		{
			e.what();

			err = true;
		}
	} while (err);
	return n;
}