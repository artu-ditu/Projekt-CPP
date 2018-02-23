#pragma once
#ifndef  los
#define los
#include "stdafx.h"
#include <iostream>
#include <string>
#include <string.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

class Los {
public:
	int LosujLiczbe(int zakres, int minimum);
	string LosujKsiazke();
	string LosujGatunek();
	string LosujCzasopismo();
	string LosujImie(string plec);
	string LosujNazwisko(string plec);
};

#endif
