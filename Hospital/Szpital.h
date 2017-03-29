#pragma once
#include "Pacjent.h"
#include "Dane.h"
#include "Parametry.h"
using namespace std;

class Szpital
{
private:
	
	Dane dane;
	Parametry parametry;
	Pacjent *pacjenci;
	static int liczbaSzpitali;
	string nazwaSzpitala;
	int liczbaPacjentow;
	int liczbaOddzialow;

public:
	
	Szpital();	//konst.
	Szpital(string _nazwaSzpitala, int _liczbaPacjentow);
	Szpital(Szpital &szpital);	//konst. kopiujacy														
	~Szpital();	//dest.
	
	Parametry ilesal();
	static int wypisz_liczbaSzpitali();
	void UstawNazwe(string nazwa);
	void UstawLiczbeOddzialow(int liczba_oddzialow);
	void UstawParametry(Parametry &p);
	void UstawDane(Dane &d);
	Dane PobierzDane();
	Pacjent PobierzPacjenta();

	void DodajPacjenta(string imie, string nazwisko, int nr, int lo);
	
	//operatory
	bool operator>(const Szpital &s);    
	Szpital& operator=(const Szpital &s);
	Pacjent& operator[](int i);

	bool operator==(const Szpital &d);
	friend bool operator==(const Szpital &d1, const Szpital &d2);

};