#define _CRT_SECURE_NO_WARNINGS


#include <iostream>
#include <time.h>
#include "Kasyno.h"

Kasyno::Kasyno()
	:liczbaGraczy()
{
	for (int i = 0;i < 52;)
	{
		for (int k = 0;k < 4;k++) // petla ustalajaca kolory
		{
			talia[i].setKolor(k);
			i++;
		}
	}

	for (int i = 0;i < 52;)
	{
		for (int w = 0;w < 13;w++) // petla ustalajaca wartosci
		{
			talia[i].setWartosc(w);
			i++;
		}
	}

	for (int i = 0;i < 2;i++)
	{
		char nazwa[20];
		liczbaGraczy[i].setGdzieJestem(this);
		std::cout << "Podaj nick " << i + 1 << ". gracza: ";
		std::cin >> nazwa;
		liczbaGraczy[i].setNazwa(nazwa);
	}
}

void Kasyno::wyswietlTalie()
{
	for (int i = 0;i < 52;i++)
			talia[i].wyswietlKarte();
}

void Kasyno::potasujTalie()
{
	Karta temp;
	srand(time(NULL));

	for (int i = 0;i <100;i++)
	{

		int n = rand()%51;

		temp = talia[n];
		//std::cout << n << std::endl;
		//temp.wyswietlKarte();
		
		int j = n;
		for (j;j < 52;j++)
			{
				talia[j] = talia[j+1];
			}
		talia[51] = temp;
	}
}

Karta* Kasyno::dajKarte()
{
	if ((liczbaGraczy[0].getIleWReku()<10)||(liczbaGraczy[1].getIleWReku()))
		return &talia[wydane++];
}

