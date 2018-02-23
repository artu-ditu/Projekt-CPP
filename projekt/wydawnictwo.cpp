#include "stdafx.h"
#include "wydawnictwo.h"

//wydawnictwo

void Wydawnictwo::dodajPublikacje(Publikacja *pub) {
	publikacje.push_back(pub);
}

void Wydawnictwo::dodajZlecenie(Zlecenie *zle) {
	zlecenia.push_back(zle);
}

void Wydawnictwo::dodajDoDrukuStd1(Zlecenie *zle) {
	standard1.dodajZlecenie(zle);
}

void Wydawnictwo::dodajDoDrukuStd2(Zlecenie *zle) {
	standard2.dodajZlecenie(zle);
}

void Wydawnictwo::dodajDoDrukuAlbum(Zlecenie *zle) {
	albumowa.dodajZlecenie(zle);
}

void Wydawnictwo::dodajUmowe(Umowa *umo) {
	bool obecnosc = false;
	for (int i = 0; i < getUmowy().size(); i++)
		if (getUmowy().at(i)->getAutor()->getNazwisko() == umo->getAutor()->getNazwisko() && getUmowy().at(i)->getAutor()->getImie() == umo->getAutor()->getImie()) {
			obecnosc = true;
			break;
		}
	if (!obecnosc) umowy.push_back(umo);
}

void Wydawnictwo::dodajAutora(Autor *aut) {
	bool obecnosc = false;
	for (int i = 0; i < getAutorzy().size(); i++)
			if (getAutorzy().at(i)->getNazwisko() == aut->getNazwisko() && getAutorzy().at(i)->getImie() == aut->getImie()) {
				obecnosc = true;
				break;
			}
	if(!obecnosc) autorzy.push_back(aut);
}

std::vector<Publikacja*> Wydawnictwo::getPublikacje() {
	return this->publikacje;
}

std::vector<Umowa*> Wydawnictwo::getUmowy() {
	return this->umowy;
}

Drukarnia Wydawnictwo::getDrukStd1() {
	return this->standard1;
}

Drukarnia Wydawnictwo::getDrukStd2() {
	return this->standard2;
}

DrukAlbum Wydawnictwo::getDrukAlbum() {
	return this->albumowa;
}

std::vector<Autor*> Wydawnictwo::getAutorzy() {
	return autorzy;
}

std::vector<Zlecenie*> Wydawnictwo::getZlecenia() {
	return zlecenia;
}

void Wydawnictwo::zmienPublikacje(std::vector<Publikacja*> nowe) {
	this->publikacje = nowe;
}

void Wydawnictwo::zmienAutorzy(std::vector<Autor*> nowe) {
	this->autorzy = nowe;
}

void Wydawnictwo::zmienUmowy(std::vector<Umowa*> nowe) {
	this->umowy = nowe;
}

void Wydawnictwo::zmienZlecenia(std::vector<Zlecenie*> nowe) {
	this->zlecenia = nowe;
}

void Wydawnictwo::zmienDrukarnieStd1(Drukarnia nowe) {
	this->standard1 = nowe;
}

void Wydawnictwo::zmienDrukarnieStd2(Drukarnia nowe) {
	this->standard2 = nowe;
}

void Wydawnictwo::zmienDrukarnieAlbum(DrukAlbum nowe) {
	this->albumowa = nowe;
}