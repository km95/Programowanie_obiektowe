#pragma once
#include "All.h"

class Error
{
	int noError;

public:
	Error(int e);
	~Error();

	enum { Decyzja, Nick, Dlugosc };
	void what();
};

int  Wyjatki_menu_podstawowego();
string Wyjatki_nick();
int Wyjatki_wybor_postaci();
int Wyjatki_menu_rozgrywki();
int Wyjatki_wczytaj();
int Wyjatki_podaj_warte();
int Wyjatki_wczytaj_podniesc_statystyki_wybor();
int Wyjatki_na_dodanie_statystyk();
int Wyjatki_wybor_sklep_menu();
int Wyjatki_wybor_sklep_menu_w_menu();
int decyzja_do_areny_wejscie();