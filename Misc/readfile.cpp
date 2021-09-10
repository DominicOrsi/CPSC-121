#include <iostream> 
#include <string>
//1. We need to include fstream
#include <fstream>


using namespace std;
 
int main ()
{	
	string filename = "words.txt";
	string inputText = "";
	int userInt = 0;
	int i = 0;
	
	//2. we need to declare a new stream variable
	ifstream inputFile;	
	
	//3. we need to open the file for reading
	inputFile.open(filename);

	cout << "Enter an integer: ";
	cin >> userInt;

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
		for(i = 0; i < userInt; ++i) {
			getline(inputFile, inputText);

			//What happens if we don't use .good() ?
			//cout << inputText << endl;
			//This did not handle the last line, why?
			if(inputFile.good()) //only manupulate if we did not reach EOF
			{
				cout << inputText << endl;
			}
		}

		//6. Don't forget to close your files!
		inputFile.close();
	}
		
	
	return 0;
} 
