#include "Parametry.h"
#include <iostream>
#include<math.h>

using namespace std;

Parametry::Parametry()
{
#ifdef _DEBUG
	cout << "Konstruktor klasy Parametry." << endl;
#endif
	szerokosc_sali = 0;
	dlugosc_sali = 0;
	szerokosc_lozka = 0;
	iloscSal = 0;
}

Parametry::Parametry(int s, int d, int sz, int i)
{
#ifdef _DEBUG
	cout << "Konstruktor klasy Parametry z parametrem." << endl;
#endif
	szerokosc_sali = s;
	dlugosc_sali = d;
	szerokosc_lozka = sz;
	iloscSal = i;
}

int Parametry::ilesal()
{
	return this->iloscSal;

}


Parametry & Parametry::operator+(const Parametry &p)
{
	int il;
	Parametry s;
	il = this->iloscSal;
	s.iloscSal = il + p.iloscSal;
	return s;

}



Parametry::~Parametry()
{
#ifdef _DEBUG
	cout << "Destruktor klasy Parametry." << endl;
#endif
}




