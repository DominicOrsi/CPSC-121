#include <iostream> 
#include <string>
//1. We need to include fstream
#include <fstream>


using namespace std;
 
int main ()
{	
	//input file
	string filename = "words.txt";
	
	//output file
	string filenameOut = "words_copy.txt";

	//other local variables
	string inputText = "";
	int count = 1;
	
	//2. we need to declare a new stream variable
	ifstream inputFile;	//input
	ofstream outputFile; //output
	
	//3. we need to open the file for reading
	inputFile.open(filename); //input
	outputFile.open(filenameOut); //output
	//append? use fstream::app as the second argument for open()
	//outputFile.open(filenameOut, fstream::app); //output

	//4. we need to make sure our file opened successfully
	if(!inputFile.is_open())
	{
		//if our input file is not open
		cout << "File failed to open, exiting program..." << endl;
	}
	else if(inputFile.fail())
	{
		//alternate method to test if our file failed to be opened
		cout << "File failed to open, exiting program..." << endl;
	}
	else
	{
		//our file was opened successfully!
		//5. Manipulate our file
		//read from the file until we reach the end of file marker
		while (!inputFile.eof())
		{
			getline(inputFile, inputText);

			//What happens if we don't use .good() ?
			//cout << inputText << endl;
			//This did not handle the last line, why?
			if(inputFile.good()) //only manupulate if we did not reach EOF
			{
				cout << inputText << endl;
				//write the same line to our output file
				outputFile << "Read line " << count++ << " :" << inputText << endl;
			}
		}

		//6. Don't forget to close your files!
		inputFile.close();
		outputFile.close();
	}
		
	
	return 0;
} 
