#include "Dane.h"
#include <iostream>

using namespace std;

Dane::Dane()
{
#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor klasy Dane." << endl;
#endif
	typSzpitala = "Ogólny";
	miejscowoscSzpitala = "Warszawa";
	ulica = "Marymoncka";
	numerBudynku = 4;
}

Dane::Dane(string typ, string miejsc, string ul, int nu) 
{
#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor klasy Dane." << endl;
#endif

	typSzpitala = typ;
	miejscowoscSzpitala = miejsc;
	ulica = ul;
	numerBudynku = nu;
}

void Dane::ZmienTyp(string nowy_typ)
{
	typSzpitala = nowy_typ;
}





Dane::~Dane()
{
#ifdef _DEBUG
	cout << "Zosta³ wyywolany destruktor klasy Dane." << endl;
#endif
}


ostream & operator << (ostream &s, Dane &d)
{
	s << "Dane o szpitalu: " << endl << "Szpital " << d.typSzpitala << " w " << d.miejscowoscSzpitala << endl << " na ulicy " << d.ulica << " " << d.numerBudynku << endl;
	return s;
}


