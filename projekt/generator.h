#pragma once
#ifndef generator
#define generator
#include "stdafx.h"
#include "wydawnictwo.h"
#include "los.h"
#include <iostream>
#include <fstream>
#include <sstream>

class Generator {
private:
	Wydawnictwo ePress;
public:
	std::string wybor_pliku();
	Wydawnictwo getePress();
	void stworz_plik();
	void wczytaj_publikacje(std::string nazwa);
	void wczytaj_autorow(std::string nazwa);
	void wczytaj_umowy(std::string nazwa);
	void wczytaj_zlecenia(std::string nazwa);
	void dodaj_publikacje();
	void usun_publikacje();
	void dodaj_autora();
	void usun_autora();
	void dodaj_umowe();
	void usun_umowe();
	void dodaj_zlecenie();
	void usun_zlecenie();
	void zmien_nazwe_drukarni();
	void generuj_ksiazki();
	void generuj_czasopisma();
	void generuj_autorow();
	void generuj_umowy();
	void generuj_zlecenia();
};

#endif