void Kasyno::graj(int _g)
{
	bool grajDalej = true;
	bool n = true;
	int wybor;

	while (grajDalej == true)
	{

		potasujTalie();
		dodajBota();

		Karta *temp1;

		for (int i = 1;i <= _g;i++)
		{
			temp1 = dajKarte();
			liczbaGraczy[0].wezKarte(temp1);

			temp1 = dajKarte();
			liczbaGraczy[1].wezKarte(temp1);

			for (int j = 0;j < liczbaBotow;j++)
			{
				temp1 = dajKarte();
				boty[j].wezKarte(temp1);
			}
		}

		if (liczbaGraczy[0].getIlePunktow() >= 21)
			liczbaGraczy[0].PasujlubDobierz(true);

		if (liczbaGraczy[1].getIlePunktow() >= 21)
			liczbaGraczy[1].PasujlubDobierz(true);

		for (int j = 0;j < liczbaBotow;j++)
		{
				boty[j].PasujlubDobierz();
		}

		while ((liczbaGraczy[0].getCzyPas() == false) || (liczbaGraczy[1].getCzyPas() == false))
		{
			system("cls");

			std::cout << "--- " << liczbaGraczy[0].getNazwa() << " ---" << std::endl;
			liczbaGraczy[0].pokazKarty();
			

			std::cout << "--- " << liczbaGraczy[1].getNazwa() << " ---" << std::endl;
			liczbaGraczy[1].pokazKarty();

			for (int j = 0;j < liczbaBotow;j++)
			{
				std::cout << "--- " << boty[j].getNazwa() << " ---" << std::endl;
				boty[j].pokazKarty();
			}

			if ((liczbaGraczy[0].getCzyPas() == false) && (liczbaGraczy[1].getCzyPas() == false))
			{
				for (int i = 0;i < 2;i++)
				{
					std::cout << liczbaGraczy[i].getNazwa() << " co robisz? ";
					liczbaGraczy[i].PasujlubDobierz();

					if (liczbaGraczy[i].getCzyPas() == true)
					{
						std::cout << liczbaGraczy[i].getNazwa() << " pasuje." << std::endl << std::endl;
					}

					else if (liczbaGraczy[i].getCzyPas() == false)
					{
						std::cout << liczbaGraczy[i].getNazwa() << " dobiera." << std::endl << std::endl;
						temp1 = dajKarte();
						liczbaGraczy[i].wezKarte(temp1);
						
						if (liczbaGraczy[i].getIlePunktow() >= 21)
							liczbaGraczy[i].PasujlubDobierz(true);
					}
				}
			}

			else if ((liczbaGraczy[0].getCzyPas() == false))
			{
				std::cout << liczbaGraczy[0].getNazwa() << " co robisz? ";
				liczbaGraczy[0].PasujlubDobierz();

				if (liczbaGraczy[0].getCzyPas() == true)
				{
					std::cout << liczbaGraczy[0].getNazwa() << " pasuje." << std::endl << std::endl;
				}

				else if (liczbaGraczy[0].getCzyPas() == false)
				{
					std::cout  << liczbaGraczy[0].getNazwa() << " dobiera." << std::endl << std::endl;
					temp1 = dajKarte();
					liczbaGraczy[0].wezKarte(temp1);

					if (liczbaGraczy[0].getIlePunktow() >= 21)
						liczbaGraczy[0].PasujlubDobierz(true);
				}

			}

			else if ((liczbaGraczy[1].getCzyPas() == false))
			{
				std::cout << liczbaGraczy[1].getNazwa() << " co robisz? ";
				liczbaGraczy[1].PasujlubDobierz();

				if (liczbaGraczy[1].getCzyPas() == true)
				{
					std::cout << liczbaGraczy[1].getNazwa() << " pasuje." << std::endl << std::endl;
				}

				else if (liczbaGraczy[1].getCzyPas() == false)
				{
					std::cout<< liczbaGraczy[1].getNazwa() <<  " dobiera." << std::endl << std::endl;
					temp1 = dajKarte();
					liczbaGraczy[1].wezKarte(temp1);

					if (liczbaGraczy[1].getIlePunktow() >= 21)
						liczbaGraczy[1].PasujlubDobierz(true);
				}
			}

			for (int j = 0;j < liczbaBotow;j++)
			{
				boty[j].PasujlubDobierz();

				if (boty[j].czyPas == false)
				{
					temp1 = dajKarte();
					boty[j].wezKarte(temp1);
				}
			}
		}

			do {
				for (int j = 0;j < liczbaBotow;j++)
				{
					boty[j].PasujlubDobierz();

					if (boty[j].czyPas == false)
					{
						temp1 = dajKarte();
						boty[j].wezKarte(temp1);
						n = false;
					}
					else
						n = true;
				}
			} while (n == false);

		system("cls");


		std::cout << "--- " << liczbaGraczy[0].getNazwa() << " ---" << std::endl;
		liczbaGraczy[0].pokazKarty();
		std::cout << "--- " << liczbaGraczy[1].getNazwa() << " ---" << std::endl;
		liczbaGraczy[1].pokazKarty();

		for (int j = 0;j < liczbaBotow;j++)
		{
			std::cout << "--- " << boty[j].getNazwa() << " ---" << std::endl;
			boty[j].pokazKarty();
		}

		wskazZwyciezce();
		ZapiszStanGry();

		sprzataniePoGrze();
		std::cout << "Czy chcesz zaczac nowa gre?" << std::endl;
		std::cout << "1. Gram dalej!" << std::endl;
		std::cout << "2. Koniec na dzis." << std::endl;
		std::cin >> wybor;
		system("cls");

		if ((wybor != 1) || (wybor != 2))
		{
			while ((wybor != 1) && (wybor != 2))
			{
				std::cin.clear();
				std::cin.ignore(256, '\n');
				std::cout << "Blad, dokonaj wyboru ponownie." << std::endl;
				std::cin >> wybor;
			}
		}

	if (wybor == 1)
		{
			grajDalej = true;
		}

	else if (wybor == 2)
		{
			grajDalej = false;
		}

	}

}

