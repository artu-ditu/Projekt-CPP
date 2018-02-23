#pragma once
#ifndef umowa
#define umowa
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include "autor.h"

class Umowa {
protected:
	Autor *aut;
	char typ;
public:
	Umowa();
	Umowa(Autor *aut);
	Autor* getAutor();
	char getTyp();
};

class Praca : public Umowa {
public:
	Praca();
	Praca(Autor *aut);
};

class Dzielo : public Umowa {
public:
	Dzielo();
	Dzielo(Autor *aut);
};

#endif // umowa
