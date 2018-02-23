#include "stdafx.h"
#include "drukarnia.h"

//drukarnia

Drukarnia::Drukarnia() {
}

Drukarnia::Drukarnia(std::string nazwa, bool czyAlbum) {
	this->nazwa = nazwa;
	this->czyAlbum = 0;
}

Drukarnia::Drukarnia(std::string nazwa, std::vector<Zlecenie*> zlecenia, bool czyAlbum) {
	this->nazwa = nazwa;
	this->zlecenia = zlecenia;
	this->czyAlbum = 0;
}

void Drukarnia::dodajZlecenie(Zlecenie *zle) {
	zlecenia.push_back(zle);
}

std::vector<Zlecenie*> Drukarnia::getZlecenia() {
	return this->zlecenia;
}

void Drukarnia::zmienZlecenia(std::vector<Zlecenie*> nowe) {
	this->zlecenia = nowe;
}

bool Drukarnia::getAlbum() {
	return this->czyAlbum;
}

std::string Drukarnia::getNazwa() {
	return this->nazwa;
}

//drukarnia albumowa

DrukAlbum::DrukAlbum() {
}

DrukAlbum::DrukAlbum(std::string nazwa, bool czyAlbum) {
	this->nazwa = nazwa;
	this->czyAlbum = 1;
}

DrukAlbum::DrukAlbum(std::string nazwa, std::vector<Zlecenie*> zlecenia, bool czyAlbum) {
	this->nazwa = nazwa;
	this->zlecenia = zlecenia;
	this->czyAlbum = 1;
}