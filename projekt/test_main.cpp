#include "stdafx.h"
#include "wydawnictwo.h"
#include "generator.h"
#include "reader.h"

using namespace std;


int main() {

	cout << "Wydawnictwo ePress" << endl;

	Generator *test = new Generator();
	Reader *test_reader = new Reader();

	bool dalej = true;
	char wybor;
	string nazwa;

	while (dalej) {
		cout << endl;
		cout << "[1] Stworz nowy plik" << endl;
		cout << "[2] Dodaj wpis do pliku" << endl;
		cout << "[3] Wypisz zawartosc pliku" << endl;
		cout << "[4] Wczytaj zawartosc pliku" << endl;
		cout << "[5] Wypisz publikacje wydawnictwa" << endl;
		cout << "[6] Wypisz autorow wydawnictwa" << endl;
		cout << "[7] Usun publikacje" << endl;
		cout << "[8] Usun autora" << endl;
		cout << "[9] Wczytaj autorow" << endl;
		cout << "[a] Dodaj umowe" << endl;
		cout << "[b] Przegladaj umowy" << endl;
		cout << "[c] Usun umowe" << endl;
		cout << "[d] Wczytaj umowe" << endl;
		cout << "[e] Dodaj zlecenie" << endl;
		cout << "[f] Wypisz zlecenia" << endl;
		cout << "[g] Usun zlecenie" << endl;
		cout << "[h] Wczytaj zlecenia" << endl;
		cout << "[i] Dodaj nazwy drukarni" << endl;
		cout << "[j] Przegladaj drukarnie" << endl;
		cout << "[0] Zamknij program" << endl;
		cout << endl;
		cout << "Wybierz opcje:" << endl;
		cin >> wybor;

		switch (wybor) {
		case '1':
			test->stworz_plik();
			break;
		case '2':
			nazwa = test->wybor_pliku();
			test_reader->dodaj_wynik_plik(nazwa);
			break;
		case '3':
			nazwa = test->wybor_pliku();
			test_reader->wypisz_plik(nazwa);
			break;
		case '4':
			nazwa = test->wybor_pliku();
			test->wczytaj_publikacje(nazwa);
			break;
		case '5':
			test_reader->wypiszPublikacje(test);
			break;
		case '6':
			test_reader->wypiszAutorow(test);
			break;
		case '7':
			test->usun_publikacje();
			break;
		case '8':
			test->usun_autora();
			break;
		case '9':
			nazwa = test->wybor_pliku();
			test->wczytaj_autorow(nazwa);
			break;
		case 'a':
			test->dodaj_umowe();
			break;
		case 'b':
			test_reader->wypiszUmowy(test);
			break;
		case 'c':
			test->usun_umowe();
			break;
		case 'd':
			nazwa = test->wybor_pliku();
			test->wczytaj_umowy(nazwa);
			break;
		case 'e':
			test->dodaj_zlecenie();
			break;
		case 'f':
			test_reader->wypiszZlecenia(test);
			break;
		case 'g':
			test->usun_zlecenie();
			break;
		case 'h':
			nazwa = test->wybor_pliku();
			test->wczytaj_zlecenia(nazwa);
			break;
		case 'i':
			test->zmien_nazwe_drukarni();
			break;
		case 'j':
			test_reader->wypiszDrukarnie(test);
			break;
		case 'k':
			test_reader->wypiszZleceniaStd1(test);
			break;
		case '0':
			dalej = 0;
			break;
		}
	}

	system("pause");
	return 0;
}