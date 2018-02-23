#include "stdafx.h"
#include "umowa.h"

//umowa

Umowa::Umowa() {
}

Autor* Umowa::getAutor() {
	return this->aut;
}

Umowa::Umowa(Autor *aut) {
	this->aut = aut;
}

char Umowa::getTyp() {
	return this->typ;
}

//umowa o prace

Praca::Praca() {
}

Praca::Praca(Autor *aut) {
	this->aut = aut;
	this->typ = 'p';
}

//umowa o dzielo

Dzielo::Dzielo() {
}

Dzielo::Dzielo(Autor *aut) {
	this->aut = aut;
	this->typ = 'd';
}
