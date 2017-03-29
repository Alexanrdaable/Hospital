#include "Pacjent.h"
#include <iostream>

using namespace std;

Pacjent::Pacjent()
{
#ifdef _DEBUG
	cout << "Konstruktor klasy Pacjent." << endl;
#endif
	string imie = "Jan";
	string nazwisko ="Kowalski";
	int nrPacjenta = 1;
	int liczbaObjawow = 0;
}

Pacjent::Pacjent(int liczba)
{
#ifdef _DEBUG
	cout << "Konstruktor klasy Pacjent." << endl;
#endif
	string imie = "Jan";
	string nazwisko = "Kowalski";
	int nrPacjenta = 1;
	liczbaObjawow = liczba;
}

Pacjent::Pacjent(string imie, string nazwisko, int numer, int liczbaObjawow)
{
	this->imie = imie;
	this->nazwisko = nazwisko;
	this->nrPacjenta = numer;
	this->liczbaObjawow = liczbaObjawow;

#ifdef _DEBUG
	cout << "Konstruktor klasy Pacjent z parametrami." << endl;
#endif
}

bool Pacjent::StanZdrowia()
{
	if (liczbaObjawow = 0)
		return true;
	else
		return false;
}

int Pacjent::PobierzIloscObjawow() {
	return liczbaObjawow;
}

Pacjent Pacjent::operator++(int)
{
	Pacjent kopia(*this);
	liczbaObjawow++;
	cout << "Stan zdrowia sie pogorszyl." << endl;
	return kopia;
}

Pacjent Pacjent::operator--(int)
{
	if (liczbaObjawow > 0)
	{
		Pacjent kopia(*this);
		liczbaObjawow--;
		cout << "Stan zdrowia sie poprawil." << endl;
		return kopia;
	}
	else
		cout << " Stan zdrowia: Pacjent ca³kowicie zdrowy." << endl;
	
}

Pacjent::operator string() const
{
	string l_o;
	if (liczbaObjawow > 0)
	{
		l_o = " Stan zdrowia: Pacjent jest chory.";
	}
	else
		l_o = " Stan zdrowia: Pacjent jest zdrowy.";

	return imie + " " + nazwisko + " " + l_o;

}


Pacjent::~Pacjent()
{
#ifdef _DEBUG
	cout << "Destruktor klasy Pacjent." << endl;
#endif
}


ostream & operator << (ostream &s, Pacjent &p)
{
	s << endl << "Dane pacjenta: " << endl << p.imie << " " << p.nazwisko << endl << "Nr pacjenta:  " << p.nrPacjenta << endl << "Liczba objawow choroby: " << p.liczbaObjawow << endl;
	return s;
}
