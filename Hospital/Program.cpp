// Hospital.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Dane.h"
#include "Pacjent.h"
#include "Parametry.h"	
#include "Szpital.h"
#include <iostream>
using namespace std;

//test szpital: >, =, wypisz dane
//test dane:  << wypisz dane
//test pacjent: ++, -- , wypisz, konwersja,[]
//test parametry: +ilosc sal  

void test_operatory_Dane(Szpital S1)
{
	cout << endl << "Test wypisywania danych: " << endl;
	cout << S1.PobierzDane() << endl;
}

void test_operatory_Szpital(Szpital S1, Szpital S2)
{
	cout << endl << "Porownuje dwa szpitale pod wzgledem wielkosci, test > : " << endl;
	if (S1 > S2)
	{
		cout << "Szpital pierwszy jest wiekszy, poniewaz ma wiecej oddzialow." << endl;
		cout << endl;
	}

	else
	{
		cout << "Szpital pierwszy ma mniej oddzialow i jest mniejszy." << endl;
		cout << endl;
	}
}

void test_operator_porownania_Szpital(Szpital S1, Szpital S2)
{
	cout << endl << "Porownujemy dwa szpitale:" << endl;

	if (S1 == S2)
	{
		cout << "Porownujesz dwa takie same szpitale." << endl;
	}
	else
	{
		cout << "Szpital S1 jest innym szpitalem niz S2." << endl;
	}
	cout << endl;
}

void test_operatory_Parametry(Szpital S1, Szpital S2)
{
	Parametry p = Parametry(10, 10, 1, 5);
	Parametry p2 = S2.ilesal();			
	Parametry suma = p + p2;
	cout << endl << "Test operatora dodawania: " << endl;
	cout << endl << "Liczba sal pierwszego szpitala: " << p.ilesal() << endl;
	cout << "Liczba sal drugiego szpitala: " << p2.ilesal() << endl;
	cout << "Po sumowaniu: " << suma.ilesal() << endl;
	cout << endl;

}

void test_operator_indeksowania(Szpital S1) {
	Pacjent pacjent = S1[0];

	cout << endl << "Test operatora indeksowania: " << endl << pacjent << endl;
}

void test_operator_inkrementacji_dekrementacji_Pacjent(Pacjent pacjent)
{

	cout << endl << "Liczba przed zwiekszeniem ilosci chorob: " << pacjent.PobierzIloscObjawow() << endl;

	pacjent++;

	cout << endl << "Liczba po zwiekszeniu ilosci chorob: " << pacjent.PobierzIloscObjawow() << endl;

	cout << endl << "Leczymy pacjenta! " << endl;

	pacjent--;

	cout << endl <<  "Liczba po zmniejszeniu ilosci chorob: " << pacjent.PobierzIloscObjawow() << endl;

	cout << endl <<  "Test operatora konwersji konwersji obiektu na string: " << endl << (string)pacjent << endl;

	cout << endl <<  "Test operatora wypisywania dla pacjenta:  " << endl << pacjent << endl;

	cout << endl;
}



int main()
{

	Szpital S1;
	S1.UstawNazwe("Bielanski");
	S1.UstawLiczbeOddzialow(5);
	S1.DodajPacjenta("Jan", "Kowalski", 1, 5);
	S1.UstawDane(Dane("Ogolny", "Warszawa", "Pilsudskiego", 7));
	S1.UstawParametry(Parametry(50, 100, 50, 5));

	Szpital S2;
	S2.UstawNazwe("Centralny");
	S2.UstawLiczbeOddzialow(3);
	S2.DodajPacjenta("Krzysztof", "Kowalski", 1, 0);
	S2.UstawDane(Dane("Specjalistyczny", "Warszawa", "AK", 7));
	S2.UstawParametry(Parametry(70, 90, 70, 55));


	test_operatory_Parametry(S1, S2);
	test_operatory_Szpital(S1, S2);
	test_operator_porownania_Szpital(S1, S2);
	test_operatory_Dane(S1);
	test_operator_indeksowania(S1);

	Pacjent pacjent = S2.PobierzPacjenta();
	test_operator_inkrementacji_dekrementacji_Pacjent(pacjent);


	cout << "Liczba utworzonych szpitali: " << Szpital::wypisz_liczbaSzpitali() << endl;

	int end;
	cin >> end;
	return 0;
}

