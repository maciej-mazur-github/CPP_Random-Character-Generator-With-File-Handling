#include <iostream>   // do oblugi standardowych strumieni wyjscia/wejscia (cout oraz cin)
#include <fstream>   // do obslugi plikow
#include <conio.h>  // dla funkcji _getch() umozliwiajacej utrzymanie otwartej konsoli do momentu nacisniecia dowolnego klawisza
#include <cstdlib>
using namespace std;


void wczytajDoPliku() {
	char tablica[15];

	srand(time(0));   // umozliwia seedowanie generatora liczb pseudolosowych rand() w zaleznosci od czasu systemowego 
	// dzieki temu kazde kolejne uzycie rand() wygeneruje inne liczby (bez tego generowane bylyby ciagle te same)

	for (int i = 0; i < 15; i++) {
		tablica[i] = (char)((rand() % 25) + 97);  // %25 ogranicza przedzial wygenerowanych liczb do 0-25
		// +97 przeksztalca wygenerowane liczby w odpowiadajace im male znaki ASCII poczawszy od 
		// 97 (czyli od malego "a")
	}

	ofstream plik("znaki.txt");  // otwarcie pliku znaki.txt do zapisu; jesli plik ten jeszcze w folderze nie istnieje, to zostanie stworzony
	// jesli zas istnieje, to jego pierwotna zawartosc zostanie na wstepie wykasowana

	if (!plik) {    // dzieki przeladowaniu operatorow klasy fstream zmienna strumieniowa plik bedzie miec wartosc logiczna false
		// jesli przy powyzszym otwarciu pliku wystapil jakis blad; w przeciwnymm razie bedzie miec wartosc true
		cout << "Wystapil blad przy otwieraniu pliku znaki.txt\nSprobuj ponownie";
		return;
	}

	for (int i = 0; i < 15; i++) {
		if (!plik.put(tablica[i])) {  // warunek, ktory jednoczesnie sprawdza, czy w strumieniu nie pojawil sie podczas zapisu jakis blad oraz
			// dopisuje do pliku kolejne znaki z tablicy
			cout << "Wystapil blad podczas zapisywania do pliku znaki.txt\n";
			return;
		}
	}

	if (plik) {    // jesli po wczytaniu wszystkich znakow z tablicy zadna z flag stanu strumienia nie zostala ustawiona (jesli strumien nie ma bledow)
		cout << "\nTablica losowych znakow zostala prawidlowo zapisana w pliku znaki.txt\nMozesz teraz uzyc opcji 2) by wyswietlic zawartosc pliku.\n\n\n";
	}
}


void odczytajZPliku() {
	ifstream plik("znaki.txt");  // otwarcie pliku do odczytu

	if (!plik) {   // jesli otwarcie pliku nie powiodlo sie np. dlatego, ze plik jeszcze nie istnieje w folderze projektu
		cout << "\nOtwarcie pliku znaki.txt nie powiodlo sie. Upewnij sie, by uzyc najpierw opcji 1) celem stworzenia pliku, z ktorego program"
			<< " bedzie mogl odczytac dane.\n";
		return;
	}

	char znak;

	while (plik.get(znak)) {  // w tej petli wydrukowany na ekranie zostanie kolejno kazdy znak z pliku
		// petle te przerywa dopiero napotkanie EOF (end of file), ktory ustawi wartosc logiczna strumienia plik na false
		cout << znak;
	}

	if (!plik.eof()) {  // jesli zczytywanie z pliku zakonczone zostalo z innego powodu niz napotkanie konca pliku
		cout << "\nBlad odczytu pliku znaki.txt\n";
	}
}