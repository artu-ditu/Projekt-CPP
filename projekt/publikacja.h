#pragma once
#ifndef publikacja
#define publikacja
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "autor.h"

class Publikacja {
protected:
	std::string nazwa;
	int liczba_stron;
	std::string data_wydania;
	float cena;
	Autor* _autor;
	char typ;
	std::string gatunek;
public:
	Publikacja();
	Publikacja(std::string naz, std::string dat, int str, float cen);
	std::string getNazwa();
	int getStrony();
	std::string getData();
	float getCena();
	void zmienAutora(Autor *aut);
	Autor* getAutor();
	char getTyp();
	std::string getGatunek();
};

class Ksiazka : public Publikacja {
protected:
public:
	Ksiazka();
	Ksiazka(std::string naz, std::string dat, int str, float cen, std::string gatunek);
};

class Czasopismo : public Publikacja {
protected:
public:
	Czasopismo();
	Czasopismo(std::string naz, std::string dat, int str, float cen, std::string gatunek);
};

class Album : public Ksiazka {
public:
	Album();
	Album(std::string naz, std::string dat, int str, float cen, std::string gatunek);
};

class Proza : public Ksiazka {
public:
	Proza();
	Proza(std::string naz, std::string dat, int str, float cen, std::string gatunek);
};

class Tygodnik : public Czasopismo {
public:
	Tygodnik();
	Tygodnik(std::string naz, std::string dat, int str, float cen, std::string gatunek);
};

class Miesiecznik : public Czasopismo {
public:
	Miesiecznik();
	Miesiecznik(std::string naz, std::string dat, int str, float cen, std::string gatunek);
};

#endif // publikacja