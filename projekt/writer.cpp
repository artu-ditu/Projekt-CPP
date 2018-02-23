#include "stdafx.h"
#include "writer.h"

void Writer::zapiszPublikacje(Generator *gen) {

	ofstream plik("ePress_publikacje.txt", fstream::out | fstream::app);

	if (plik.is_open()) {
		for (int i = 0; i < gen->getePress().getPublikacje().size(); i++) {
			plik << gen->getePress().getPublikacje().at(i)->getNazwa() << "\n\t" 
				<< gen->getePress().getPublikacje().at(i)->getData() << "\t" 
				<< gen->getePress().getPublikacje().at(i)->getGatunek() << "\t" 
				<< gen->getePress().getPublikacje().at(i)->getStrony() << "\t"
				<< gen->getePress().getPublikacje().at(i)->getCena() << "\t" << "\n"
				<< gen->getePress().getPublikacje().at(i)->getAutor()->getImie() << "\n" 
				<< gen->getePress().getPublikacje().at(i)->getAutor()->getNazwisko() << "\n\t" 
				<< gen->getePress().getPublikacje().at(i)->getAutor()->getWiek() << "\t" 
				<< gen->getePress().getPublikacje().at(i)->getAutor()->getPlec() << "\n\n";
		}

		plik.close();
	}
}

void Writer::zapiszAutorow(Generator *gen) {

	ofstream plik("ePress_autorzy.txt", fstream::out | fstream::app);

	if (plik.is_open()) {

		for (int i = 0; i < gen->getePress().getAutorzy().size(); i++) {
			plik << gen->getePress().getAutorzy().at(i)->getImie() << "\n"
				<< gen->getePress().getAutorzy().at(i)->getNazwisko() << "\n\t"
				<< gen->getePress().getAutorzy().at(i)->getPlec() << "\t"
				<< gen->getePress().getAutorzy().at(i)->getWiek() << "\n\n";
		}

		plik.close();
	}
}

void Writer::zapiszUmowy(Generator *gen) {

	ofstream plik("ePress_umowy.txt", fstream::out | fstream::app);

	if (plik.is_open()) {

		for (int i = 0; i < gen->getePress().getUmowy().size(); i++) {
			plik << gen->getePress().getUmowy().at(i)->getAutor()->getImie() << "\n"
				<< gen->getePress().getUmowy().at(i)->getAutor()->getNazwisko() << "\n\t"
				<< gen->getePress().getUmowy().at(i)->getAutor()->getPlec() << "\t"
				<< gen->getePress().getUmowy().at(i)->getAutor()->getWiek() << "\t"
				<< gen->getePress().getUmowy().at(i)->getTyp() << "\n\n";
		}

		plik.close();
	}
}

void Writer::zapiszZlecenia(Generator *gen) {

	ofstream plik("ePress_zlecenia_wszystkie.txt", fstream::out | fstream::app);

	if (plik.is_open()) {

		for (int i = 0; i < gen->getePress().getZlecenia().size(); i++) {
			plik << gen->getePress().getZlecenia().at(i)->getPublikacja()->getNazwa() << "\n"
				<< gen->getePress().getZlecenia().at(i)->getNaklad() << "\n\t"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getData() << "\t"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getGatunek() << "\t"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getStrony() << "\t"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getCena() << "\t" << "\n"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getAutor()->getImie() << "\n"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getAutor()->getNazwisko() << "\n\t"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getAutor()->getWiek() << "\t"
				<< gen->getePress().getZlecenia().at(i)->getPublikacja()->getAutor()->getPlec() << "\n\n";
		}

		plik.close();
	}
}

void Writer::zapiszZleceniaStd1(Generator *gen) {

	ofstream plik("ePress_zlecenia_std1.txt", fstream::out | fstream::app);

	if (plik.is_open()) {

		for (int i = 0; i < gen->getePress().getDrukStd1().getZlecenia().size(); i++) {
			plik << gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getNazwa() << "\n"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getNaklad() << "\n\t"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getData() << "\t"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getGatunek() << "\t"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getStrony() << "\t"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getCena() << "\t" << "\n"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getAutor()->getImie() << "\n"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getAutor()->getNazwisko() << "\n\t"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getAutor()->getWiek() << "\t"
				<< gen->getePress().getDrukStd1().getZlecenia().at(i)->getPublikacja()->getAutor()->getPlec() << "\n\n";
		}

		plik.close();
	}
}

void Writer::zapiszZleceniaStd2(Generator *gen) {

	ofstream plik("ePress_zlecenia_std2.txt", fstream::out | fstream::app);

	if (plik.is_open()) {

		for (int i = 0; i < gen->getePress().getDrukStd2().getZlecenia().size(); i++) {
			plik << gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getNazwa() << "\n"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getNaklad() << "\n\t"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getData() << "\t"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getGatunek() << "\t"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getStrony() << "\t"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getCena() << "\t" << "\n"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getAutor()->getImie() << "\n"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getAutor()->getNazwisko() << "\n\t"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getAutor()->getWiek() << "\t"
				<< gen->getePress().getDrukStd2().getZlecenia().at(i)->getPublikacja()->getAutor()->getPlec() << "\n\n";
		}

		plik.close();
	}
}

void Writer::zapiszZleceniaAlbum(Generator *gen) {

	ofstream plik("ePress_zlecenia_album.txt", fstream::out | fstream::app);

	if (plik.is_open()) {

		for (int i = 0; i < gen->getePress().getDrukAlbum().getZlecenia().size(); i++) {
			plik << gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getNazwa() << "\n"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getNaklad() << "\n\t"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getData() << "\t"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getGatunek() << "\t"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getStrony() << "\t"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getCena() << "\t" << "\n"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getAutor()->getImie() << "\n"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getAutor()->getNazwisko() << "\n\t"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getAutor()->getWiek() << "\t"
				<< gen->getePress().getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getAutor()->getPlec() << "\n\n";
		}

		plik.close();
	}
}