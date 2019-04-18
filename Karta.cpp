#include "Karta.h"

const char kolory[] = { 'k', 'd', 't', 'p' };
const char figury[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'D', 'J', 'Q', 'K', 'A' };
const int wartosci[] = { 2,   3,   4,   5,   6,   7 ,  8,   9,  10,   2,   3,   4,  11 };

Karta::Karta(int _kolor, int _wartosc) {
	setKolor(_kolor);
	setWartosc(_wartosc);
}

void Karta::setKolor(int _kolor) {
	if (_kolor < 4) {
		kolor = kolory[_kolor];
	}
}

void Karta::setWartosc(int _wartosc) {
	if (_wartosc < 14) {
		figura = figury[_wartosc];
		wartosc = wartosci[_wartosc];
	}
}

void Karta::wyswietlKarte()
{

	std::cout << "Figura karty: " << figura<< std::endl;
	std::cout << "Kolor karty: " << kolor<< std::endl << std::endl;
}
/*
Karta Karta::operator<<(Karta)
{
	plik << figura << kolor;
}
*/