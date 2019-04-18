#include "Gracz.h"


Gracz::Gracz()
{
	ileWReku = 0;
	ilePunktow = 0;
}

void Gracz::naReceile()
{
	std::cout << ileWReku << std::endl;
}

void Gracz::wezKarte(Karta * _karta)
{
	int n = 0;
	if (ileWReku < 10)
	{
		wReku[ileWReku++] = _karta;

		n = _karta->getWartosc();
		ilePunktow += n;
	}
	else
		std::cout << "Masz juz 10 kart!"<<std::endl;
}

void Gracz::pokazKarty()
{
	for (int i = 1;i <= ileWReku;i++)
		wReku[i - 1]->wyswietlKarte();


	std::cout << "Kart w reku: " << ileWReku << std::endl;
	std::cout << "Liczba punktow: " << ilePunktow << std::endl << std::endl;
}

void Gracz::setGdzieJestem(Kasyno* _gdzie)
{
	gdzieJestem = _gdzie;
}

void Gracz::PasujlubDobierz()
{
	int wybor = 0;

	std::cout << "Pasujesz czy dobierasz?" << std::endl;
	std::cout << "1. Dobieram" << std::endl;
	std::cout << "2. Pasuje" << std::endl;

	std::cin >> wybor;

	if ((wybor != 1) || (wybor != 2))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');

		while ((wybor != 1) && (wybor != 2))
		{
			std::cout << "Blad, dokonaj wyboru ponownie." << std::endl;
			std::cin >> wybor;
			std::cin.clear();
			std::cin.ignore(256, '\n');

		}
	}

	if (wybor == 1)
	{
		czyPas = false;
	}

	else if (wybor == 2)
	{
		czyPas = true;
	}
}

void Gracz::PasujlubDobierz(bool _i)
{
	czyPas = _i;
}

bool Gracz::getCzyPas()
{
	return czyPas;
}

int Gracz::getIlePunktow()
{
	return ilePunktow;
}

void Gracz::setNazwa(char _nazwa[20])
{
	for (int i = 0;i < 20;i++)
	{
		if (_nazwa[i] == '\0')
		{
			nazwa[i] = '\0';
			break;
		}
		
		nazwa[i] = _nazwa[i];
	}
}

char* Gracz::getNazwa()
{
	return nazwa;
}

int Gracz::getIleWReku()
{
	return ileWReku;
}

Gracz::~Gracz()
{
	ilePunktow = 0;
	ileWReku = 0;
	czyPas = false;
	for (int i = 0;i < 10;i++)
	{
		wReku[i] = 0;
	}
}
