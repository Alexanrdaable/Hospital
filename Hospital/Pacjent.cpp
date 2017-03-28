#include "Pacjent.h"
#include <iostream>

using namespace std;

Pacjent::Pacjent()
{
#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor klasy Pacjent." << endl;
#endif
	string imie = "Jan";
	string nazwisko ="Kowalski";
	int nrPacjenta = 1;
	int liczbaObjawow = 0;
}

Pacjent::Pacjent(int liczba)
{
#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor klasy Pacjent." << endl;
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
	cout << "wywolano konstruktor z parametrem klasy Pacjent" << endl;
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
	return kopia;
}

Pacjent Pacjent::operator--(int)
{
	if (liczbaObjawow > 0)
		liczbaObjawow--;
	else
		cout << "Pacjent ca³kowicie zdrowy." << endl;
	return *this;
}

Pacjent::operator string() const
{
	string l_o;
	if (liczbaObjawow > 0)
	{
		l_o = "Pacjent jest chory";
	}
	else
		l_o = "Pacjent jest zdrowy";

	return imie + " " + nazwisko + " " + l_o;

}


Pacjent::~Pacjent()
{
#ifdef _DEBUG
	cout << "Zosta³ wyywolany destruktor klasy Pacjent" << endl;
#endif
}


ostream & operator << (ostream &s, Pacjent &p)
{
	s << "Dane pacjenta: " << endl << p.imie << " " << p.nazwisko << endl << "Nr pacjenta:  " << p.nrPacjenta << endl << "Liczba objawow choroby: " << p.liczbaObjawow << endl;
	return s;
}
