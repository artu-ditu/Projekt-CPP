#pragma once
#ifndef autor
#define autor
#include "stdafx.h"
#include <iostream>
#include <string>

class Autor {
private:
	std::string imie;
	std::string nazwisko;
	std::string plec;
	int rok_urodzenia;
public:
	Autor();
	Autor(std::string imie, std::string nazwisko, std::string plec, int rok_urodzenia);
	std::string getPlec();
	int getWiek();
	std::string getImie();
	std::string getNazwisko();
};

#endif