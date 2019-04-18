#pragma once
#include "Karta.h"
//#include "Kasyno.h"
#include <iostream>
#include<string>

class Kasyno;

class Gracz
{
	friend class Kasyno;

protected:
	int ileWReku; 
	int ilePunktow; 
	Karta *wReku[10]; 
	Kasyno* gdzieJestem;
	bool czyPas=false;
	char nazwa[20];

public:
	Gracz();
	void Gracz::wezKarte(Karta * _karta); 
	void Gracz::pokazKarty();
	void Gracz::naReceile();
	void Gracz::setGdzieJestem(Kasyno* _gdzie);
	void Gracz::PasujlubDobierz();
	void Gracz::PasujlubDobierz(bool);
	bool Gracz::getCzyPas();
	int Gracz::getIlePunktow();
	void Gracz::setNazwa(char _nazwa[20]);
	char* Gracz::getNazwa();
	int Gracz::getIleWReku();

	~Gracz();
};

