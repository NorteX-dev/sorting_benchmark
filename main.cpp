#include <iostream>
#include <ctime>
#include <chrono>
#include "input_manager.h"
#include "file_manager.h"
#include "sorting.h"

// Długość każdej tablicy.
#define DLUGOSC 10
// Ilość testów która jest wykonywana.
// Więcej testów to bardziej dokładna średnia czasów, ale zajmuje dłużej.
#define ILOSC_TESTOW 5
// Kontroluje czy jest wyświetlana tablica przed i po sortowaniu.
// Dla większych długości tablicy (~ >20) zalecane jest przełączenie na `false` żeby nie zawalało konsoli.
#define WYSWIETLAJ_WARTOSCI true

using namespace std;
using namespace std::chrono;

void printArray(int arr[], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d ", arr[i]);
	}
	printf("\n");
}

// Sortuje tablice `arr` według algorytmu `algorithm`.
// Zwraca czas wykonania __w mikrosekundach__.
double performSingleTest(int arr[], char algorithm) {
	auto start = high_resolution_clock::now();
	if (algorithm == 'b') {
		bubbleSort(arr, DLUGOSC);
	}
	if (algorithm == 's') {
		selectionSort(arr, DLUGOSC);
	}
	if (algorithm == 'i') {
		insertionSort(arr, DLUGOSC);
	}
	if (algorithm == 'm') {
		mergeSort(arr, 0, DLUGOSC - 1);
	}
	if (algorithm == 'q') {
		quickSort(arr, 0, DLUGOSC - 1);
	}
	auto end = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(end - start);
	double us = duration.count();
	return us;
}

void printTimes(double times[]) {
	for (int i = 0; i < ILOSC_TESTOW; i++) {
		cout << "Czas pracy = " << times[i] << "ms" << endl;
	}
}

double sumTimes(double times[]) {
	double sum = 0;
	for (int i = 0; i < ILOSC_TESTOW; i++) {
		sum += times[i];
	}
	return sum;
}

int main() {
	srand(time(NULL));

	int arr[DLUGOSC];
	char test = choose_algorithm();
	generate_mock_data(arr, DLUGOSC);
	// Tablica `times`, po wykonaniu testów, zawiera czasy wykonania każdego testu.
	// Wyniki są w MIKROSEKUNDACH (nie milisekundach)!
	double times[ILOSC_TESTOW];
	for (int i = 0; i < ILOSC_TESTOW; i++) {
		cout << "TEST #" << i + 1 << ":" << endl;
		if (WYSWIETLAJ_WARTOSCI) {
			cout << "Tablica przed sortowaniem:" << endl;
			printArray(arr, DLUGOSC);
		}

		double resultMcrSec = performSingleTest(arr, test);

		if (WYSWIETLAJ_WARTOSCI) {
			cout << "Tablica po sortowaniu:" << endl;
			printArray(arr, DLUGOSC);
		}
		times[i] = resultMcrSec;
		cout << "Sortowanie zajalo: " << resultMcrSec / 1000.0 << "ms." << endl;
		cout << endl << "###########################" << endl;
	}
	cout << "Czasy:" << endl;
	printTimes(times);
	long double avg = sumTimes(times) / (long double) ILOSC_TESTOW;
	cout << "Sredni czas = " << avg << "ms" << endl;
	writeToFile(times, ILOSC_TESTOW);
	return 0;
}

