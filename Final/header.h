/*
 Name: Dominic Orsi
 Class: CPSC 121, Fall 2020
 Lab Final Exam
 Notes:		[Insert any notes here, e.g., if you comment out code to get it to compile,
			 note the line number and what you attempted to do to fix your code]
*/

#ifndef header_H
#define header_H

//Required includes -- you should be able to complete this exam without additional includes
// and you should not modify/remove any of these!
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <ios>
#include <iomanip>

using namespace std;

//enumerated data type used for menu option selections
enum MenuOptions { OPEN_INPUT_FILE = 1, OPEN_OUTPUT_FILE, READ_TRUCK_DATA, DISPLAY_PACKAGE_INFO, COMPUTE_PACKAGE_STATS, DISPLAY_PACKAGE_STATS, DISPLAY_ALL_DATA, WRITE_ALL_DATA, ORDER66, EXIT_PGM };

//required prototype - leave unmodified. You must still place this in it's proper file
void cls(void); //function clears screen on both Linux and Windows OSes

//required function prototypes
bool openInputFile(ifstream& infile, const string filename);
bool openOutputFile(ofstream& outfile, const string filename);
void displayFileStatus(bool fileStatus, const string filename);
void processPackages(ifstream& infile, vector<int>& packageIds, vector<double>& packageWeights, vector<string>& packageDimensions, string& driverName);
bool verifyPackagesSize(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions);
void displayPackageInformation(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName);
void computePackageStats(vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, int& heaviestId, double& heaviestWeight, double& avgWeight);
bool verifyStatsCompute(int heaviestId, double heaviestWeight, double avgWeight);
void displayPackageStats(int heaviestId, double heaviestWeight, double avgWeight);
void writePackageInfoAndStats(ofstream& outfile, vector<int> packageIds, vector<double> packageWeights, vector<string> packageDimensions, const string driverName, int heaviestId, double heaviestWeight, double avgWeight);

/*OPTIONAL - if you implement any extra functions include them BELOW the required functions
			ALSO make note in your note comment block at the top of the file(s) that you have
			created additional function prototypes/definitions

	POSSIBLE ADDITIONAL FUNCTION PROTOTYPES (not required to complete this program)
*/

#endif