void Kasyno::wskazZwyciezce()
{
	bool n=false;
	setTablicaPunktow();

	tablicaPunktow[0] = liczbaGraczy[0].getIlePunktow();
	tablicaPunktow[1] = liczbaGraczy[1].getIlePunktow();

	for (int j = 2;j < (liczbaBotow+2); j++)
	{
		tablicaPunktow[j] = boty[j - 2].getIlePunktow();
	}

	for (int i = 0;i < (liczbaBotow + 2);i++)
	{

		 if (tablicaPunktow[i] == 21)
		{
			 n = true;

			 if (i < 2)
			 {
				 std::cout << liczbaGraczy[i].getNazwa() << " wygrywa!" << std::endl<<std::endl;
			 }
			 else
				 std::cout << boty[i-2].getNazwa() << " wygrywa!" << std::endl<<std::endl;	
			 
		
		}

		else if (tablicaPunktow[i] < 21)
		{
			if (n==false)
			{
				if (tablicaPunktow[i] == punktyMax())
				{
					if (i < 2)
					{
						std::cout << liczbaGraczy[i].getNazwa() << " wygrywa!" <<std::endl<< std::endl;
					}
					else
						std::cout << boty[i - 2].getNazwa() << " wygrywa!" << std::endl<<std::endl;
				}
			}
		}
	}



/*
	// wszystkie przegrane
	if (pkt1 > 21)
		std::cout << liczbaGraczy[0].getNazwa() << " przegrywa!" << std::endl;

	 if (pkt2 > 21)
		std::cout << liczbaGraczy[1].getNazwa() << " przegrywa!" << std::endl;

	 if (pktBotow[0] > 21)
		std::cout << boty[0].getNazwa() << " przegrywa!" << std::endl;

	 if (pktBotow[1] > 21)
		std::cout << boty[1].getNazwa() << " przegrywa!" << std::endl;

	 if (pktBotow[2] > 21)
		std::cout << boty[2].getNazwa() << " przegrywa!" << std::endl;

	//wszystkie wygrane
	 if (pkt1 = 21)
		std::cout << liczbaGraczy[0].getNazwa() << " wygrywa!" << std::endl;

	 if (pkt2 = 21)
		std::cout << liczbaGraczy[1].getNazwa() << " wygrywa!" << std::endl;

	 if (pktBotow[0] = 21)
		std::cout << boty[0].getNazwa() << " wygrywa!" << std::endl;

	 if (pktBotow[1] = 21)
		std::cout << boty[1].getNazwa() << " wygrywa!" << std::endl;

	 if (pktBotow[2] = 21)
		std::cout << boty[2].getNazwa() << " wygrywa!" << std::endl;

	//mieszane
	 if ((pkt1<21)>((pkt2<21)||(pktBotow[0]<21)||(pktBotow[1]<21)||(pktBotow[2]<21))) //wygrywa gracz 1.
		std::cout << liczbaGraczy[0].getNazwa() << " wygrywa!" << std::endl;
	
	 if ((pkt2<21)>((pkt1<21) || (pktBotow[0]<21) || (pktBotow[1]<21) || (pktBotow[2]<21))) //wygrywa gracz 2.
		 std::cout << liczbaGraczy[1].getNazwa() << " wygrywa!" << std::endl;

	 if ((pktBotow[0]<21)>((pkt2<21) || (pkt1<21) || (pktBotow[1]<21) || (pktBotow[2]<21))) //wygrywa bot 1.
		 std::cout << boty[0].getNazwa() << " wygrywa!" << std::endl;

	 if ((pktBotow[1]<21)>((pkt2<21) || (pkt1<21) || (pktBotow[0]<21) || (pktBotow[2]<21))) //wygrywa bot 2.
		 std::cout << boty[1].getNazwa() << " wygrywa!" << std::endl;

	 if ((pktBotow[2]<21)>((pkt2<21) || (pkt1<21) || (pktBotow[1]<21) || (pktBotow[0]<21))) //wygrywa bot 3.
		 std::cout << boty[2].getNazwa() << " wygrywa!" << std::endl;
*/

/*
	 if ((21-pkt1>0)&&(pkt2<=21))
	{
		std::cout << liczbaGraczy[0].getNazwa() << " przegrywa!" << std::endl << std::endl;
	
		if (21-pkt2>=0)
			std::cout << "Wygrywa " << liczbaGraczy[1].getNazwa() << "!" << std::endl << std::endl;
	}

	else if ((pkt2 > 21)&&(pkt1<=21))
	{
		std::cout << liczbaGraczy[1].getNazwa() << " przegrywa!" << std::endl << std::endl;

		if (21 - pkt1 >= 0)
			std::cout << "Wygrywa " << liczbaGraczy[0].getNazwa() << "!" << std::endl << std::endl;
	}

	else if (21-pkt1 > 21-pkt2)
		std::cout << "Wygrywa "<<liczbaGraczy[1].getNazwa()<<"!" << std::endl << std::endl;

	else if (21 - pkt1 < 21 - pkt2)
		std::cout << "Wygrywa " << liczbaGraczy[0].getNazwa() << "!" << std::endl << std::endl;

	else if ((21-pkt1>=0)==(21-pkt2>=0))
		std::cout << "Remis!" << std::endl << std::endl;
	 */
}

