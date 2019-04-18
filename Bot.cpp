#include "Bot.h"



Bot::Bot()
{
}

void Bot::ustawStylGry()
{
	int wybor = 0;

	std::cout << "Ustal styl gry bota: " << std::endl<<std::endl;
	std::cout << "1. Zachowawanczy" << std::endl;
	std::cout << "2. Normalny" << std::endl;
	std::cout << "3. Ryzykowny" << std::endl;

	std::cin >> wybor;

	if ((wybor != 1) || (wybor != 2)||(wybor!=3))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');

		while ((wybor != 1) && (wybor != 2)&& (wybor != 3))
		{
			std::cout << "Blad, dokonaj wyboru ponownie." << std::endl;
			std::cin >> wybor;
			std::cin.clear();
			std::cin.ignore(256, '\n');

		}
	}

	if (wybor == 1)
	{
		stylGry = 15;
	}
	else if (wybor == 2)
	{
		stylGry = 17;
	}
	else if (wybor == 3)
	{
		stylGry = 19;
	}

}

int Bot::getStylGry()
{
	return stylGry;
}

void Bot::PasujlubDobierz()
{
	if (ilePunktow <= stylGry)
		czyPas = false;

	else 
		czyPas = true;
}

Bot::~Bot()
{
	ilePunktow = 0;
	ileWReku = 0;
	czyPas = false;
	for (int i = 0;i < 10;i++)
	{
		wReku[i] = 0;
	}
}

