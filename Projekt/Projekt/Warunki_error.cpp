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
			cout << "Wracasz do �wiata rozpaczy czy chcesz kontynuowa� t� potworn� rozgrywk�?\nTa decyzja powie nam czy jeste� prawdziwym wojownikiem.\n\n" << "1 - Tak\n\n" << "2 - Nie\n\nWybierz m�drze: ";
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
				cout << "Witam ci� m�ody wojowniku wkroczy�e� w�a�nie do �wiata, w kt�rym przeciwnicy\ns� najgorsi z najgorszych. Wszystko mo�e si� tu zda�y�, niczego nie mo�na \nsi� tu spodziewa�. Wielu przed tob� pr�bowa�o sprosta� temu wyzwaniu.\n";
				cout << "Lekcewa�yli swoich przeciwnik�w, przez co polegli.";
				cout << "Od ciebie bije wielka \naura nieznanej mi mocy. S�dz�, �e ty b�dziesz lepszy ni� ta ca�a reszta.";
				cout << "\n\nPowiedz jak ci� zw� : ";
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
			cout << "Kim jeste�.\n\n";
			cout << "1 - Paladyn (Umie w�ada� mieczami jednor�cznymi oraz pos�ugiwa� tarcza)\n";
			cout << "2 - Barbazynca(Pos�uguje si� dwoma toporami)\n";
			cout<< "3 - Wojownik(Miecze dwur�czne nie s� mu straszne)\n";
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
			cout << "Je�li my�lisz ze zarobisz tu kokosy to jeste� w wielkim b��dzie.\nZa godzine warty otrzymasz jedyne 10 z�ota. \nMaksymalnie mo�esz i�� na 24 h.\nIle godzin chcesz mie� warty(1h = 10s)?: ";
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
			cout << "Czy chcesz podnie�� statystyki? \n1 - Tak\n2 - Nie\nWybierz: ";
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
			cout << "1 - HP (+25 HP)\n2 - Si�a (+1 Si�y)\n3 - Zreczno�� (+1 Zreczno�ci)\nWybierz: ";
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
			cout << "Nie mam ca�ego dnia po�piesz si�!\n\n1 - Miecze(Paladyn)\n2 - Miecze dwur�czne(Wojownik)\n3 - Topory(Barbazynca)\n4 - Tarcze(Paladyn)\n5 - Zbroje\n6 - Wyjscie\n\nWybor: ";
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
			cout << "G�o�niej bo nie s�ysz�.\nTo m�wisz �e kt�r� rzecz chcesz ?\n6-Wyjscie\nPoprosze: ";
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
			cout << "Napewno chcesz tam i�� ? \n1 - Tak\n2 - Nie\nWybierz: ";
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