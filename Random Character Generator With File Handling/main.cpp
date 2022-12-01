#include <iostream>   // do oblugi standardowych strumieni wyjscia/wejscia (cout oraz cin)
#include <fstream>   // do obslugi plikow
#include <conio.h>  // dla funkcji _getch() umozliwiajacej utrzymanie otwartej konsoli do momentu nacisniecia dowolnego klawisza
#include <cstdlib>  // dla funkcji rand() oraz srand() (dla generowania liczb pseudolosowych)
#include "random_character_generator.h"

using namespace std;  // ulatwienie dajace mozliwosc napisania np. cout zamiast std::cout



int main()
{
	cout << "Program do zapisywania i odczytywania losowych znakow z pliku.\n"
		<< "Wybierz jedna z nastepujacych opcji:\n\n"
		<< "\t1) Zapis losowych znakow do pliku znaki.txt\n"
		<< "\t2) Odczyt znakow z pliku znaki.txt\n"
		<< "\t3) Zakonczenie dzialania programu\n";

	int wybor;
	bool kontynuuj = true;

	while (kontynuuj) {   // petla glowna programu, ktora przerwac moze jedynie wybor opcji 3)
		cin >> wybor;

		switch (wybor) {
		case 1:
			wczytajDoPliku();
			break;
		case 2:
			odczytajZPliku();
			break;
		case 3:
			kontynuuj = false;
			cout << "\nWybrano zakonczenie dzialania programu...\n";
			break;
		default:
			cout << "Wybrano nieprawidlowa opcje. Sprobuj ponownie.../n";
		}

		if (kontynuuj) {
			cout << "\n\nKtora opcje wybierasz teraz? ";
		}
	}

	cout << "\n\n\nNacisnij dowolny klawisz, aby zakonczyc dzialanie programu..." << endl;
	_getch();
}





