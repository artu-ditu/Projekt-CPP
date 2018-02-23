#include "stdafx.h"
#include "publikacja.h"

//publikacja

Publikacja::Publikacja() {
}

Publikacja::Publikacja(std::string naz, std::string dat, int str, float cen) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
}

std::string Publikacja::getNazwa() {
	return this->nazwa;
}

int Publikacja::getStrony() {
	return this->liczba_stron;
}

std::string Publikacja::getData() {
	return this->data_wydania;
}

float Publikacja::getCena() {
	return this->cena;
}

char Publikacja::getTyp() {
	return this->typ;
}

void Publikacja::zmienAutora(Autor *aut) {
	this->_autor = aut;
}

Autor* Publikacja::getAutor() {
	return this->_autor;
}

std::string Publikacja::getGatunek() {
	return this->gatunek;
}

//ksiazka

Ksiazka::Ksiazka() {
}

Ksiazka::Ksiazka(std::string naz, std::string dat, int str, float cen, std::string gatunek) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
	this->gatunek = gatunek;
}

//czasopismo

Czasopismo::Czasopismo() {
}

Czasopismo::Czasopismo(std::string naz, std::string dat, int str, float cen, std::string gatunek) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
	this->gatunek = gatunek;
}

//album

Album::Album() {
}

Album::Album(std::string naz, std::string dat, int str, float cen, std::string gatunek) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
	this->gatunek = gatunek;
	this->typ = 'a';
}

//proza

Proza::Proza() {
}

Proza::Proza(std::string naz, std::string dat, int str, float cen, std::string gatunek) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
	this->gatunek = gatunek;
	this->typ = 'p';
}

//miesiecznik

Miesiecznik::Miesiecznik() {
}

Miesiecznik::Miesiecznik(std::string naz, std::string dat, int str, float cen, std::string gatunek) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
	this->gatunek = gatunek;
	this->typ = 'm';
}

//tygodnik

Tygodnik::Tygodnik() {
}

Tygodnik::Tygodnik(std::string naz, std::string dat, int str, float cen, std::string gatunek) {
	this->nazwa = naz;
	this->data_wydania = dat;
	this->liczba_stron = str;
	this->cena = cen;
	this->gatunek = gatunek;
	this->typ = 't';
}