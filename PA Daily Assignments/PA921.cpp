#include <iostream>

using namespace std;

int main() {
	// SW development method
	// 1. problem requirements
	// We want to calculate the reimburstment per mile for a sales man at $.35 a mile.
	
	// 2. analyze the problem
	// inputs: Original odometer reading, new odometer reading
	// outputs: Reimburstment per mile at $0.35 a mile
	// relationships: Subtract original odometer reading from new odometer reading to get reimburstment
	// 
	
	// 3. design the algorithm (pseudocode)
	// Ask for original odometer reading
	// Ask for new odometer reading
	// Subtract orignal odometer from new odometer
	// Get answer from above problem and then times it by $0.35 to get reimburstment
	// Display reimburstment to user
	
	// 4. implement the algorithm (C++)
	
	double firstReading = 0.0;
	double secondReading = 0.0;
	double newReading = 0.0;
	double moneyBack =0.0;

	cout << "Please enter original odometer reading: ";
	cin >> firstReading;
	cout << "Please enter ending odometer reading: ";
	cin >> secondReading;

	//
	newReading = secondReading - firstReading;
	moneyBack = newReading * 0.35;

	//
	cout << "You drove " << newReading << " miles. At $0.35 a mile your reimburstment is: $" << moneyBack << ".\n";
	
	// 5. test the completed program
	// test with values from sheet
	
	
	// 6. maintain the program

	return 0;
}
