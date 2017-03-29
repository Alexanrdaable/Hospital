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
	cout << "Konstruktor klasy Szpital." << endl;
#endif

}

Szpital::Szpital(string nazwa_Szpitala, int liczba_Pacjentow)
{
	int liczbaPacjentow = 0;
	pacjenci = new Pacjent[liczbaPacjentow];
	parametry = Parametry();
	dane = Dane();

	string nazwaSzpitala = nazwa_Szpitala;
	int liczbaOddzialow = 1;

	liczbaPacjentow = liczba_Pacjentow;

	liczbaSzpitali++;

#ifdef _DEBUG
	cout << "Konstruktor klasy Szpital z parametrami." << endl;
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
	cout << "Konstruktor kopiujacy klasy Szpital." << endl;
#endif

}

void Szpital::UstawNazwe(string nazwa)
{
	this->nazwaSzpitala = nazwa; 			
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

	Pacjent *tempPacjent = new Pacjent[liczbaPacjentow + 1];			

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

bool Szpital::operator>(const Szpital &s)			//czy wiekszy szpital
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
		cout << "Probujesz znalezc nieistniejacego pacjenta." << endl;
	}	
}



Szpital::~Szpital()
{
	delete[]pacjenci;
	
#ifdef _DEBUG
	cout << "Destruktor klasy Szpital." << endl;
#endif
}



bool operator==(const Szpital &d1, const Szpital &d2)
{
	if (d1.nazwaSzpitala == d2.nazwaSzpitala && d1.liczbaPacjentow == d2.liczbaPacjentow && d1.liczbaOddzialow == d2.liczbaOddzialow)
		return true;
	else
		return false;
}