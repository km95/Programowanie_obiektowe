#include "Error.h"
#include "All.h"


Error::Error(int e)
{
	noError = e;
}

Error::~Error()
{
}

void Error::what()
{
	switch (noError)
	{
	case Decyzja:
		cout << "\nBledna dane, Prosze podac cyfre z odpowiedniego zakresu \n";
	    _getch();
		break;
	case Nick:
		cout << "\nPodany nick jest nieprawidlowy, prosze podac go ponownie \n";
		_getch();
		break;
	case Dlugosc:
		cout << "\nPodany nick jest za d³ugi\n";
		_getch();
		break;
	default:
		cout << "\nInny blad\n";
	}
}