void Kasyno::sprzataniePoGrze()
{
	for (int i = 0;i < 2;i++)
	{
		liczbaGraczy[i].~Gracz();
	}
	wydane = 0;
	
	for (int j = 0;j < liczbaBotow;j++)
		boty[j].~Bot();

	delete[] boty;
	potasujTalie();
}

void Kasyno::ZapiszStanGry()
{
	std::fstream plik;
	plik.open("stan_gry.csv", std::fstream::app);

	for (int i = 0;i < 2;i++)
	{
		plik << liczbaGraczy[i].getNazwa();
		
		for (int j = 0; j<liczbaGraczy[i].getIleWReku();j++)
		{
			plik << ","<< liczbaGraczy[i].wReku[j]->getFigura() << liczbaGraczy[i].wReku[j]->getKolor();
		}
		plik << "," << liczbaGraczy[i].getIlePunktow() << "\n";
	}

	for (int i = 0;i < liczbaBotow;i++)
	{
		plik << boty[i].getNazwa();

		for (int j = 0; j<boty[i].getIleWReku();j++)
		{
			plik << "," << boty[i].wReku[j]->getFigura() << boty[i].wReku[j]->getKolor();
		}
		plik << "," << boty[i].getIlePunktow() << "\n";
	}

	plik.close();
}

void Kasyno::dodajBota()
{
	int wybor;

	std::cout << "Podaj liczbe botow [0-3]: ";
	std::cin >> wybor;

	if ((wybor != 0) || (wybor != 1) || (wybor != 2) || (wybor !=3))
	{
		std::cin.clear();
		std::cin.ignore(256, '\n');


		while ((wybor != 0) && (wybor != 1) && (wybor != 2) && (wybor != 3))
		{
			std::cout << "Blad, dokonaj wyboru ponownie." << std::endl;
			std::cin >> wybor;
			std::cin.clear();
			std::cin.ignore(256, '\n');
		}
	}

	boty = new Bot[wybor];
	
	switch (wybor)
	{
	case 3: 
		boty[0].setNazwa("Bot 1.");
		boty[0].ustawStylGry();
		boty[1].setNazwa("Bot 2.");
		boty[1].ustawStylGry();
		boty[2].setNazwa("Bot 3.");
		boty[2].ustawStylGry();
		break;
	case 2:
		boty[0].setNazwa("Bot 1.");
		boty[0].ustawStylGry();
		boty[1].setNazwa("Bot 2.");
		boty[1].ustawStylGry();
		break;
	case 1:
		boty[0].setNazwa("Bot 1.");
		boty[0].ustawStylGry();
	default:
		break;
	}

	liczbaBotow = wybor;
}

void Kasyno::setTablicaPunktow()
{
	tablicaPunktow = new int[2 + liczbaBotow];
}

int Kasyno::punktyMax()
{
	int max = 0;
	int *temp = new int[liczbaBotow + 2];

	for (int i = 0;i < (liczbaBotow + 2);i++)
	{
		temp[i] = tablicaPunktow[i];
	}


	for (int i = 0;i < (liczbaBotow + 2);i++)
	{
		if (temp[i] >= 21)
		{
			temp[i] = 0;
		}
	}

	for (int i = 0;i < (liczbaBotow + 2);i++)
	{
		if (max < temp[i])
			max = temp[i];
	}

	delete[] temp;
	return max;
}

Kasyno::~Kasyno()
{
	for (int i = 0;i < (liczbaBotow+2);i++)
	{
		tablicaPunktow[i] = 0;
	}
}
