#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <iomanip>
#include <cmath>

using namespace std;

// Function prototype declaration
double read_double(ifstream& infile);
int read_integer(ifstream& infile);
string read_string(ifstream& infile);
int store_data_sets(ifstream& infile, vector<string>& studentID, vector<double>& studentGPA, vector<int>& studentClass, vector<double>& studentAge);
double calculate_sum(vector<double> vector);
double calculate_sum(vector<int> vector);
double calculate_mean(double sum, int number);
int calculate_count_above_mean(double mean, vector<double> studentGPA);
int calculate_count_below_mean(double mean, vector<double> studentGPA);
void calculate_deviation(vector<double>& deviationsGPA, vector<double> studentGPA, double mean);
double calculate_variance(vector<double> vector);
double calculate_standard_deviation(double variance);
double find_max(vector<double> vector, int& index);
double find_min(vector<double> vector, int& index);
void print_formatted_double(ofstream& outfile, double number, int precision);

int main() {
	vector<string> studentID;
	vector<double> studentGPA;
	vector<int> studentClass;
	vector<double> studentAge;
	vector<double> deviationsGPA;
	int completeSet = 0;
	int aboveGPA = 0, belowGPA = 0, maxGPAIndex = 0, minGPAIndex = 0;
	double sumGPA = 0.0, meanGPA = 0.0, vGPA = 0.0, standardDGPA = 0.0, minGPA = 0.0, maxGPA = 0.0;
	double sumClass = 0.0, meanClass = 0.0;
	double sumAge = 0.0, meanAge = 0.0;
	string inputFileName = "input.dat";
	string outputFileName = "output.dat";
	ifstream infile;
	ofstream outfile;

	// Open files
	infile.open(inputFileName);
	outfile.open(outputFileName);

	// Calling function store_data_sets
	completeSet = store_data_sets(infile, studentID, studentGPA, studentClass, studentAge);
	
	// If loop to check complete data set
	if(completeSet == -1) {
		cout << "Did not grab complete data set, exiting program." << endl;
		exit(-1); // Exit program with -1 error code
	}

	// Calling functions to the find sum of GPA, class standing, and age
	sumGPA = calculate_sum(studentGPA);
	sumClass = calculate_sum(studentClass);
	sumAge = calculate_sum(studentAge);

	// Calling function to calculate mean GPA, class standing, and age
	meanGPA = calculate_mean(sumGPA, completeSet);
	meanClass = calculate_mean(sumClass, completeSet);
	meanAge = calculate_mean(sumAge, completeSet);

	// Calling functions to find GPA above and below mean GPA
	aboveGPA = calculate_count_above_mean(meanGPA, studentGPA);
	belowGPA = calculate_count_below_mean(meanGPA, studentGPA);

	// Calling function to find deviation
	calculate_deviation(deviationsGPA, studentGPA, meanGPA);

	// Calling function to find variance
	vGPA = calculate_variance(deviationsGPA);

	// Calling function to find standard deviation
	standardDGPA = calculate_standard_deviation(vGPA);

	// Calling functions to find min and max GPA
	maxGPA = find_max(studentGPA, maxGPAIndex);
	minGPA = find_min(studentGPA, minGPAIndex);
	cout << "Max: " << maxGPAIndex << " Min: " << minGPAIndex << endl;

	// Output things
	/*
	cout << completeSet << endl;
	cout << meanGPA << endl;
	cout << aboveGPA << endl << belowGPA << endl;
	cout << meanClass << endl;
	cout << meanAge << endl << endl;
	cout << standardDGPA << endl;
	cout << studentGPA.at(minGPAIndex) << endl << studentID.at(minGPAIndex) << endl;
	cout << studentGPA.at(maxGPAIndex) << endl << studentID.at(maxGPAIndex) << endl;
	*/

	// Calling function to output numbers to outfile
	outfile << completeSet << endl;
	outfile << endl;

	// Calling function to output numbers to outfile
	print_formatted_double(outfile, meanGPA, 2);
	outfile << aboveGPA << endl;
	outfile << belowGPA << endl;

	// Calling function to output numbers to outfile
	print_formatted_double(outfile, meanClass, 2);
	print_formatted_double(outfile, meanAge, 2);
	outfile << endl;

	// Calling function to output numbers to outfile
	print_formatted_double(outfile, standardDGPA, 2);
	print_formatted_double(outfile, minGPA, 2);
	outfile << studentID.at(minGPAIndex) << endl;
	
	// Calling function to output numbers to outfile
	print_formatted_double(outfile, maxGPA, 2);
	outfile << studentID.at(maxGPAIndex) << endl;
	
	// File closing
	infile.close();
	outfile.close();

	return 0;
}

