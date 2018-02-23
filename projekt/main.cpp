#include "stdafx.h"
#include "wydawnictwo.h"
#include "generator.h"
#include "reader.h"
#include "writer.h"
#include "wyjatki.h"
#include "los.h"

using namespace std;

int main() {

	cout << "Wydawnictwo ePress" << endl;

	srand(time(NULL));
	Generator *g_ePress = new Generator();
	Reader *r_ePress = new Reader();
	Writer *w_ePress = new Writer();
	Los *l_ePress = new Los();

	bool dalej = true;
	char wybor;
	string nazwa;

	while (dalej) {
		cout << endl << "Menu glowne:" << endl;
		cout << "[1] Pliki" << endl;
		cout << "[2] Publikacje" << endl;
		cout << "[3] Autorzy" << endl;
		cout << "[4] Umowy" << endl;
		cout << "[5] Drukarnie i zlecenia" << endl;
		cout << "[0] Zamknij program" << endl;
		cout << endl;
		cout << "Wybierz opcje:" << endl;
		cin >> wybor;

		switch (wybor) {
		case '1': {
			char w;
			cout << endl << "Menu - pliki:" << endl;
			cout << "[1] Stworz nowy plik tekstowy" << endl;
			cout << "[2] Wypisz zawartosc pliku tekstowego" << endl;
			cout << endl;
			cout << "Wybierz opcje:" << endl;
			cin >> w;
			switch (w) {
			case '1':
				g_ePress->stworz_plik();
				break;
			case '2':
				nazwa = g_ePress->wybor_pliku();
				r_ePress->wypisz_plik(nazwa);
				break;
			}
			break;
		}
		case '2': {
			char w;
			cout << endl << "Menu - publikacje:" << endl;
			cout << "[1] Wczytaj publikacje" << endl;
			cout << "[2] Wypisz publikacje" << endl;
			cout << "[3] Dodaj publikacje" << endl;
			cout << "[4] Usun publikacje" << endl;
			cout << "[5] Zapisz publikacje" << endl;
			cout << "[6] Generuj ksiazki" << endl;
			cout << "[7] Generuj czasopisma" << endl;
			cout << endl;
			cout << "Wybierz opcje:" << endl;
			cin >> w;
			switch (w) {
			case '1':
				nazwa = g_ePress->wybor_pliku();
				g_ePress->wczytaj_publikacje(nazwa);
				break;
			case '2': {
				char w;
				cout << endl;
				cout << "[1] Wypisz proze i poezje" << endl;
				cout << "[2] Wypisz album" << endl;
				cout << "[3] Wypisz miesieczniki" << endl;
				cout << "[4] Wypisz tygodniki" << endl;
				cout << "[5] Wypisz wszystkie publikacje" << endl;
				cout << endl;
				cout << "Wybierz opcje:" << endl;
				cin >> w;
				switch (w) {
				case '1':
					r_ePress->wypiszProze(g_ePress);
					break;
				case '2':
					r_ePress->wypiszAlbumy(g_ePress);
					break;
				case '3':
					r_ePress->wypiszMiesieczniki(g_ePress);
					break;
				case '4':
					r_ePress->wypiszTygodniki(g_ePress);
					break;
				case '5':
					r_ePress->wypiszPublikacje(g_ePress);
					break;
				}
				break;
			}
			case '3':
				try {
					g_ePress->dodaj_publikacje();
				}
				catch (UjemnaLiczbaStronWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac liczbe stron:\t" << x.getVal() << endl;
				}
				catch (UjemnaCenaWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac cene:\t" << x.getVal() << endl;
				}
				catch (NieprawidlowyWiekWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac rok urodzenia:\t" << x.getVal() << endl;
				}
				break;
			case '4':
				g_ePress->usun_publikacje();
				break;
			case '5':
				w_ePress->zapiszPublikacje(g_ePress);
				break;
			case '6':
				g_ePress->generuj_ksiazki();
				break;
			case '7':
				g_ePress->generuj_czasopisma();
				break;
			}
			break;
		}

		case '3': {
			char w;
			cout << endl << "Menu - autorzy:" << endl;
			cout << "[1] Wczytaj autorow" << endl;
			cout << "[2] Wypisz autorow" << endl;
			cout << "[3] Dodaj autora" << endl;
			cout << "[4] Usun autora" << endl;
			cout << "[5] Zapisz autorow" << endl;
			cout << "[6] Generuj autorow" << endl;
			cout << endl;
			cout << "Wybierz opcje:" << endl;
			cin >> w;
			switch (w) {
			case '1':
				nazwa = g_ePress->wybor_pliku();
				g_ePress->wczytaj_autorow(nazwa);
				break;
			case '2':
				r_ePress->wypiszAutorow(g_ePress);
				break;
			case '3':
				try {
					g_ePress->dodaj_autora();
				}
				catch (NieprawidlowyWiekWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac rok urodzenia:\t" << x.getVal() << endl;
				}
				break;
			case '4':
				g_ePress->usun_autora();
				break;
			case '5':
				w_ePress->zapiszAutorow(g_ePress);
				break;
			case '6': {
				g_ePress->generuj_autorow();
				break;
			}
			}
		}
			break;
		case '4': {
			char w;
			cout << endl << "Menu - umowy" << endl;
			cout << "[1] Wczytaj umowy" << endl;
			cout << "[2] Wypisz umowy" << endl;
			cout << "[3] Dodaj umowe" << endl;
			cout << "[4] Usun umowe" << endl;
			cout << "[5] Zapisz umowy" << endl;
			cout << "[6] Generuj umowy" << endl;
			cout << endl;
			cout << "Wybierz opcje:" << endl;
			cin >> w;
			switch (w) {
			case '1':
				nazwa = g_ePress->wybor_pliku();
				g_ePress->wczytaj_umowy(nazwa);
				break;
			case '2': {
				char w;
				cout << endl;
				cout << "[1] Wypisz umowy o prace" << endl;
				cout << "[2] Wypisz umowy o dzielo" << endl;
				cout << "[3] Wypisz wszystkie umowy" << endl;
				cout << endl;
				cout << "Wybierz opcje:" << endl;
				cin >> w;
				switch (w) {
				case '1':
					r_ePress->wypiszPrace(g_ePress);
					break;
				case '2':
					r_ePress->wypiszDzielo(g_ePress);
					break;
				case '3':
					r_ePress->wypiszUmowy(g_ePress);
					break;
				}
				break;
			}
			case '3':
				try {
					g_ePress->dodaj_umowe();
				}
				catch (NieprawidlowyWiekWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac rok urodzenia:\t" << x.getVal() << endl;
				}
				break;
			case '4':
				g_ePress->usun_umowe();
				break;
			case '5':
				w_ePress->zapiszUmowy(g_ePress);
				break;
			case '6':
				g_ePress->generuj_umowy();
				break;
			}
			break;
		}
		case '5': {
			char w;
			cout << endl << "Menu - drukarnie i zlecenia:" << endl;
			cout << "[1] Wczytaj zlecenia" << endl;
			cout << "[2] Zmien nazwy drukarni" << endl;
			cout << "[3] Wypisz drukarnie" << endl;
			cout << "[4] Wypisz zlecenia" << endl;
			cout << "[5] Dodaj zlecenie" << endl;
			cout << "[6] Usun zlecenie" << endl;
			cout << "[7] Zapisz zlecenia" << endl;
			cout << "[8] Generuj zlecenia" << endl;
			cout << endl;
			cout << "Wybierz opcje:" << endl;
			cin >> w;
			switch (w) {
			case '1':
				nazwa = g_ePress->wybor_pliku();
				g_ePress->wczytaj_zlecenia(nazwa);
				break;
			case '2':
				g_ePress->zmien_nazwe_drukarni();
				break;
			case '3':
				r_ePress->wypiszDrukarnie(g_ePress);
				break;
			case '4': {
				char x;
				cout << endl;
				cout << "[1] Wypisz zlecenia standardowej drukarni nr 1 " << g_ePress->getePress().getDrukStd1().getNazwa() << endl;
				cout << "[2] Wypisz zlecenia standardowej drukarni nr 2 " << g_ePress->getePress().getDrukStd2().getNazwa() << endl;
				cout << "[3] Wypisz zlecenia albumowej drukarni " << g_ePress->getePress().getDrukAlbum().getNazwa() << endl;
				cout << "[4] Wypisz wszystkie zlecenia" << endl;
				cout << endl;
				cout << "Wybierz opcje:" << endl;
				cin >> x;
				switch (x) {
				case '1':
					r_ePress->wypiszZleceniaStd1(g_ePress);
					break;
				case '2':
					r_ePress->wypiszZleceniaStd2(g_ePress);
					break;
				case '3':
					r_ePress->wypiszZleceniaAlbum(g_ePress);
					break;
				case '4':
					r_ePress->wypiszZlecenia(g_ePress);
					break;
				}
				break;
			}
			case '5':
				try {
					g_ePress->dodaj_zlecenie();
				}
				catch (NieprawidlowyWiekWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac rok urodzenia:\t" << x.getVal() << endl;
				}
				catch (UjemnaLiczbaStronWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac liczbe stron:\t" << x.getVal() << endl;
				}
				catch (UjemnaCenaWyjatek x) {
					cout << "Nie mozna wykonac operacji. " << x.getMessage() << endl;
					cout << "Probowano wpisac cene:\t" << x.getVal() << endl;
				}
				break;
			case '6':
				g_ePress->usun_zlecenie();
				break;
			case '7': {
				char z;
				cout << endl;
				cout << "[1] Zapisz zlecenia standardowej drukarni nr 1 " << g_ePress->getePress().getDrukStd1().getNazwa() << endl;
				cout << "[2] Zapisz zlecenia standardowej drukarni nr 2 " << g_ePress->getePress().getDrukStd2().getNazwa() << endl;
				cout << "[3] Zapisz zlecenia albumowej drukarni " << g_ePress->getePress().getDrukAlbum().getNazwa() << endl;
				cout << "[4] Zapisz zlecenia wszystkich drukarni" << endl;
				cout << endl;
				cout << "Wybierz opcje:" << endl;
				cin >> z;
				switch (z) {
				case '1':
					w_ePress->zapiszZleceniaStd1(g_ePress);
					break;
				case '2':
					w_ePress->zapiszZleceniaStd2(g_ePress);
					break;
				case '3':
					w_ePress->zapiszZleceniaAlbum(g_ePress);
					break;
				case '4':
					w_ePress->zapiszZlecenia(g_ePress);
					break;
				}
				break;
			}
			case '8':
				g_ePress->generuj_zlecenia();
				break;
			}
			break;
		}
		case '0':
			dalej = 0;
			break;
		}
	}

	system("pause");
	return 0;
}