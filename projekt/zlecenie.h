#pragma once
#ifndef zlecenie
#define zlecenie
#include "stdafx.h"
#include <iostream>
#include "publikacja.h"

class Zlecenie {
private:
	Publikacja *pub;
	int naklad;
public:
	Zlecenie();
	Zlecenie(Publikacja *pub, int naklad);
	Publikacja* getPublikacja();
	int getNaklad();
};

#endif // zlecenie