// Function declarations
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

string read_string(ifstream& infile) {
	string tempString = "";
	infile >> tempString;
	return tempString;
}

int store_data_sets(ifstream& infile, vector<string>& studentID, vector<double>& studentGPA, vector<int>& studentClass, vector<double>& studentAge) {
	string temp = "";
	int i = 0;
	int readRecord = 0;
	double numD = 0.0;
	// While loop to loop through file
	while(!infile.eof()) {
		temp = read_string(infile);
		studentID.push_back(temp);
		numD = read_double(infile);
		studentGPA.push_back(numD);
		i = read_integer(infile);
		studentClass.push_back(i);
		numD = read_double(infile);
		studentAge.push_back(numD);
		getline(infile, temp);
		readRecord++;
	}

	// If loop for return to check if full data set has been pulled out
	if(studentID.size() == studentAge.size()) {
		return readRecord;
	} else {
		return -1;
	}
}

double calculate_sum(vector<double> vector) {
	double numD = 0.0;
	int i = 0;

	// For loop to add to sum
	for( i = 0; i < vector.size(); i++) {
		numD += vector.at(i);
	}
	
	return numD;
}

double calculate_sum(vector<int> vector) {
	int numD = 0.0;
	int i = 0;

	// For loop to add to sum
	for( i = 0; i < vector.size(); i++) {
		numD += vector.at(i);
	}
	
	return numD;
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

int calculate_count_above_mean(double mean, vector<double> studentGPA) {
	int i = 0;
	int aboveMean = 0;

	// For loop to iterate through vector
	for(i = 0; i < studentGPA.size(); i++) {

		// If loop to count above mean
		if(studentGPA.at(i) > mean) {
			aboveMean++;
		}
	}
	return aboveMean;
}

int calculate_count_below_mean(double mean, vector<double> studentGPA) {
	int i = 0;
	int belowMean = 0;

	// For loop to iterate through vector
	for(i = 0; i < studentGPA.size(); i++) {

		// If loop to count above mean
		if(studentGPA.at(i) < mean) {
			belowMean++;
		}
	}
	return belowMean;
}

void calculate_deviation(vector<double>& deviationsGPA, vector<double> studentGPA, double mean) {
	int i = 0;
	double tempD = 0.0;

	// For loop to iterate through array
	for(i = 0; i < studentGPA.size(); i++) {
		tempD = studentGPA.at(i) - mean;
		deviationsGPA.push_back(tempD);
	}
}

double calculate_variance(vector<double> vector) {
	double variance = 0.0;
	double powSum = 0.0;
	int i = 0;
	
	// For loop to iterate through vector
	for(i = 0; i < vector.size(); i++) {
		powSum += pow(vector.at(i), 2);
	}
	variance = powSum / vector.size();
	return variance;
}

double calculate_standard_deviation(double variance) {
	double standardDeviation = 0.0;
	standardDeviation = sqrt(variance);
	return standardDeviation;
}

double find_max(vector<double> vector, int& index) {
	int i = 0;
	double GPA = 0.0;

	// For loop to iterate through vector
	for(i = 0; i < vector.size(); i++) {
		
		// If statement to find max
		if(vector.at(i) > vector.at(index)) {
			index = i;
			GPA = vector.at(i);
		}
	}
	return GPA;
}

double find_min(vector<double> vector, int& index) {
	int i = 0;
	double GPA = 0.0;

	// For loop to iterate through vector
	for(i = 0; i < vector.size(); i++) {
		
		// If statement to find max
		if(vector.at(i) < vector.at(index)) {
			index = i;
			GPA = vector.at(i);
		}
	}
	return GPA;
}

void print_formatted_double(ofstream& outfile, double number, int precision) {
	outfile << fixed << setprecision(precision) << number << endl;
}

