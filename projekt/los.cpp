#include "stdafx.h"
#include "los.h"

//los

int Los::LosujLiczbe(int zakres, int minimum) {
	int x = rand() % zakres + minimum;
	return x;
}

string Los::LosujKsiazke() {
	ifstream plik("lista_publikacji_ksiazki.txt");
	string nazwa;
	vector<string> nazwy;

	while (true) {
		getline(plik, nazwa);
		nazwy.push_back(nazwa);
		if (plik.good());
		else break;
	}
	plik.close();

	int p = LosujLiczbe(nazwy.size(), 1);

	return nazwy.at(p-1);
}

string Los::LosujCzasopismo() {
	ifstream plik("lista_publikacji_czasopisma.txt");
	string nazwa;
	vector<string> nazwy;

	while (true) {
		getline(plik, nazwa);
		nazwy.push_back(nazwa);
		if (plik.good());
		else break;
	}
	plik.close();

	int p = LosujLiczbe(nazwy.size(), 1);

	return nazwy.at(p - 1);
}

string Los::LosujGatunek() {
	ifstream plik("lista_gatunki_ksiazki.txt");
	string gatunek;
	vector<string> gatunki;

	while (true) {
		getline(plik, gatunek);
		gatunki.push_back(gatunek);
		if (plik.good());
		else break;
	}
	plik.close();

	int p = LosujLiczbe(gatunki.size(), 1);

	return gatunki.at(p-1);
}

string Los::LosujImie(string plec) {
	string nazwa_pliku = "lista_imiona_";
	nazwa_pliku += plec;
	nazwa_pliku += ".txt";
	ifstream plik(nazwa_pliku);
	string imie;
	vector<string> imiona;

	while (true) {
		getline(plik, imie);
		imiona.push_back(imie);
		if (plik.good());
		else break;
	}
	plik.close();

	int p = LosujLiczbe(imiona.size(), 1);

	return imiona.at(p-1);
}

string Los::LosujNazwisko(string plec) {
	ifstream plik("lista_nazwiska.txt");
	string nazwisko;
	vector<string> nazwiska;

	while (true) {
		getline(plik, nazwisko);
		nazwiska.push_back(nazwisko);
		if (plik.good());
		else break;
	}
	plik.close();

	int p = LosujLiczbe(nazwiska.size(), 1);

	nazwisko = nazwiska.at(p-1);
	char tmp[100];

	strcpy(tmp, nazwisko.c_str());

	bool ski = strstr(tmp, "ski") != 0;
	bool cki = strstr(tmp, "cki") != 0;

	string _nazwisko(tmp);

	if (plec == "k" && ski == true) {
		_nazwisko.erase(_nazwisko.length() - 3, _nazwisko.length() - 1);
		_nazwisko += "ska";
	}

	if (plec == "k" && cki == true) {
		_nazwisko.erase(_nazwisko.length() - 3, _nazwisko.length() - 1);
		_nazwisko += "cka";
	}

	return _nazwisko;
}