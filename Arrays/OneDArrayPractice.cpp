#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

const int SIZE = 10;

// ARRAYS ARE PASS BY REFERENCE
void fillArray(int[], int); // ref to a 1D array, size
void displayArray(const int[], int);
void addValueArray(int[], int);

int main() {
	int oneD[SIZE];
	int i = 0;
	
	srand(time(0));
	//cout << oneD << endl;

	fillArray(oneD, SIZE); // oneD is passed by reference
	// so fillArray can modify its memory
	
	// task 1: write a printArray() function
	displayArray(oneD, SIZE);
	// task 2: write a addValueArray() function
	// prompts the user for a value and adds that value
	// to every element in oneD
	addValueArray(oneD, SIZE);
	displayArray(oneD, SIZE);

	return 0;
}

void addValueArray(int arr[], int size) {
	int i, value = 0;
	cout << "Enter a value: ";
	cin >> value;
	
	for (i = 0; i < size; i++) {
		arr[i] += value;
	}
}

void displayArray(const int arr[], int size) {
	int i;
		
	for (i = 0; i < size; i++) {
		cout << arr[i] << endl;
	}
}

void fillArray(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		arr[i] = rand() % 6 + 1;
	}
}
