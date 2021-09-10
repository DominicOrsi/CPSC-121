/*
 Name: Dominic Orsi
 Class: CPSC 121, Fall 2020
 Lab Final Exam
 Notes:		[Insert any notes here, e.g., if you comment out code to get it to compile,
			 note the line number and what you attempted to do to fix your code]
*/

#include "header.h"

//program main
int main()
{
	//package contains
	/*
		int id;
		double weight;
		string dimensions; //LxWxH
	*/

	//Parallel Vectors
	vector<int> packageIds;
	vector<double> packageWeights;
	vector<string> packageDimensions;
	//Input and Output stream variables
	ifstream infile;
	ofstream outfile;
	//string variables
	string inputFilename = "truckload.txt", outputFilename = "truckloadstats.txt", driverName = "";
	//stats variables
	int heaviestId = 0;
	double heaviestWeight = 0, avgWeight = 0;
	//menu choice variable
	int userMenuSelection = -1;
	//keeping track of file open status
	bool inputFileIsOpen = false, outputFileIsOpen = false;
	//keeping track of validating data
	bool packageDataAreValid = false, packageStatsAreValid = false;

	//MENU LOOP
	do
	{
		do
		{
			cout << "\nPlease choose from the following menu (1-9) to handle truck load processing.\n";
			cout << "1) Open input file for reading\n";
			cout << "2) Open output file for writing\n";
			cout << "3) Read in truck file and process data\n";
			cout << "4) Display the package information\n";
			cout << "5) Compute package statistics for the current truck load\n";
			cout << "6) Display package statistics for the current truck load\n";
			cout << "7) Display the package information AND package statistics\n";
			cout << "8) Write the package information AND package statistics to the output file\n";
			cout << "9) Generate a programming joke\n";
			cout << "10) Quit\n";
			cout << ">> ";
			cin >> userMenuSelection;
			if (userMenuSelection > 10)
			{
				cls(); //clears the screen
				cout << "Invalid Option\n";
			}
		} while (userMenuSelection < 1 || userMenuSelection > 10);
		cout << "\n";
		cls(); //clears the screen

		/* START HINT BLOCK
		-:HINT:-

				 ██╗  ██╗██╗███╗   ██╗████████╗
			  ██╗██║  ██║██║████╗  ██║╚══██╔══╝██╗
		█████╗╚═╝███████║██║██╔██╗ ██║   ██║   ╚═╝█████╗
		╚════╝██╗██╔══██║██║██║╚██╗██║   ██║   ██╗╚════╝
			  ╚═╝██║  ██║██║██║ ╚████║   ██║   ╚═╝
				 ╚═╝  ╚═╝╚═╝╚═╝  ╚═══╝   ╚═╝

		For each of the following case statements you  should ONLY need
		to write a combinations of

		1) function calls
		2) if-else statements
		3) cout statements

		END HINT BLOCK*/

		switch (static_cast<MenuOptions>(userMenuSelection))
		{
		case OPEN_INPUT_FILE: //Open input file for reading
			inputFileIsOpen = openInputFile(infile, inputFilename);
			displayFileStatus(inputFileIsOpen, inputFilename);
			//(BONUS) read filename from user input
			break;
		case OPEN_OUTPUT_FILE: //Open output file for writing
			outputFileIsOpen = openOutputFile(outfile, outputFilename);
			displayFileStatus(outputFileIsOpen, outputFilename);
			//(BONUS) read filename from user input
			break;
		case READ_TRUCK_DATA: //Read in truck file for processing
			processPackages(infile, packageIds, packageWeights, packageDimensions, driverName);
			packageDataAreValid = verifyPackagesSize(packageIds, packageWeights, packageDimensions);
			break;
		case DISPLAY_PACKAGE_INFO: //Display the package information in forward order
			displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName);
			break;
		case COMPUTE_PACKAGE_STATS: //Compute package statistics for the current truck load
			computePackageStats(packageIds, packageWeights, packageDimensions, heaviestId, heaviestWeight, avgWeight);
			packageStatsAreValid = verifyStatsCompute(heaviestId, heaviestWeight, avgWeight);
			break;
		case DISPLAY_PACKAGE_STATS: //Display package statistics for the current truck load
			displayPackageStats(heaviestId, heaviestWeight, avgWeight);
			break;
		case DISPLAY_ALL_DATA: //Display the package information in forward order AND statistics about the packages
			displayPackageInformation(packageIds, packageWeights, packageDimensions, driverName);
			displayPackageStats(heaviestId, heaviestWeight, avgWeight);
			break;
		case WRITE_ALL_DATA: //Write the package information in forward order AND statistics about the packages to an output file
			writePackageInfoAndStats(outfile, packageIds, packageWeights, packageDimensions, driverName, heaviestId, heaviestWeight, avgWeight);
			break;
		case ORDER66:
			//Does nothing unless you want it to :-)
			cout << "This starter code...\n Ba dum tsss!";
			//https://www.youtube.com/watch?v=ObpcGNCU944
			break;
		case EXIT_PGM:
			//Do nothing, we will exit the loop
			break;
		default:
			cout << "Invalid Option\n";
			break;
		}

	} while (userMenuSelection != 10);

	//CLOSE FILES

	return 0;
}
