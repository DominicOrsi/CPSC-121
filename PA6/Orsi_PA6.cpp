/*
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: November 2, 2020
Programming Assignment: PA6
*/
#include<iostream>
#include<fstream>
#include<iomanip>
#include<ios>
#include<string>
#include<cmath>


using namespace std;
// Constant declaration
const int NUM_CONST = 5;
//Function prototype declarations
double read_double(ifstream& infile);
int read_integer(ifstream& infile);
double calculate_sum(double number1, double number2, double number3, double number4, double number5);
double calculate_mean(double sum, int number);
double calculate_deviation(double number, double mean);
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);
double calculate_standard_deviation(double variance);
double find_max(double number1, double number2, double number3, double number4, double number5);
double find_min(double number1, double number2, double number3, double number4, double number5);
void print_double(ofstream& outfile, double number);

int main() {
	int i = 0;
	int tempArray[NUM_CONST];
	int classArray[NUM_CONST];
	double gpaArray[NUM_CONST];
	double ageArray[NUM_CONST];
	double deviationArray[NUM_CONST];
	double gpaSum = 0.0;
	double ageSum = 0.0;
	double classSum = 0.0;
	double gpaMean = 0.0;
	double ageMean = 0.0;
	double classMean = 0.0;
	double gpaVari = 0.0;
	double gpaDeviation = 0.0;
	double gpaMin = 0.0;
	double gpaMax = 0.0;
	string temp = "";
	string inputFileName = "input.dat";
	string outputFileName = "output.dat";
	ifstream infile;
	ofstream outfile;
	
	// Open files
	infile.open(inputFileName);
	outfile.open(outputFileName);

	// Check input file is open
	if(!infile.is_open()) {
	cout << "Input file failed to open\n";
		return -1;
	}	
	
	// for loop for getting data
	for(i = 0; i < NUM_CONST; i++) {
		tempArray[i] = read_integer(infile);
		gpaArray[i] = read_double(infile);
		// cout << "GPA: " << gpaArray[i] << endl;
		classArray[i] = read_integer(infile);
		// cout << "Class: " << classArray[i] << endl;
		ageArray[i] = read_double(infile);
		// cout << "Age: " << ageArray[i] << endl;
		getline(infile, temp);
	}
	
	// Sum function calls
	gpaSum = calculate_sum(gpaArray[0], gpaArray[1], gpaArray[2], gpaArray[3], gpaArray[4]);
	classSum = calculate_sum(classArray[0], classArray[1], classArray[2], classArray[3], classArray[4]);
	ageSum = calculate_sum(ageArray[0], ageArray[1], ageArray[2], ageArray[3], ageArray[4]);
	
	// Mean function calls
	gpaMean = calculate_mean(gpaSum, NUM_CONST);
	classMean = calculate_mean(classSum, NUM_CONST);
	ageMean = calculate_mean(ageSum, NUM_CONST);
	
	// Output function calls
	print_double(outfile, gpaMean);
	print_double(outfile, classMean);
	print_double(outfile, ageMean);

	// Deviation function calls for loop
	for(i = 0; i < NUM_CONST; i++) {
	deviationArray[i] = calculate_deviation(gpaArray[i], gpaMean);
	deviationArray[i] = abs(deviationArray[i]);
	}
	
	// Variation function call
	gpaVari = calculate_variance(deviationArray[0], deviationArray[1], deviationArray[2], deviationArray[3], deviationArray[4], NUM_CONST);

	// Standard deviation call
	gpaDeviation = calculate_standard_deviation(gpaVari);
	
	// Output function call
	outfile << endl;
	print_double(outfile, gpaDeviation);

	// Min and Max function call
	gpaMin = find_min(gpaArray[0], gpaArray[1], gpaArray[2], gpaArray[3], gpaArray[4]);
	gpaMax = find_max(gpaArray[0], gpaArray[1], gpaArray[2], gpaArray[3], gpaArray[4]);
	
	// Output function call
	print_double(outfile, gpaMin);
	print_double(outfile, gpaMax);

	// File closing
	infile.close();
	outfile.close();

	return 0;
}

// Function definitions 
double read_double(ifstream& infile) {
	double numDouble = 0.0;
	infile >> numDouble;
	return numDouble;
}

int read_integer(ifstream& infile) {
	int numInt = 0;
	infile >> numInt;
	return numInt;
}

double calculate_sum(double number1, double number2, double number3, double number4, double number5) {
	double sum = 0.0;
	sum = number1 + number2 + number3 + number4 + number5;
	return sum;
}

double calculate_mean(double sum, int number) {
	double mean = 0.0;
	mean = sum / number;
	
	// Check mean
	if(mean <= 0) {
		return -1;
	} else {
		return mean;
	}
}

double calculate_deviation(double number, double mean) {
	double deviation = 0.0;
	deviation = number - mean;
	return deviation;
}

double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number) {
	double variance = 0.0;
	variance = (pow(deviation1, 2) + pow(deviation2, 2) + pow(deviation3, 2) + pow(deviation4, 2) + pow(deviation5, 2)) / number;
	return variance;
}

double calculate_standard_deviation(double variance) {
	double standardDeviation = 0.0;
	standardDeviation = sqrt(variance);
	return standardDeviation;
}

double find_max(double number1, double number2, double number3, double number4, double number5) {
	double maxNumber = 0.0;
	maxNumber = number1;

	// if statement for max
	if(number2 > maxNumber) {
		maxNumber = number2;
	} else if(number3 > maxNumber) {
		maxNumber = number3;
	} else if(number4 > maxNumber) {
		maxNumber = number4;
	} else if(number5 > maxNumber) {
		maxNumber = number5;
	}

	return maxNumber;
}

double find_min(double number1, double number2, double number3, double number4, double number5) {
	double minNumber = 0.0;
	minNumber = number1;

	// if statement for min
	if(number2 < minNumber) {
		minNumber = number2;
	} else if(number3 < minNumber) {
		minNumber = number3;
	} else if(number4 < minNumber) {
		minNumber = number4;
	} else if(number5 < minNumber) {
		minNumber = number5;
	}

	return minNumber;
}

void print_double(ofstream& outfile, double number) {
	outfile << fixed << setprecision(2) << number << endl;
}

