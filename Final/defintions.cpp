/*
 Name: Dominic Orsi
 Class: CPSC 121, Fall 2020
 Lab Final Exam
 Notes:		[Insert any notes here, e.g., if you comment out code to get it to compile,
			 note the line number and what you attempted to do to fix your code]
*/

#include "header.h"

void cls(void)
{
	system("cls||clear");
	return;
}
/*LEAVE THIS FUNCTION UNMODIFIED*/

bool openInputFile(ifstream& infile, const string filename) {
	bool returnType = false;
	infile.open(filename);
	if(infile.is_open()) {
		returnType = true;
	} else {
		returnType = false;
	}
	return returnType;
}

bool openOutputFile(ofstream& outfile, const string filename) {
	bool returnType = false;
	outfile.open(filename);
	if(outfile.is_open()) {
		returnType = true;
	} else {
		returnType = false;
	}
	return returnType;
}

void displayFileStatus(bool fileStatus, const string filename) {
	if(fileStatus == true) {
		cout << filename << " was opened successfully\n";
	} else {
		cout << filename << " failed to open succesfully\n";
	}
}

void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName) {
	int i = 0;
	double d = 0;
	string temp = "";
	getline(infile, driverName);
	while(!infile.eof()) {
		getline(infile, temp);
		infile >> i;
		packageIds.push_back(i);
		infile >> d;
		packageWeights.push_back(d);
		infile >> temp;
		packageDimensions.push_back(temp);
	}
}
		
bool verifyPackagesSize(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions) {
	if(packageIds.size() == packageDimensions.size() && packageIds.size() > 0) {	
		return true;
	} else {
		return false;
	}
}

void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName) {
	int i = 0;

	cout << "Driver: " << driverName << endl;
	cout << "Number of packages: " << packageIds.size() << endl;
	cout << "Packaged Information\n__________\n";

	for(i = 0; i < packageIds.size(); i++) {
		cout << "Package Id: " << packageIds.at(i) << endl;
		cout << "Package Weight: " << fixed << setprecision(2) << packageWeights.at(i) << endl;
		cout << "Package Dimensions: " << packageDimensions.at(i) << endl;
		cout << endl;
	}
}

void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight) {
	int i = 0;
	int k = 0;
	for(i = 0; i < packageIds.size(); i++) {
		if(packageWeights.at(i) > packageWeights.at(k)) {
			k = i;
			heaviestId = packageIds.at(k);
			heaviestWeight = packageWeights.at(k);
		}
		avgWeight += packageWeights.at(i);
	}
	avgWeight = avgWeight / packageIds.size();
}

bool verifyStatsCompute(int heaviestId, double heaviestWeight, double avgWeight) {
	if(heaviestId > 0 && heaviestWeight > 0 && avgWeight > 0) {
		return true;
	} else {
		return false;
	}
}

void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight) {
	cout << "Package Stats\n__________\n";
	cout << "Id of heaviest weighted package: " << heaviestId << endl;
	cout << "Weight of heaviest package: " << fixed << setprecision(2) << heaviestWeight << endl;
	cout << "Average weight of packaged on truck: " << fixed << setprecision(2) << avgWeight << endl;
}

void writePackageInfoAndStats(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, int heaviestId, double heaviestWeight, double avgWeight) {
	int i = 0;

	outfile << "Driver: " << driverName << endl;
	outfile << "Number of packages: " << packageIds.size() << endl;
	outfile << "Packaged Information\n__________\n";

	for(i = 0; i < packageIds.size(); i++) {
		outfile << "Package Id: " << packageIds.at(i) << endl;
		outfile << "Package Weight: " << fixed << setprecision(2) << packageWeights.at(i) << endl;
		outfile << "Package Dimensions: " << packageDimensions.at(i) << endl;
		outfile << endl;
	}
	outfile << "Package Stats\n__________\n";
	outfile << "Id of heaviest weighted package: " << heaviestId << endl;
	outfile << "Weight of heaviest package: " << fixed << setprecision(2) << heaviestWeight << endl;
	outfile << "Average weight of packaged on truck: " << fixed << setprecision(2) << avgWeight << endl;
}
