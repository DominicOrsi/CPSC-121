/*
Name: Dominic Orsi
Class CPCS 121, Fall 2020
Date: October 19, 2020
Programming Assignments: PA5
Description: Makes a roadtrip from Seattle, WA to Denver, CO and the writes it all to roadtrip_stats.txt.
*/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ios>

using namespace std;

int main() {
	int days = 0;
	int totalDays = 0;
	int longestDays = 0;
	int waypointCounter = 0;
	double meters = 0;
	double miles = 0;
	double longestMiles = 0;
	double totalMiles = 0;
	string inputFileName = "Seattle_to_Denver_roadtrip.txt";
	string outputFileName = "roadtrip_stats.txt";
	string startCity = "";
	string cityName = "";
	string temp = "";
	string longestStay = "";
	string longestMilesName = "";
	string previousCity = "";
	string longestMilesPrevious = "";
	string longestDaysName = "";
	ifstream inFile;
	ofstream outFile;

	// Opens both files
	inFile.open(inputFileName);
	outFile.open(outputFileName);

	// Welcoming statment
	cout << "Welcome to the road trip analyzer program!\nRoadtrip origin, destination, waypoints, distance between waypoints in meters,\nand number of days spent at each waypoint will be read in from a file.\nThe program writes to an output file the distance in miles between each waypoint on the trip and statistics about the trip. Enjoy!\n\n";
	
	// Checks if file is open
	if (inFile.is_open()) {
		cout << "Successfully opened " << inputFileName << endl << endl;
	}
	else {
		cout << "Failed to open " << inputFileName << endl;
		exit(-1);
	}

	// Grab start city
	getline(inFile, startCity);
	previousCity = startCity; // Done for loop to get this city in case it is needed

	getline(inFile, temp);

	// task: read in each line of the file using getline()
	// print out the line to the console

	while (!inFile.eof()) {
		// Meters to miles work
		inFile >> meters;
		miles = meters * 0.00062137;
		totalMiles += miles;
		
		getline(inFile, temp);
		
		// City name grabbed
		getline(inFile, cityName);

		// Days grabbed and then added to total days
		inFile >> days;
		totalDays += days;
		
		// If statement for inFile.fail as when reaching destination days would fail
		if(inFile.fail()) {
			// not breaking as i am rebel and just added - 1 to things
		}

		// If else statement for longest days spent
		if (days > longestDays) {
			longestDays = days;
			longestDaysName = cityName;
		}
		
		getline(inFile, temp);
		getline(inFile, temp);
	
		// Waypoint counting
		waypointCounter++;
		
		// If statement for longest roadtrip
		if (miles > longestMiles) {
			longestMiles = miles;
			longestMilesName = cityName;
			longestMilesPrevious = previousCity;
		} 

		// Previous city to current city output to file
		outFile << previousCity << " to " << cityName << ": " << miles << " miles." << endl;		

		// Previous city added for if statement
		previousCity = cityName;

		// Reads out what waypoint is being processed 
		if (inFile.good()) {
			cout << "Proccessing waypoint " << cityName << " (" << days << " days)..." << endl;
		}
	}
	
	// Destination Out
	cout << "Roadtrip destination: " << cityName << endl << endl;
	
	
	// Outputting roadtrip stats
	outFile << "\n**Roadtrip Stats**\n";
	outFile << "Number of waypoints on roadtrip: " << waypointCounter - 1 << endl;
	outFile << "Number of days on roadtrip: " << totalDays - 1<<  endl;
	outFile << "Total miles traveled on roadtrip: " << totalMiles << endl;
	outFile << "Longest distance between waypoints on the roadtrip is " << longestMilesPrevious << " to " << longestMilesName << ": " << longestMiles << " miles" << endl;
	outFile << "Longest roadtrip days at one waypoint is " << longestDaysName << ": " << longestDays  << " days" << endl;
	outFile << "Average roadtrip distance between stops is: " << totalMiles / waypointCounter << endl;
	outFile << "Average roadtrip days at one waypoint: " << static_cast<double>(totalDays - 1) / static_cast<double>(waypointCounter - 1) << endl;
	
	// Closes both files
	cout << "Closing " << inputFileName << endl;
	inFile.close();
	outFile.close();

	return 0;
}
