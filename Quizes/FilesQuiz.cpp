#include <iostream> //needed for cin/cout
#include <string> //needed for string functions, e.g. getline
#include <fstream> //needed for file IO
#include <iomanip> //needed for output formatting
#include <ios> //needed for output formatting

using namespace std;

int main() {
	string endMessage = "";
	string trashBin = "";
	string driversName = "";
	string store = "";
	int time = 0;
	int timeCount = 0;
	int truckCount = 0;
	int dropOffTime = 0;
	string inputFileName = "trucks.txt";
	string outputFileName = "truck-destination.txt";
	ifstream infile;
	ofstream outfile;
	
	infile.open(inputFileName);
	outfile.open(outputFileName);
	
	if(!infile.is_open()) {
		return -1;
	}

	outfile << "Truck Drop-offs Report\n";	
	
	while(!infile.eof()) {	

	if(infile.fail()) {
		cout << "We are done\n";
		endMessage = trashBin;
		break;
	}

	getline(infile, driversName);
	getline(infile, store);
	infile >> time;
	infile >> trashBin;
	truckCount++;
	timeCount += time;

	outfile << store << endl;
	}
	
	dropOffTime =  timeCount / truckCount;	
	
	outfile << "\nNumber of Trucks: " << truckCount << endl;
	outfile << "Average Drop-off Time: " << dropOffTime;
	return 0;
}

