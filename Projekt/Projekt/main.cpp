
#include "All.h"
#include "Paladyn.h"
#include "Barbazynca.h"
#include "Wojownik.h"
#include "Potwor.h"
#include "Miecz.h"
#include "Miecz_dwureczny.h"
#include "Error.h"
#include "Topor.h"
#include "Tarcza.h"
#include "Zbroja.h"
//#include "Warunki_error.cpp"
void mansas();
bool fileExists(const string&);
Przedmiot **Przedmioty;
int main()
{
	setlocale(LC_ALL, "");
	mansas();
	srand(time(NULL));
	int wczyt;
	Postac **postac = new Postac*[1]; //usun ten jebany obiekt
	if (fileExists("Save.csv"))
	{
		wczyt = Wyjatki_wczytaj();
	}
	else
	wczyt = 0;
	if (wczyt == 1)
	{
		Load(postac[0]);
	}	
	else
	{
		string nick = Wyjatki_nick();

		switch (Wyjatki_wybor_postaci())
		{
		case 1:
			postac[0] = new Paladyn(nick);
			break;
		case 2:
			postac[0] = new Barbazynca(nick);
			break;
		case 3:
			postac[0] = new Wojownik(nick);
			break;
		}
	}
		int wybor = 0;
		system("cls");
		do
		{
			switch (Wyjatki_menu_rozgrywki())
			{
			case 1:system("cls");
			{
					   Postac *potwor = new Potwor(postac[0]->getlevel());
					   postac[0]->setobrazenia_otrzymane(0);
					   cout <<setw(25) <<left<< postac[0]->Getnick() << setw(16) << "VS" << potwor->Getnick() << endl << endl;
					   cout << "Si³a: " << setw(35) << postac[0]->getSila() << "Si³a: " << potwor->getSila() << endl;
					   cout << "Zrêcznoœæ: " << setw(30) << postac[0]->getZrecznosc() << "Zrêcznoœæ: " << potwor->getZrecznosc() << endl;
					   cout << "Pancerz: " << setw(32) << postac[0]->Pancerz(Przedmioty) << "Pancerz: " << potwor->Pancerz(Przedmioty) << endl;
					   cout << "Œredni atak: " << setw(28) << postac[0]->sredni_atak(Przedmioty) << "Œredni atak: " << potwor->sredni_atak(Przedmioty) << endl;
					   cout << "Twoje HP: " << setw(31) << postac[0]->getHP() << "Przeciwnika HP:" << potwor->getHP() << endl << endl;
					   do
					   {

						   cout << endl; postac[0]->atak(*potwor, Przedmioty); cout << endl;
						   if (potwor->getHP()>0)
						   potwor->atak(*postac[0], Przedmioty);
						   Sleep(1000);
//						   cout << "Przeciwnika HP:" << potwor->getHP() << "		Twoje HP: " << postac[0]->getHP() << endl << endl;
					   } while (((postac[0]->getHP()) >= 0) && ((potwor->getHP()) >= 0));
					   if (postac[0]->getHP() > 0)
					   {
						   cout << "\nZada³eœ " << potwor->getobrazenia_otrzymane() << " Obra¿eñ" << "\nStraci³es HP: " << postac[0]->getobrazenia_otrzymane() << "\nPozosta³o HP: " << postac[0]->getHP() << endl << endl;
						   cout << "\nWygrales!!!!!!!\nNagroda:" << endl;
						   postac[0]->Drop(*potwor);
						   postac[0]->Sprawdz_Max_Exp();
					   }
					   else
					   {

						   postac[0]->poraszka();
					   }
					   delete  potwor;
					   _getch();
			}break;
			case 2:system("cls");
				if (decyzja_do_areny_wejscie()==1)
				{
					arena(*postac[0], Przedmioty);
				}
				else
				{
					system("cls");
					cout << "Jednak wiesz gdzie twoje miejsce" << endl;
					cout << "Dalej"; _getch();
				}

				break;
			case 3:system("cls");
				cout << "Dotar³eœ do œwi¹tyni wiecznej m³odoœci twoje HP zostanie odnowione po 5s" << endl;
				postac[0]->odnowa_HP();
				Sleep(5000);
				cout << "Dalej"; _getch();
				break;
			case 4:system("cls");
				int warta;
				warta = Wyjatki_podaj_warte();
				postac[0]->warta(warta);
				Sleep((10000 * warta));
				cout << "Dalej"; _getch();
				break;
			case 5:system("cls");
				postac[0]->Sklep(Przedmioty,*postac[0]);
				_getch();
				break;
			case 6:system("cls");
				if ((postac[0]->GetPunkty_statystyk()) != 0)
				{
					int podniesc_statystyki_wybor = Wyjatki_wczytaj_podniesc_statystyki_wybor();
					if (podniesc_statystyki_wybor !=2)
					postac[0]->Podnies_statystyki();
				}
				system("cls");
				postac[0]->wypisz_staty();
				cout << "Dalej"; _getch();
				break;
			case 7:
				wybor = 9;
				Save(*postac[0]);
				cout << "Ty tam po drugiej stronie wiedz ¿e ciê obserowjemy i wszystkie twoje wyczyny\nzostan¹ zachowane w naszej pamieci.";
				break;

			}
		} while (!(wybor == 9));

		_getch();

}

