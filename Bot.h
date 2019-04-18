#pragma once
#include "Gracz.h"
class Bot :
	public Gracz
{
	int stylGry;
public:
	Bot();
	void ustawStylGry();
	int getStylGry();
	void PasujlubDobierz();
	~Bot();
};

