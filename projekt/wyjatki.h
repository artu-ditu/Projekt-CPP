#pragma once
#ifndef wyjatki
#define wyjatki
#include "stdafx.h"
#include <string>

using namespace std;

class Wyjatek : public exception {
	string message;
public:
	Wyjatek() {}
	Wyjatek(string msg) : message(msg) {}
	string getMessage();
};

class UjemnaLiczbaStronWyjatek : public Wyjatek {
	int val;
public:
	UjemnaLiczbaStronWyjatek(int v) : val(v) {}
	UjemnaLiczbaStronWyjatek(string msg, int v) : Wyjatek(msg), val(v) {}
	int getVal();
};

class UjemnaCenaWyjatek : public Wyjatek {
	float val;
public:
	UjemnaCenaWyjatek(float v) : val(v) {}
	UjemnaCenaWyjatek(string msg, float v) : Wyjatek(msg), val(v) {}
	float getVal();
};

class NieprawidlowyWiekWyjatek : public Wyjatek {
	int val;
public:
	NieprawidlowyWiekWyjatek(int v) : val(v) {}
	NieprawidlowyWiekWyjatek(string msg, int v) : Wyjatek(msg), val(v) {}
	int getVal();
};

#endif