#include "file_manager.h"
#include <iostream>
#include <fstream>

using namespace std;

void writeToFile(double times[], int testCount) {
	cout << "Writing results to file..." << endl;
	ofstream file("dane.txt");
	for (int i = 0; i < testCount; i++) {
		file << times[i] << ",";
	}
	file << "\n";
	file.close();
}