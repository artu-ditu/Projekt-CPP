#include "stdafx.h"
#include "zlecenie.h"

//zlecenie

Zlecenie::Zlecenie() {
}

Zlecenie::Zlecenie(Publikacja *pub, int naklad) {
	this->pub = pub;
	this->naklad = naklad;
}

Publikacja* Zlecenie::getPublikacja() {
		return this->pub;
	}

int Zlecenie::getNaklad() {
		return this->naklad;
	}