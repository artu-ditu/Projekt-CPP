#include "stdafx.h"
#include "autor.h"

//autor

Autor::Autor() {
}

Autor::Autor(std::string im, std::string nazw, std::string pl, int rok_ur) {
	this->imie = im;
	this->nazwisko = nazw;
	this->plec = pl;
	this->rok_urodzenia = rok_ur;
}

std::string Autor::getPlec() {
		return this->plec;
	}

int Autor::getWiek() {
		return this->rok_urodzenia;
	}
	
std::string Autor::getImie() {
		return this->imie;
	}
	
std::string Autor::getNazwisko() {
		return this->nazwisko;
	}