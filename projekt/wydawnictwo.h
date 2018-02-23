#pragma once
#ifndef wydawnictwo
#define wydawnictwo
#include "stdafx.h"
#include <iostream>
#include <vector>
#include "drukarnia.h"
#include "umowa.h"
#include "publikacja.h"

class Wydawnictwo {
private:
	std::vector<Publikacja*> publikacje;
	std::vector<Umowa*> umowy;
	DrukAlbum albumowa;
	Drukarnia standard1, standard2;
	std::vector<Autor*> autorzy;
	std::vector<Zlecenie*> zlecenia;
public:
	void dodajPublikacje(Publikacja *pub);
	void dodajUmowe(Umowa *umo);
	void dodajAutora(Autor *aut);
	void dodajZlecenie(Zlecenie *zle);
	void dodajDoDrukuStd1(Zlecenie *zle);
	void dodajDoDrukuStd2(Zlecenie *zle);
	void dodajDoDrukuAlbum(Zlecenie *zle);
	std::vector<Publikacja*> getPublikacje();
	std::vector<Umowa*> getUmowy();
	Drukarnia getDrukStd1();
	Drukarnia getDrukStd2();
	DrukAlbum getDrukAlbum();
	std::vector<Autor*> getAutorzy();
	std::vector<Zlecenie*> getZlecenia();
	void zmienPublikacje(std::vector<Publikacja*> nowe);
	void zmienAutorzy(std::vector<Autor*> nowe);
	void zmienUmowy(std::vector<Umowa*> nowe);
	void zmienZlecenia(std::vector<Zlecenie*> nowe);
	void zmienDrukarnieStd1(Drukarnia nowe);
	void zmienDrukarnieStd2(Drukarnia nowe);
	void zmienDrukarnieAlbum(DrukAlbum nowe);
};


#endif // wydawnictwo