void mansas()
{

	Przedmioty = new Przedmiot *[25];
	Przedmioty[0] = new Miecz("Drewniany miecz", "Miecz",1, 200, 0, 3, 5);
	Przedmioty[1] = new Miecz("Stalowy miecz", "Miecz",5, 2000, 1, 10, 20);
	Przedmioty[2] = new Miecz("Miecz z koœci s³oniowej ", "Miecz", 10, 15000, 2, 30, 50);
	Przedmioty[3] = new Miecz("Ebonitowy miecz", "Miecz", 20, 40000, 3, 60, 90);
	Przedmioty[4] = new Miecz("Demoniczny miecz", "Miecz", 30, 160000, 4, 150, 200);

	Przedmioty[5] = new Miecz_dwureczny("Drewniany miecz dwurêczny", "Miecz_dwureczny", 1, 200, 5, 7, 10);
	Przedmioty[6] = new Miecz_dwureczny("Stalowy miecz dwurêczny", "Miecz_dwureczny", 5, 2000, 6, 20, 30);
	Przedmioty[7] = new Miecz_dwureczny("Miecz dwurêczny z koœci s³oniowej", "Miecz_dwureczny", 10, 15000, 7, 50, 70);
	Przedmioty[8] = new Miecz_dwureczny("Ebonitowy miecz dwurêczny", "Miecz_dwureczny", 20, 40000, 8, 90, 130);
	Przedmioty[9] = new Miecz_dwureczny("Demoniczny miecz dwurêczny ", "Miecz_dwureczny", 30, 160000, 9, 200, 300);

	Przedmioty[10] = new Topor("Drewniany topor", "Topor", 1, 200, 0, 10, 5);
	Przedmioty[11] = new Topor("Stalowy topor", "Topor", 5, 2000, 11, 10, 20);
	Przedmioty[12] = new Topor("Topór z koœci s³oniowej ", "Topor", 10, 15000, 12, 30, 50);
	Przedmioty[13] = new Topor("Ebonitowy topór ", "Topor", 20, 40000, 13, 60, 90);
	Przedmioty[14] = new Topor("Demoniczny topór", "Topor", 30, 160000, 14, 150, 200);

	Przedmioty[15] = new Tarcza("Drewniana Tarcza", "Tarcza", 1, 200, 15, 4);
	Przedmioty[16] = new Tarcza("Stalowa Tarcza", "Tarcza", 5, 2000, 16, 15);
	Przedmioty[17] = new Tarcza("Tarcza z koœci s³oniowej ", "Tarcza", 10, 15000, 17, 35);
	Przedmioty[18] = new Tarcza("Ebonitowa Tarcza", "Tarcza", 20, 40000, 18, 75);
	Przedmioty[19] = new Tarcza("Demoniczna Tarcza", "Tarcza", 30, 160000, 19, 180);

	Przedmioty[20] = new Zbroja("Skórzana Zbroja", "Zbroja", 1, 200, 20, 5);
	Przedmioty[21] = new Zbroja("Stalowa Zbroja", "Zbroja", 5, 2000, 21, 20);
	Przedmioty[22] = new Zbroja("Zbroja z koœci s³oniowej ", "Zbroja", 10, 15000, 22, 50);
	Przedmioty[23] = new Zbroja("Ebonitowa Zbroja", "Zbroja", 20, 40000, 23, 100);
	Przedmioty[24] = new Zbroja("Demoniczna zbroja ", "Zbroja", 30, 160000,24, 250);



}
bool fileExists(const string& fileName)
{
	fstream plik;
	plik.open(fileName.c_str(), ios::in | ios::_Nocreate);  /* wa¿ne, by nie tworzyæ pliku, jeœli nie istnieje, st¹d flaga nocreate */
	if (plik.is_open())
	{
		plik.close();
		return true;
	}
	plik.close();
	return false;
}