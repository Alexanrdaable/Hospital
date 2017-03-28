#pragma once
#include <string>
using namespace std;

class Dane
{
private:
	string typSzpitala;
	string miejscowoscSzpitala;
	string ulica;
	int numerBudynku;

public:
	Dane();
	Dane(string typ, string miejsc, string ul, int nu);
	~Dane();
	void ZmienTyp(string nowy_typ);

	
	friend ostream& operator << (ostream &s, Dane &d);
};


