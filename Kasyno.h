#pragma once
#include <fstream>
#include "Karta.h"
#include "Gracz.h"
#include "Bot.h"

class Gracz;

class Kasyno
{
private:
	int wydane=0;
	int liczbaBotow;
	Karta talia[52];
	Gracz liczbaGraczy[2];
	Bot *boty = nullptr;
	int *tablicaPunktow = nullptr;

public:
	Kasyno();
	void Kasyno::wyswietlTalie();
	void Kasyno::potasujTalie(); 
	Karta* Kasyno::dajKarte();
	void Kasyno::graj(int);
	void Kasyno::wskazZwyciezce();
	void Kasyno::sprzataniePoGrze();
	void Kasyno::ZapiszStanGry(); 
	void Kasyno::dodajBota();
	void Kasyno::setTablicaPunktow();
	int Kasyno::punktyMax();
	~Kasyno();
};

