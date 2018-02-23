#pragma once
#ifndef writer
#define writer
#include "stdafx.h"
#include "generator.h"

using namespace std;

class Writer {
public:
	void zapiszPublikacje(Generator *gen);
	void zapiszAutorow(Generator *gen);
	void zapiszUmowy(Generator *gen);
	void zapiszZlecenia(Generator *gen);
	void zapiszZleceniaStd1(Generator *gen);
	void zapiszZleceniaStd2(Generator *gen);
	void zapiszZleceniaAlbum(Generator *gen);
};

#endif