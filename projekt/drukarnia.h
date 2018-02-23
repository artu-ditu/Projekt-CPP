#pragma once
#ifndef drukarnia
#define drukarnia
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "zlecenie.h"

class Drukarnia {
protected:
	std::string nazwa;
	std::vector<Zlecenie*> zlecenia;
	bool czyAlbum;
public:
	Drukarnia();
	Drukarnia(std::string nazwa, bool czyAlbum);
	Drukarnia(std::string nazwa, std::vector<Zlecenie*> zlecenia, bool czyAlbum);
	void dodajZlecenie(Zlecenie *zle);
	std::vector<Zlecenie*> getZlecenia();
	bool getAlbum();
	std::string getNazwa();
	void zmienZlecenia(std::vector<Zlecenie*> nowe);
};

class DrukAlbum : public Drukarnia {
public:
	DrukAlbum();
	DrukAlbum(std::string nazwa, bool czyAlbum);
	DrukAlbum(std::string nazwa, std::vector<Zlecenie*> zlecenia, bool czyAlbum);
};

#endif // drukarnia

