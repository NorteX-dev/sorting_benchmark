#include "input_manager.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void generate_mock_data(int tab[], int n) {
	int i = 0;
	char wybor;
	cout
			<< "Podaj przypadek:\no - optymalne (co 3 elementy jeden losowy)\np - pesymistyczne (wartosci 1000..0)\nl - losowe (wartosci losowe z przedzialu 0 - 999)"
			<< endl;
	cin >> wybor;
	if (wybor == 'o') {
		while (i < n) {
			if (i % 3 == 0) {
				tab[i] = (rand() % 1000);
			} else {
				tab[i] = i;
			}
			i++;
		}
	}
	if (wybor == 'l') {
		while (i < n) {
			tab[i] = (rand() % 1000);
			i++;
		}
	}
	if (wybor == 'p') {
		while (i < n) {
			tab[i] = n - i;
			i++;
		}
	}
}

char choose_algorithm() {
	char wybor;
	cout
			<< "Wybierz algorytm do przetestowania:" << endl
			<< "b - bubble" << endl
			<< "s - selection" << endl
			<< "i - insertion" << endl
			<< "m - merge" << endl
			<< "q - quick" << endl
			<< endl;
	cin >> wybor;
	return wybor;
}