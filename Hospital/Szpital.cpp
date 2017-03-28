#include "Szpital.h"
#include <iostream>
#include<string>
using namespace std;


int Szpital::liczbaSzpitali = 0;

int Szpital::wypisz_liczbaSzpitali()
{
	return liczbaSzpitali;
}


Szpital::Szpital()
{
	int liczbaPacjentow = 0;
	pacjenci = new Pacjent[liczbaPacjentow];

	string nazwaSzpitala = "Bielanski";
	int liczbaOddzialow = 1;

	liczbaSzpitali++;

#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor klasy Szpital" << endl;
#endif

}

Szpital::Szpital(string _nazwaSzpitala, int _liczbaPacjentow)
{
	int liczbaPacjentow = 0;
	pacjenci = new Pacjent[liczbaPacjentow];
	parametry = Parametry();
	dane = Dane();

	string nazwaSzpitala = _nazwaSzpitala;
	int liczbaOddzialow = 1;

	liczbaPacjentow = _liczbaPacjentow;

	liczbaSzpitali++;

#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor klasy Szpital z parametrami" << endl;
#endif

}

Szpital::Szpital(Szpital &szpital)
{
	liczbaPacjentow = szpital.liczbaPacjentow;
	nazwaSzpitala = szpital.nazwaSzpitala;
	liczbaOddzialow = szpital.liczbaOddzialow;
	parametry = szpital.parametry;
	dane = szpital.dane;

	pacjenci = new Pacjent[liczbaPacjentow];

	for (int i = 0; i < liczbaPacjentow; i++)
	{
		pacjenci[i] = szpital.pacjenci[i];
	}

#ifdef _DEBUG
	cout << "Zosta³ wyywolany konstruktor kopiujacy klasy Szpital" << endl;
#endif

}

void Szpital::UstawNazwe(string nazwa)
{
	this->nazwaSzpitala = nazwa; 			//wskazuje na obiekt dla ktorego zostala wywolana metoda
}


void Szpital::UstawLiczbeOddzialow(int liczba_oddzialow)
{
	this->liczbaOddzialow = liczba_oddzialow;
}

void Szpital::UstawParametry(Parametry p)
{
	this->parametry = p;
}
void Szpital::UstawDane(Dane d)
{
	this->dane = d;
}

Dane Szpital::PobierzDane() {
	return this->dane;
}

Pacjent Szpital::PobierzPacjenta() {
	return this->pacjenci[0];
}

void Szpital::DodajPacjenta(string imie, string nazwisko, int nr, int lo)
{
	Pacjent nowyPacjent = Pacjent(imie, nazwisko, nr, lo);

	Pacjent *tempPacjent = new Pacjent[liczbaPacjentow + 1];			//wskaznik, przypisac pamiec, dodac nowy, wywalic, wrzucic nowy wsk

	for (int i = 0; i < liczbaPacjentow; i++)
		tempPacjent[i] = pacjenci[i];


	delete[] pacjenci;
	pacjenci = tempPacjent;
	pacjenci[liczbaPacjentow] = nowyPacjent;

	liczbaPacjentow++;
}


Parametry Szpital::ilesal()
{
	return this->parametry;
}


//operator przypisana 
Szpital& Szpital::operator=(const Szpital &s)
{
	int liczbaPacjentow = s.liczbaPacjentow;
	string nazwaSzpitala = s.nazwaSzpitala;
	int liczbaOddzialow = s.liczbaOddzialow;

	return *this;
}

bool Szpital::operator>(const Szpital &s)			//ze jest wiekszy szpital
{
	if ((liczbaOddzialow > s.liczbaOddzialow) || (liczbaPacjentow > s.liczbaPacjentow))
	{
		return true;
	}
	else {
		return false;
	}
}

bool Szpital::operator==(const Szpital &d)
{
	if (d.nazwaSzpitala == nazwaSzpitala && d.liczbaPacjentow == liczbaPacjentow && d.liczbaOddzialow == liczbaOddzialow)
	{
		return true;
	}
	else {
		return false;
	}
}


Pacjent& Szpital::operator[](int i)
{
	if (i >= 0 && i < liczbaPacjentow)
		return pacjenci[i];
	else
	{
		cout << "Znajdujesz sie poza zakresem liczby pacjentow." << endl;
	}	
}

//void Szpital::dodajPacjenta(const Pacjent &pacjent)			//spr
//{
//	Pacjent *temp;
//
//	temp = new Pacjent[liczbaPacjentow];
//	for (int i = 0; i < liczbaPacjentow; i++)
//		temp[i] = pacjenci[i];
//
//	temp[liczbaPacjentow] = pacjent;
//	delete[] pacjenci;
//	pacjenci = temp;
//
//	liczbaPacjentow++;
//
//}

Szpital::~Szpital()
{
	delete[]pacjenci;
	//liczbaSzpitali--;
#ifdef _DEBUG
	cout << "Zosta³ wyywolany destruktor klasy Szpital" << endl;
#endif
}



bool operator==(const Szpital &d1, const Szpital &d2)
{
	if (d1.nazwaSzpitala == d2.nazwaSzpitala && d1.liczbaPacjentow == d2.liczbaPacjentow && d1.liczbaOddzialow == d2.liczbaOddzialow)
		return true;
	else
		return false;
}