#include "stdafx.h"
#include "generator.h"
#include "wyjatki.h"

using namespace std;

//generator

Wydawnictwo Generator::getePress() {
	return ePress;
}

string Generator::wybor_pliku() {
	string nazwa;
	cout << endl << "Na ktorym pliku chcesz dzialac?" << endl;
	cin >> nazwa;
	nazwa += ".txt";
	return nazwa;
}

void Generator::stworz_plik() {
	string nazwa;
	cout << endl << "Podaj nazwe pliku:" << endl;
	cin >> nazwa;
	nazwa += ".txt";
	ofstream plik(nazwa);
}

void Generator::wczytaj_publikacje(string nazwa) {
	ifstream plik(nazwa);
	
	char wybor;

	cout << endl;
	cout << "Jakiego typu publikacje chcesz wczytac?" << endl;
	cout << "[1] Proza/poezja" << endl;
	cout << "[2] Album" << endl;
	cout << "[3] Miesiecznik" << endl;
	cout << "[4] Tygodnik" << endl;
	cout << endl;
	cout << "Wybierz opcje:" << endl;
	cin >> wybor;

	string w_nazwa, w_data, w_im_aut, w_nazw_aut, w_plec, w_gatunek;
	int w_liczba_stron, w_rok_ur;
	float w_cena;

	switch (wybor) {
	case '1': {
		while (true) {
			getline(plik, w_nazwa);
			plik >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
			getline(plik, w_im_aut);
			getline(plik, w_nazw_aut);
			plik >> w_rok_ur >> w_plec >> ws;
			Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
			Proza *nowa = new Proza(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			if (plik.good());
			else break;
		}
		plik.close();
		break;
	}
	case '2': {
		while (true) {
			getline(plik, w_nazwa);
			plik >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
			getline(plik, w_im_aut);
			getline(plik, w_nazw_aut);
			plik >> w_rok_ur >> w_plec >> ws;
			Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
			Album *nowa = new Album(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			if (plik.good());
			else break;
		}
		plik.close();
		break;
	}
	case '3': {
		while (true) {
			getline(plik, w_nazwa);
			plik >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
			getline(plik, w_im_aut);
			getline(plik, w_nazw_aut);
			plik >> w_rok_ur >> w_plec >> ws;
			Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
			Miesiecznik *nowa = new Miesiecznik(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			if (plik.good());
			else break;
		}
		plik.close();
		break;
	}
	case '4': {
		while (true) {
			getline(plik, w_nazwa);
			plik >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
			getline(plik, w_im_aut);
			getline(plik, w_nazw_aut);
			plik >> w_rok_ur >> w_plec >> ws;
			Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
			Tygodnik *nowa = new Tygodnik(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			if (plik.good());
			else break;
		}
		plik.close();
		break;
	}
	}
}

void Generator::wczytaj_autorow(string nazwa) {
	ifstream plik(nazwa);

	string w_im_aut, w_nazw_aut, w_plec;
	int w_rok_ur;

	while (true) {
		getline(plik, w_im_aut);
		getline(plik, w_nazw_aut);
		plik >> w_plec >> w_rok_ur >> ws;
		Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
		ePress.dodajAutora(nowy);
		if (plik.good());
		else break;
	}
	plik.close();
}

void Generator::wczytaj_umowy(string nazwa) {
	ifstream plik(nazwa);

	string w_im_aut, w_nazw_aut, w_plec;
	int w_rok_ur;
	char w_typ;

	while (true) {
		getline(plik, w_im_aut);
		getline(plik, w_nazw_aut);
		plik >> w_plec >> w_rok_ur >> w_typ >> ws;
		Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
		switch (w_typ) {
		case 'd': {
			Dzielo *nowa = new Dzielo(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajUmowe(nowa);
		}
		case 'p': {
			Praca *nowa = new Praca(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajUmowe(nowa);
		}
		}
		if (plik.good());
		else break;
	}
	plik.close();
}

void Generator::wczytaj_zlecenia(std::string nazwa) {
	ifstream plik(nazwa);

	string typ;
	char wybor, wybor2, wybordruk;
	cout << endl << "Jakiego typu zlecenia maja zostac dodane?" << endl;
	cout << "[1] albumy" << endl;
	cout << "[2] inne" << endl;
	cin >> wybor;


	string w_nazwa, w_data, w_im_aut, w_nazw_aut, w_plec, w_gatunek;
	int w_liczba_stron, w_rok_ur, w_naklad;
	float w_cena;

	switch (wybor) {
	case '1': {
		while (true) {
			getline(plik, w_nazwa);
			plik >> w_naklad >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
			getline(plik, w_im_aut);
			getline(plik, w_nazw_aut);
			plik >> w_rok_ur >> w_plec >> ws;
			Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
			Album *nowa = new Album(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
			Zlecenie *nowe = new Zlecenie(nowa, w_naklad);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			ePress.dodajZlecenie(nowe);
			ePress.dodajDoDrukuAlbum(nowe);
			if (plik.good());
			else break;
		}
		break;
	}
	case '2': {
		cout << endl;
		cout << "Jakiego typu inne zlecenia chcesz dodac?" << endl;
		cout << "[1] Proza/poezja" << endl;
		cout << "[2] Miesieczniki" << endl;
		cout << "[3] Tygodniki" << endl;
		cin >> wybor2;

		cout << endl << "Ktorej drukarni maja zostac zlecone?" << endl;
		cout << "[1] Standardowa drukarnia nr 1 - " << ePress.getDrukStd1().getNazwa() << endl;
		cout << "[2] Standardowa drukarnia nr 2 - " << ePress.getDrukStd2().getNazwa() << endl;
		cout << "[3] Albumowa drukarnia - " << ePress.getDrukAlbum().getNazwa() << endl;
		cin >> wybordruk;

		switch (wybor2) {
		case '1': {
			while (true) {
				getline(plik, w_nazwa);
				plik >> w_naklad >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
				getline(plik, w_im_aut);
				getline(plik, w_nazw_aut);
				plik >> w_rok_ur >> w_plec >> ws;
				Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
				Proza *nowa = new Proza(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
				Zlecenie *nowe = new Zlecenie(nowa, w_naklad);
				nowa->zmienAutora(nowy);
				ePress.dodajAutora(nowy);
				ePress.dodajPublikacje(nowa);
				ePress.dodajZlecenie(nowe);
				switch (wybordruk) {
				case '1':
					ePress.dodajDoDrukuStd1(nowe);
					break;
				case '2':
					ePress.dodajDoDrukuStd2(nowe);
					break;
				case '3':
					ePress.dodajDoDrukuAlbum(nowe);
					break;
				}
				if (plik.good());
				else break;
			}
			break;
		}
		case '2': {
			while (true) {
				getline(plik, w_nazwa);
				plik >> w_naklad >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
				getline(plik, w_im_aut);
				getline(plik, w_nazw_aut);
				plik >> w_rok_ur >> w_plec >> ws;
				Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
				Miesiecznik *nowa = new Miesiecznik(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
				Zlecenie *nowe = new Zlecenie(nowa, w_naklad);
				nowa->zmienAutora(nowy);
				ePress.dodajAutora(nowy);
				ePress.dodajPublikacje(nowa);
				ePress.dodajZlecenie(nowe);
				switch (wybordruk) {
				case '1':
					ePress.dodajDoDrukuStd1(nowe);
					break;
				case '2':
					ePress.dodajDoDrukuStd2(nowe);
					break;
				case '3':
					ePress.dodajDoDrukuAlbum(nowe);
					break;
				}
				if (plik.good());
				else break;
			}
			break;
		}
		case '3': {
			while (true) {
				getline(plik, w_nazwa);
				plik >> w_naklad >> w_data >> w_gatunek >> w_liczba_stron >> w_cena >> ws;
				getline(plik, w_im_aut);
				getline(plik, w_nazw_aut);
				plik >> w_rok_ur >> w_plec >> ws;
				Autor *nowy = new Autor(w_im_aut, w_nazw_aut, w_plec, w_rok_ur);
				Tygodnik *nowa = new Tygodnik(w_nazwa, w_data, w_liczba_stron, w_cena, w_gatunek);
				Zlecenie *nowe = new Zlecenie(nowa, w_naklad);
				nowa->zmienAutora(nowy);
				ePress.dodajAutora(nowy);
				ePress.dodajPublikacje(nowa);
				ePress.dodajZlecenie(nowe);
				switch (wybordruk) {
				case '1':
					ePress.dodajDoDrukuStd1(nowe);
					break;
				case '2':
					ePress.dodajDoDrukuStd2(nowe);
					break;
				case '3':
					ePress.dodajDoDrukuAlbum(nowe);
					break;
				}
				if (plik.good());
				else break;
			}
			break;
		}
		}
		break;
	}
	}


}

void Generator::dodaj_publikacje() {
	int liczba_stron;
	float cena;
	char nzw[100];
	char dat[100];
	char gat[100];
	char im_a[100];
	char nazw_a[100];
	std::string plec;
	int rok_ur;

	char wybor;

	cout << endl;
	cout << "Jakiego typu publikacje chcesz dodac?" << endl;
	cout << "[1] Proza/poezja" << endl;
	cout << "[2] Album" << endl;
	cout << "[3] Miesiecznik" << endl;
	cout << "[4] Tygodnik" << endl;
	cout << endl;
	cout << "Wybierz opcje:" << endl;
	cin >> wybor;

	cout << endl << "Podaj nazwe:" << endl;
	cin.ignore();
	cin.getline(nzw, sizeof(nzw));

	cout << endl << "Podaj date wydania:" << endl;
	cin.getline(dat, sizeof(dat));

	cout << endl << "Podaj gatunek:" << endl;
	cin.getline(gat, sizeof(gat));

	cout << endl << "Podaj liczbe stron:" << endl;
	cin >> liczba_stron;
	if (liczba_stron < 0)
		throw UjemnaLiczbaStronWyjatek("Publikacja nie moze miec ujemnej liczby stron!", liczba_stron);

	cout << endl << "Podaj cene:" << endl;
	cin >> cena;
	if (cena < 0)
		throw UjemnaCenaWyjatek("Publikacja nie moze miec ujemnej ceny!", cena);

	cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
	cin.ignore();
	cin.getline(im_a, sizeof(im_a));

	cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
	cin.getline(nazw_a, sizeof(nazw_a));

	cout << endl << "Podaj plec autora/redaktora naczelnego (m/k):" << endl;
	cin >> plec;

	cout << endl << "Podaj rok urodzenia autora/redaktora naczelnego:" << endl;
	cin >> rok_ur;
	if (rok_ur > 2016)
		throw NieprawidlowyWiekWyjatek("Autor nie mogl jeszcze sie nie urodzic!", rok_ur);

	string nazwa(nzw);
	string data(dat);
	string gatunek(gat);
	string im_aut(im_a);
	string nazw_aut(nazw_a);

	switch (wybor) {
	case '1': {
		Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
		Proza *nowa = new Proza(nazwa, data, liczba_stron, cena, gatunek);
		nowa->zmienAutora(nowy);
		ePress.dodajAutora(nowy);
		ePress.dodajPublikacje(nowa);
		break;
	}
	case '2': {
		Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
		Album *nowa = new Album(nazwa, data, liczba_stron, cena, gatunek);
		nowa->zmienAutora(nowy);
		ePress.dodajAutora(nowy);
		ePress.dodajPublikacje(nowa);
		break;
	}
	case '3': {
			Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
			Miesiecznik *nowa = new Miesiecznik(nazwa, data, liczba_stron, cena, gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);break;
	}
	case '4': {
		Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
		Tygodnik *nowa = new Tygodnik(nazwa, data, liczba_stron, cena, gatunek);
		nowa->zmienAutora(nowy);
		ePress.dodajAutora(nowy);
		ePress.dodajPublikacje(nowa);break;
	}
	}
}

void Generator::usun_publikacje() {

	char nzw[100];

	cout << endl << "Podaj nazwe:" << endl;
	cin.ignore();
	cin.getline(nzw, sizeof(nzw));

	string nazwa(nzw);

	vector<Publikacja*> temp;

	for (int i = 0; i < ePress.getPublikacje().size(); i++) {
		if (nazwa != ePress.getPublikacje().at(i)->getNazwa())
			temp.push_back(ePress.getPublikacje().at(i));
	}

	ePress.zmienPublikacje(temp);
}

void Generator::dodaj_autora() {
	char im_a[100];
	char nazw_a[100];
	std::string plec;
	int rok_ur;

	cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
	cin.ignore();
	cin.getline(im_a, sizeof(im_a));

	cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
	cin.getline(nazw_a, sizeof(nazw_a));

	cout << endl << "Podaj plec autora/redaktora naczelnego (m/k):" << endl;
	cin >> plec;

	cout << endl << "Podaj rok urodzenia autora/redaktora naczelnego:" << endl;
	cin >> rok_ur;
	if (rok_ur > 2016)
		throw NieprawidlowyWiekWyjatek("Autor nie mogl jeszcze sie nie urodzic!", rok_ur);

	string im_aut(im_a);
	string nazw_aut(nazw_a);

	Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
	ePress.dodajAutora(nowy);
}

void Generator::usun_autora() {

	char im_a[100];
	char nazw_a[100];

	cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
	cin.ignore();
	cin.getline(im_a, sizeof(im_a));

	cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
	cin.getline(nazw_a, sizeof(nazw_a));

	string im_aut(im_a);
	string nazw_aut(nazw_a);

	vector<Autor*> temp;

	for (int i = 0; i < ePress.getAutorzy().size(); i++) {
		if (im_aut == ePress.getAutorzy().at(i)->getImie() && nazw_aut == ePress.getAutorzy().at(i)->getNazwisko());
		else temp.push_back(ePress.getAutorzy().at(i));
	}

	ePress.zmienAutorzy(temp);
}

void Generator::dodaj_umowe() {

	string typ;
	char wybor;
	cout << endl << "Jakiego typu umowa ma zostac dodana?" << endl;
	cout << "[1] umowa o prace" << endl;
	cout << "[2] umowa o dzielo" << endl;
	cout << endl;
	cout << "Wybierz opcje:" << endl;
	cin >> wybor;

	char im_a[100];
	char nazw_a[100];
	std::string plec;
	int rok_ur;

	cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
	cin.ignore();
	cin.getline(im_a, sizeof(im_a));

	cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
	cin.getline(nazw_a, sizeof(nazw_a));

	cout << endl << "Podaj plec autora/redaktora naczelnego (m/k):" << endl;
	cin >> plec;

	cout << endl << "Podaj rok urodzenia autora/redaktora naczelnego:" << endl;
	cin >> rok_ur;
	if (rok_ur > 2016)
		throw NieprawidlowyWiekWyjatek("Autor nie mogl jeszcze sie nie urodzic!", rok_ur);

	string im_aut(im_a);
	string nazw_aut(nazw_a);

	Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
	ePress.dodajAutora(nowy);

	switch (wybor) {
	case '1': {
		Praca *nowa = new Praca(nowy);
		ePress.dodajUmowe(nowa);
		break;
	}
	case '2': {
		Dzielo *nowa = new Dzielo(nowy);
		ePress.dodajUmowe(nowa);
		break;
	}
	}

}

void Generator::usun_umowe() {

	char im_a[100];
	char nazw_a[100];

	cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
	cin.ignore();
	cin.getline(im_a, sizeof(im_a));

	cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
	cin.getline(nazw_a, sizeof(nazw_a));

	string im_aut(im_a);
	string nazw_aut(nazw_a);

	vector<Umowa*> temp;

	for (int i = 0; i < ePress.getUmowy().size(); i++) {
		if (im_aut == ePress.getUmowy().at(i)->getAutor()->getImie() && nazw_aut == ePress.getUmowy().at(i)->getAutor()->getNazwisko());
		else temp.push_back(ePress.getUmowy().at(i));
	}

	ePress.zmienUmowy(temp);

}

void Generator::dodaj_zlecenie() {

	string typ;
	char wybor, wybor2;
	cout << endl << "Jakiego typu publikacja ma zostac dodana?" << endl;
	cout << "[1] album" << endl;
	cout << "[2] inna" << endl;
	cout << endl;
	cout << "Wybierz opcje:" << endl;
	cin >> wybor;

	int liczba_stron;
	float cena;
	char nzw[100];
	char dat[100];
	char gat[100];
	char im_a[100];
	char nazw_a[100];
	std::string plec;
	int rok_ur, naklad;

	switch (wybor) {
	case '1': {
		cout << endl << "Podaj nazwe:" << endl;
		cin.ignore();
		cin.getline(nzw, sizeof(nzw));

		cout << endl << "Podaj date wydania:" << endl;
		cin.getline(dat, sizeof(dat));

		cout << endl << "Podaj gatunek:" << endl;
		cin.getline(gat, sizeof(gat));

		cout << endl << "Podaj liczbe stron:" << endl;
		cin >> liczba_stron;
		if (liczba_stron < 0)
			throw UjemnaLiczbaStronWyjatek("Publikacja nie moze miec ujemnej liczby stron!", liczba_stron);

		cout << endl << "Podaj cene:" << endl;
		cin >> cena;
		if (cena < 0)
			throw UjemnaCenaWyjatek("Publikacja nie moze miec ujemnej ceny!", cena);

		cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
		cin.ignore();
		cin.getline(im_a, sizeof(im_a));

		cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
		cin.getline(nazw_a, sizeof(nazw_a));

		cout << endl << "Podaj plec autora/redaktora naczelnego (m/k):" << endl;
		cin >> plec;

		cout << endl << "Podaj rok urodzenia autora/redaktora naczelnego:" << endl;
		cin >> rok_ur;
		if (rok_ur > 2016)
			throw NieprawidlowyWiekWyjatek("Autor nie mogl jeszcze sie nie urodzic!", rok_ur);

		cout << endl << "Podaj naklad publikacji:" << endl;
		cin >> naklad;

		string nazwa(nzw);
		string data(dat);
		string gatunek(gat);
		string im_aut(im_a);
		string nazw_aut(nazw_a);

		Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
		Album *nowa = new Album(nazwa, data, liczba_stron, cena, gatunek);
		Zlecenie *nowe = new Zlecenie(nowa, naklad);
		nowa->zmienAutora(nowy);
		ePress.dodajAutora(nowy);
		ePress.dodajPublikacje(nowa);
		ePress.dodajZlecenie(nowe);
		ePress.dodajDoDrukuAlbum(nowe);
		break;
	}
	case '2': {
		cout << endl;
		cout << "Jakiego typu inna publikacje chcesz dodac?" << endl;
		cout << "[1] Proza/poezja" << endl;
		cout << "[2] Miesiecznik" << endl;
		cout << "[3] Tygodnik" << endl;
		cout << endl;
		cout << "Wybierz opcje:" << endl;
		cin >> wybor2;

		cout << endl << "Podaj nazwe:" << endl;
		cin.ignore();
		cin.getline(nzw, sizeof(nzw));

		cout << endl << "Podaj date wydania:" << endl;
		cin.getline(dat, sizeof(dat));

		cout << endl << "Podaj gatunek:" << endl;
		cin.getline(gat, sizeof(gat));

		cout << endl << "Podaj liczbe stron:" << endl;
		cin >> liczba_stron;
		if (liczba_stron < 0)
			throw UjemnaLiczbaStronWyjatek("Publikacja nie moze miec ujemnej liczby stron!", liczba_stron);

		cout << endl << "Podaj cene:" << endl;
		cin >> cena;
		if (cena < 0)
			throw UjemnaCenaWyjatek("Publikacja nie moze miec ujemnej ceny!", cena);

		cout << endl << "Podaj imie autora/redaktora naczelnego:" << endl;
		cin.ignore();
		cin.getline(im_a, sizeof(im_a));

		cout << endl << "Podaj nazwisko autora/redaktora naczelnego:" << endl;
		cin.getline(nazw_a, sizeof(nazw_a));

		cout << endl << "Podaj plec autora/redaktora naczelnego (m/k):" << endl;
		cin >> plec;

		cout << endl << "Podaj rok urodzenia autora/redaktora naczelnego:" << endl;
		cin >> rok_ur;

		cout << endl << "Podaj naklad publikacji:" << endl;
		cin >> naklad;

		string nazwa(nzw);
		string data(dat);
		string gatunek(gat);
		string im_aut(im_a);
		string nazw_aut(nazw_a);

		switch (wybor2) {
		case '1': {
			Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
			Proza *nowa = new Proza(nazwa, data, liczba_stron, cena, gatunek);
			Zlecenie *nowe = new Zlecenie(nowa, naklad);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			ePress.dodajZlecenie(nowe);
			ePress.dodajDoDrukuStd1(nowe);
			break;
		}
		case '2': {
			Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
			Miesiecznik *nowa = new Miesiecznik(nazwa, data, liczba_stron, cena, gatunek);
			Zlecenie *nowe = new Zlecenie(nowa, naklad);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			ePress.dodajZlecenie(nowe);
			ePress.dodajDoDrukuStd2(nowe);
			break;
		}
		case '3': {
			Autor *nowy = new Autor(im_aut, nazw_aut, plec, rok_ur);
			Tygodnik *nowa = new Tygodnik(nazwa, data, liczba_stron, cena, gatunek);
			Zlecenie *nowe = new Zlecenie(nowa, naklad);
			nowa->zmienAutora(nowy);
			ePress.dodajAutora(nowy);
			ePress.dodajPublikacje(nowa);
			ePress.dodajZlecenie(nowe);
			ePress.dodajDoDrukuStd2(nowe);
			break;
		}
		}
		break;
	}
	}

}

void Generator::usun_zlecenie() {

	char nzw[100];
	char druk[100];

	cout << endl << "Podaj nazwe publikacji:" << endl;
	cin.ignore();
	cin.getline(nzw, sizeof(nzw));

	string nazwa(nzw);

	vector<Zlecenie*> temp;
	vector<Zlecenie*> tmp1;
	vector<Zlecenie*> tmp2;
	vector<Zlecenie*> tmpA;

	for (int i = 0; i < ePress.getZlecenia().size(); i++) {
		if (nazwa != ePress.getZlecenia().at(i)->getPublikacja()->getNazwa())
			temp.push_back(ePress.getZlecenia().at(i));
	}

	for (int i = 0; i < ePress.getDrukStd1().getZlecenia().size(); i++) {
		if (nazwa != ePress.getDrukStd1().getZlecenia().at(i)->getPublikacja()->getNazwa())
			tmp1.push_back(ePress.getDrukStd1().getZlecenia().at(i));
	}

	for (int i = 0; i < ePress.getDrukStd2().getZlecenia().size(); i++) {
		if (nazwa != ePress.getDrukStd2().getZlecenia().at(i)->getPublikacja()->getNazwa())
			tmp2.push_back(ePress.getDrukStd2().getZlecenia().at(i));
	}

	for (int i = 0; i < ePress.getDrukAlbum().getZlecenia().size(); i++) {
		if (nazwa != ePress.getDrukAlbum().getZlecenia().at(i)->getPublikacja()->getNazwa())
			tmpA.push_back(ePress.getDrukAlbum().getZlecenia().at(i));
	}

	ePress.zmienZlecenia(temp);
	ePress.getDrukStd1().zmienZlecenia(tmp1);
	ePress.getDrukStd2().zmienZlecenia(tmp2);
	ePress.getDrukAlbum().zmienZlecenia(tmpA);
}

void Generator::zmien_nazwe_drukarni() {

	char drukstd1[100];
	char drukstd2[100];
	char drukalbum[100];
	char wybor;

	cout << endl << "Nazwe ktorej drukarni chcesz zmienic?" << endl;
	cout << "[1] Standardowa drukarnia nr 1" << endl;
	cout << "[2] Standardowa drukarnia nr 2" << endl;
	cout << "[3] Albumowa drukarnia" << endl;
	cout << endl;
	cout << "Wybierz opcje:" << endl;
	cin >> wybor;
	switch (wybor) {
	case '1': {
		cout << endl << "Podaj nazwe standardowej drukarni nr 1:" << endl;
		cin.ignore();
		cin.getline(drukstd1, sizeof(drukstd1));
		string nazwa1(drukstd1);
		Drukarnia tmpstd1 = Drukarnia(nazwa1, false);
		for (int i = 0; i < ePress.getDrukStd1().getZlecenia().size(); i++)
			tmpstd1.dodajZlecenie(ePress.getDrukStd1().getZlecenia().at(i));
		ePress.zmienDrukarnieStd1(tmpstd1);
		break;
	}
	case '2': {
		cout << endl << "Podaj nazwe standardowej drukarni nr 2:" << endl;
		cin.ignore();
		cin.getline(drukstd2, sizeof(drukstd2));
		string nazwa2(drukstd2);
		Drukarnia tmpstd2 = Drukarnia(nazwa2, false);
		for (int i = 0; i < ePress.getDrukStd2().getZlecenia().size(); i++)
			tmpstd2.dodajZlecenie(ePress.getDrukStd2().getZlecenia().at(i));
		ePress.zmienDrukarnieStd2(tmpstd2);
		break;
	}
	case '3': {
		cout << endl << "Podaj nazwe albumowej drukarni:" << endl;
		cin.ignore();
		cin.getline(drukalbum, sizeof(drukalbum));
		string nazwaA(drukalbum);
		DrukAlbum tmpAlbum = DrukAlbum(nazwaA, true);
		for (int i = 0; i < ePress.getDrukAlbum().getZlecenia().size(); i++)
			tmpAlbum.dodajZlecenie(ePress.getDrukAlbum().getZlecenia().at(i));
		ePress.zmienDrukarnieAlbum(tmpAlbum);
		break;
	}
	}
}

//losowe

void Generator::generuj_autorow() {
	Los *losowanie = new Los();
	int liczba_autorow = losowanie->LosujLiczbe(10,10);

	for (int i = 0; i < liczba_autorow; i++) {
		
		string plec = "m";
		int _plec = losowanie->LosujLiczbe(500, 1);
		if (_plec % 2 == 0) plec = "k";
		
		string im = losowanie->LosujImie(plec);
		string naz = losowanie->LosujNazwisko(plec);
		int rok = losowanie->LosujLiczbe(50, 1946);

		Autor *nowy = new Autor(im, naz, plec, rok);
		ePress.dodajAutora(nowy);
	}
}

void Generator::generuj_ksiazki() {
	Los *losowanie = new Los();
	int liczba_publikacji = losowanie->LosujLiczbe(5, 5);

	for (int i = 0; i < liczba_publikacji; i++) {

		string plec = "m";
		int _plec = losowanie->LosujLiczbe(500, 1);
		if (_plec % 2 == 0) plec = "k";

		string im = losowanie->LosujImie(plec);
		string naz = losowanie->LosujNazwisko(plec);
		int rok = losowanie->LosujLiczbe(50, 1946);

		Autor *nowy = new Autor(im, naz, plec, rok);
		ePress.dodajAutora(nowy);

		char typ = 'p';
		int _typ = losowanie->LosujLiczbe(500, 1);
		if (_typ % 2 == 0) typ = 'a';

		int liczba_stron = losowanie->LosujLiczbe(300, 80);

		int _cena = losowanie->LosujLiczbe(300, 80);
		float cena = (float)_cena + 0.99;

		int _data_dzien = losowanie->LosujLiczbe(28, 1);
		int _data_miesiac = losowanie->LosujLiczbe(12, 1);
		int _data_rok = losowanie->LosujLiczbe(26, 1980);
		ostringstream dd, dm, dr;
		dd << _data_dzien;
		dm << _data_miesiac;
		dr << _data_rok;

		string data = dd.str() + "-" + dm.str() + "-" + dr.str();

		string nazwa = losowanie->LosujKsiazke();

		string gatunek = losowanie->LosujGatunek();

		if (typ == 'p') {
			Proza *nowa = new Proza(nazwa, data, liczba_stron, cena, gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajPublikacje(nowa);
		}
		else {
			Album *nowa = new Album(nazwa, data, liczba_stron, cena, gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajPublikacje(nowa);
		}
	}

}

void Generator::generuj_czasopisma() {
	Los *losowanie = new Los();
	int liczba_publikacji = losowanie->LosujLiczbe(5, 5);

	for (int i = 0; i < liczba_publikacji; i++) {

		string plec = "m";
		int _plec = losowanie->LosujLiczbe(500, 1);
		if (_plec % 2 == 0) plec = "k";

		string im = losowanie->LosujImie(plec);
		string naz = losowanie->LosujNazwisko(plec);
		int rok = losowanie->LosujLiczbe(50, 1946);

		Autor *nowy = new Autor(im, naz, plec, rok);
		ePress.dodajAutora(nowy);

		char typ = 'm';
		int _typ = losowanie->LosujLiczbe(500, 1);
		if (_typ % 2 == 0) typ = 't';

		int liczba_stron = losowanie->LosujLiczbe(50, 50);

		int _cena = losowanie->LosujLiczbe(8, 3);
		float cena = (float)_cena + 0.99;

		int _data_dzien = losowanie->LosujLiczbe(28, 1);
		int _data_miesiac = losowanie->LosujLiczbe(12, 1);
		int _data_rok = losowanie->LosujLiczbe(26, 1980);
		ostringstream dd, dm, dr;
		dd << _data_dzien;
		dm << _data_miesiac;
		dr << _data_rok;

		string data = dd.str() + "-" + dm.str() + "-" + dr.str();

		string nazwa = losowanie->LosujCzasopismo();

		string gatunek;

		if (typ == 'm') {
			gatunek = "miesiecznik";
			Miesiecznik *nowa = new Miesiecznik(nazwa, data, liczba_stron, cena, gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajPublikacje(nowa);
		}
		else {
			gatunek = "tygodnik";
			Tygodnik *nowa = new Tygodnik(nazwa, data, liczba_stron, cena, gatunek);
			nowa->zmienAutora(nowy);
			ePress.dodajPublikacje(nowa);
		}
	}

}

void Generator::generuj_umowy() {
	Los *losowanie = new Los();
	int liczba_umow = losowanie->LosujLiczbe(10, 10);

	for (int i = 0; i < liczba_umow; i++) {

		string plec = "m";
		int _plec = losowanie->LosujLiczbe(500, 1);
		if (_plec % 2 == 0) plec = "k";

		char typ = 'p';
		int _typ = losowanie->LosujLiczbe(500, 1);
		if (_typ % 2 == 0) typ = 'd';

		string im = losowanie->LosujImie(plec);
		string naz = losowanie->LosujNazwisko(plec);
		int rok = losowanie->LosujLiczbe(50, 1946);

		Autor *nowy = new Autor(im, naz, plec, rok);
		ePress.dodajAutora(nowy);

		if (typ == 'p') {
			Praca *nowa = new Praca(nowy);
			ePress.dodajUmowe(nowa);
		}
		else {
			Dzielo *nowa = new Dzielo(nowy);
			ePress.dodajUmowe(nowa);
		}
	}
}

void Generator::generuj_zlecenia() {
	Los *losowanie = new Los();
	int liczba_zlecen = losowanie->LosujLiczbe(6, 6);

	for (int i = 0; i < liczba_zlecen; i++) {

		int pub = losowanie->LosujLiczbe(500, 1);
		pub = pub % 2;

		if (pub == 0) {
			string plec = "m";
			int _plec = losowanie->LosujLiczbe(500, 1);
			if (_plec % 2 == 0) plec = "k";

			string im = losowanie->LosujImie(plec);
			string naz = losowanie->LosujNazwisko(plec);
			int rok = losowanie->LosujLiczbe(50, 1946);

			Autor *nowy = new Autor(im, naz, plec, rok);
			ePress.dodajAutora(nowy);

			char typ = 'm';
			int _typ = losowanie->LosujLiczbe(500, 1);
			if (_typ % 2 == 0) typ = 't';

			int liczba_stron = losowanie->LosujLiczbe(50, 50);

			int _cena = losowanie->LosujLiczbe(8, 3);
			float cena = (float)_cena + 0.99;

			int _data_dzien = losowanie->LosujLiczbe(28, 1);
			int _data_miesiac = losowanie->LosujLiczbe(12, 1);
			int _data_rok = losowanie->LosujLiczbe(26, 1980);
			ostringstream dd, dm, dr;
			dd << _data_dzien;
			dm << _data_miesiac;
			dr << _data_rok;

			string data = dd.str() + "-" + dm.str() + "-" + dr.str();

			string nazwa = losowanie->LosujCzasopismo();

			string gatunek;

			int naklad = losowanie->LosujLiczbe(100000, 5000);

			if (typ == 'm') {
				gatunek = "miesiecznik";
				Miesiecznik *nowa = new Miesiecznik(nazwa, data, liczba_stron, cena, gatunek);
				nowa->zmienAutora(nowy);
				ePress.dodajPublikacje(nowa);
				Zlecenie *nowe = new Zlecenie(nowa, naklad);
				ePress.dodajZlecenie(nowe);

				int bib = losowanie->LosujLiczbe(500, 1);
				bib = bib % 3;

				if (bib == 0)
					ePress.dodajDoDrukuStd1(nowe);
				if (bib == 1)
					ePress.dodajDoDrukuStd2(nowe);
				if (bib == 2)
					ePress.dodajDoDrukuAlbum(nowe);
			}
			else {
				gatunek = "tygodnik";
				Tygodnik *nowa = new Tygodnik(nazwa, data, liczba_stron, cena, gatunek);
				nowa->zmienAutora(nowy);
				ePress.dodajPublikacje(nowa);
				Zlecenie *nowe = new Zlecenie(nowa, naklad);
				ePress.dodajZlecenie(nowe);

				int bib = losowanie->LosujLiczbe(500, 1);
				bib = bib % 3;

				if (bib == 0)
					ePress.dodajDoDrukuStd1(nowe);
				if (bib == 1)
					ePress.dodajDoDrukuStd2(nowe);
				if (bib == 2)
					ePress.dodajDoDrukuAlbum(nowe);
			}
		}
		else if (pub == 1) {
			string plec = "m";
			int _plec = losowanie->LosujLiczbe(500, 1);
			if (_plec % 2 == 0) plec = "k";

			string im = losowanie->LosujImie(plec);
			string naz = losowanie->LosujNazwisko(plec);
			int rok = losowanie->LosujLiczbe(50, 1946);

			Autor *nowy = new Autor(im, naz, plec, rok);
			ePress.dodajAutora(nowy);

			char typ = 'p';
			int _typ = losowanie->LosujLiczbe(500, 1);
			if (_typ % 2 == 0) typ = 'a';

			int liczba_stron = losowanie->LosujLiczbe(300, 80);

			int _cena = losowanie->LosujLiczbe(300, 80);
			float cena = (float)_cena + 0.99;

			int _data_dzien = losowanie->LosujLiczbe(28, 1);
			int _data_miesiac = losowanie->LosujLiczbe(12, 1);
			int _data_rok = losowanie->LosujLiczbe(26, 1980);
			ostringstream dd, dm, dr;
			dd << _data_dzien;
			dm << _data_miesiac;
			dr << _data_rok;

			string data = dd.str() + "-" + dm.str() + "-" + dr.str();

			string nazwa = losowanie->LosujKsiazke();

			string gatunek = losowanie->LosujGatunek();

			int naklad = losowanie->LosujLiczbe(100000, 5000);

			if (typ == 'p') {
				Proza *nowa = new Proza(nazwa, data, liczba_stron, cena, gatunek);
				ePress.dodajPublikacje(nowa);
				nowa->zmienAutora(nowy);
				Zlecenie *nowe = new Zlecenie(nowa, naklad);
				ePress.dodajZlecenie(nowe);

				int bib = losowanie->LosujLiczbe(500, 1);
				bib = bib % 3;

				if (bib == 0)
					ePress.dodajDoDrukuStd1(nowe);
				if (bib == 1)
					ePress.dodajDoDrukuStd2(nowe);
				if (bib == 2)
					ePress.dodajDoDrukuAlbum(nowe);
			}
			else {
				Album *nowa = new Album(nazwa, data, liczba_stron, cena, gatunek);
				ePress.dodajPublikacje(nowa);
				nowa->zmienAutora(nowy);
				Zlecenie *nowe = new Zlecenie(nowa, naklad);
				ePress.dodajZlecenie(nowe);
				ePress.dodajDoDrukuAlbum(nowe);
			}
		}
	}
}