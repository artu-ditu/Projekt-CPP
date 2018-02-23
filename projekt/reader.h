#pragma once
#ifndef reader
#define reader
#include "stdafx.h"
#include "generator.h"
#include <string>

using namespace std;

class Reader {
public:
	void wypiszPublikacje(Generator *gen);
	void wypiszProze(Generator *gen);
	void wypiszAlbumy(Generator *gen);
	void wypiszMiesieczniki(Generator *gen);
	void wypiszTygodniki(Generator *gen);
	void wypiszAutorow(Generator *gen);
	void wypiszUmowy(Generator *gen);
	void wypiszPrace(Generator *gen);
	void wypiszDzielo(Generator *gen);
	void wypiszZlecenia(Generator *gen);
	void wypiszDrukarnie(Generator *gen);
	void wypiszZleceniaStd1(Generator *gen);
	void wypiszZleceniaStd2(Generator *gen);
	void wypiszZleceniaAlbum(Generator *gen);
	void wypisz_plik(std::string nazwa);
};

#endif