#include <iostream>

using namespace std;

int main() {
	// the software development method
	// 1. specify the problem requirements
	// Need to ask the user for price of item, tax % and then compute the price with tax
	// 2. analyze the problem
	// inputs: Price and tax %
	// outputs: Price with tax added
	// 3. design an algorithm to solve the problem
	// PSEUDOCODE
	// prompt the user for the price of item and tax %
	// get the price and tax % and store them
	// compute price with tax by
	// display the price with tax to the user
	// 4. implement the algorithm

	double price = 0;
	double tax = 0.0;
	double priceWTax = 0.0;
	
	cout << "Please enter the purchase price: ";
	cin >> price;
	cout << "Please enter tax percentage (%): ";
	cin >> tax;
	tax = tax / 100;
	priceWTax = price * tax;
	priceWTax = priceWTax + price;
	cout << "Price with tax is: $" << priceWTax << endl;

	// 5. test the completed program
	// test with values from sheet
	// 6. maintain the program
	return 0;
}
