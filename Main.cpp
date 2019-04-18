#include <iostream>
#include "Kasyno.h"


int main()
{
	Kasyno k1;

	/*
	k1.wyswietlTalie();

	k1.potasujTalie();
	std::cout << "---------------------TASOWANIE----------------------" << std::endl;
	k1.wyswietlTalie();
	*/

	std::cout << "----------------GRAJ--------------------------" << std::endl<<std::endl;

	k1.graj(2); // okresla ile kart na wstepie rozdac graczom

	std::cin.get();
	system("pause");
	return 0;
}