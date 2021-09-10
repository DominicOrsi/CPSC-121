#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int ARRAY_SIZE = 100;	

int main() {
	int i = 0;
	int d = 0;
	string temp = "";
	string foodArray[ARRAY_SIZE];
	string inputFileName = "foods.txt";
	ifstream infile;

	infile.open(inputFileName);

	
	if (!infile.eof()) {
	
		for(i = 0; i < ARRAY_SIZE; i++) {
			getline(infile, foodArray[i]);
		}
	} 

	infile.close();

	infile.open(inputFileName);

	while (getline(infile, temp)) {
		d++;
	}
	
	for(i = 0; i < d - 2; i++) {
		cout << foodArray[i] << ", ";
	}
	cout << foodArray[d - 2 ] << " ";

	infile.close();
	return 0;
}

