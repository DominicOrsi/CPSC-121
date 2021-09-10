#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

double BMI(double userHeight, double userWeight);
double Height(void);
double Weight(void);
double IfBMI(double userBMI);

int main() {
	// SW development method
	// 1. problem requirements
	// To get weight in pounds and height in inches to calculate BMI and say where they are underweight, overweight, or if they are in the optimal BMI
	
	// 2. analyze the problem
	// inputs: Weight, height
	// outputs: BMI
	// relationships: weight time 703 divied by height squared
	// 
	
	// 3. design the algorithm (pseudocode)
	// Ask for weight in lbs from user
	// Ask for height in feet from user
	// Times weight by 703
	// Divide that by height squared
	// Get BMI and then run a if else statement to say whether one is underweight, overweight, or optimal
	
	// 4. implement the algorithm (C++)
	
	double userWeight = 0.0;
	double userHeight = 0.0;
	double userBMI = 0.0;

	userWeight = Weight();
	userHeight = Height();
	userBMI = BMI(userHeight, userWeight);
	
	IfBMI(userBMI);
	
	// 5. test the completed program
	// test with values from sheet
	
	
	// 6. maintain the program

	return 0;
}

double BMI(double userHeight, double userWeight) {
	double userBMI = 0.0;
	userHeight = pow(userHeight, 2);
	userBMI = (userWeight * 703) / userHeight;
	return userBMI;
}

double Height(void) {
	double userHeight = 0.0;
	cout << "Please input your height in inches: ";
	cin >> userHeight;
	return userHeight;
}

double Weight(void) {
	double userWeight = 0.0;
	cout << "Please input your weight in lbs: ";
	cin >> userWeight;
	return userWeight;
}

double IfBMI(double userBMI) {
	if (userBMI <= 18.5) {
	cout << "Your BMI is " << setprecision(3) << userBMI << ", your BMI considers you underweight." << endl;
	} else if (userBMI >= 25) {
	cout << "Your BMI is " << setprecision(3) << userBMI << ", your BMI considers you overweight." << endl;
	} else {
	cout << "Your BMI is " << setprecision(3) << userBMI << ", you are in the optimal BMI range." << endl;
	}
	return 0;
}

