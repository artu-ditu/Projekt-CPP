#include "stdafx.h"
#include "reader.h"

void Reader::wypiszPublikacje(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getPublikacje().size(); i++)
		cout << gen->getePress().getPublikacje().at(i)->getNazwa() << endl;
}

void Reader::wypiszProze(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getPublikacje().size(); i++)
		if (gen->getePress().getPublikacje().at(i)->getTyp() == 'p')
			cout << gen->getePress().getPublikacje().at(i)->getNazwa() << endl;
}

void Reader::wypiszAlbumy(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getPublikacje().size(); i++)
		if (gen->getePress().getPublikacje().at(i)->getTyp() == 'a')
			cout << gen->getePress().getPublikacje().at(i)->getNazwa() << endl;

}

void Reader::wypiszMiesieczniki(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getPublikacje().size(); i++)
		if (gen->getePress().getPublikacje().at(i)->getTyp() == 'm')
			cout << gen->getePress().getPublikacje().at(i)->getNazwa() << endl;

}

void Reader::wypiszTygodniki(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getPublikacje().size(); i++)
		if (gen->getePress().getPublikacje().at(i)->getTyp() == 't')
			cout << gen->getePress().getPublikacje().at(i)->getNazwa() << endl;

}

void Reader::wypiszAutorow(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getAutorzy().size(); i++)
		cout << gen->getePress().getAutorzy().at(i)->getImie() << "\t" << gen->getePress().getAutorzy().at(i)->getNazwisko() << endl;
}

void Reader::wypiszUmowy(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getUmowy().size(); i++)
		cout << gen->getePress().getUmowy().at(i)->getAutor()->getImie() << "\t" << gen->getePress().getUmowy().at(i)->getAutor()->getNazwisko() << endl;
}

void Reader::wypiszPrace(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getUmowy().size(); i++)
		if (gen->getePress().getUmowy().at(i)->getTyp() == 'p')
			cout << gen->getePress().getUmowy().at(i)->getAutor()->getImie() << "\t" << gen->getePress().getUmowy().at(i)->getAutor()->getNazwisko() << endl;
}

void Reader::wypiszDzielo(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getUmowy().size(); i++)
		if (gen->getePress().getUmowy().at(i)->getTyp() == 'd')
			cout << gen->getePress().getUmowy().at(i)->getAutor()->getImie() << "\t" << gen->getePress().getUmowy().at(i)->getAutor()->getNazwisko() << endl;
}

void Reader::wypiszZlecenia(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getZlecenia().size(); i++) {
		cout << endl << gen->getePress().getZlecenia().at(i)->getPublikacja()->getNazwa() << endl;
		cout << "\t" << gen->getePress().getZlecenia().at(i)->getPublikacja()->getAutor()->getImie() << "\t" << gen->getePress().getZlecenia().at(i)->getPublikacja()->getAutor()->getNazwisko() << endl;
	}
	
}

void Reader::wypiszDrukarnie(Generator *gen) {
	cout << endl;
	cout << "Drukarnia standardowa nr 1: " << gen->getePress().getDrukStd1().getNazwa() << endl;
	cout << "Drukarnia standardowa nr 2: " << gen->getePress().getDrukStd2().getNazwa() << endl;
	cout << "Drukarnia albumowa: " << gen->getePress().getDrukAlbum().getNazwa() << endl;
}

void Reader::wypiszZleceniaStd1(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getDrukStd1().getZlecenia().size(); i++)
		cout << gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getNazwa() << endl;
}

void Reader::wypiszZleceniaStd2(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getDrukStd2().getZlecenia().size(); i++)
		cout << gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getNazwa() << endl;
}

void Reader::wypiszZleceniaAlbum(Generator *gen) {
	cout << endl;
	for (int i = 0; i < gen->getePress().getDrukAlbum().getZlecenia().size(); i++)
		cout << gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getNazwa() << endl;
}

void Reader::wypisz_plik(string nazwa) {
	ifstream plik(nazwa);
	string linia;
	cout << endl;
	while (getline(plik, linia)) {
		cout << linia << endl;
	}
	plik.close();
}