/* 
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: October 9, 2020
Programming Assignments: PA3
Description: This code completes all established tasks required for PA3
Notes: I utilized code from this link, https://stackoverflow.com/questions/903221/press-enter-to-continue , to get the "Press Q to contine you" part of the code.
*/

#include<iostream>
#include<iomanip>
#include<string>
#include<limits>

using namespace std;

int main () {
	// Value declaration
	int enter = 0;
	int userIntP1 = 0;
	int forLoopA1 = 1;
	int whileLoopA1 = 1;
	int i = 1;
	int d = 1;
	int payStubs = 0;
	int userIntP3 = 0;
	int digitSum = 0;
	int digitOriginal = 0;
	int pieLoop = 0;
	int userIntP5 = 0;
	int forLoopSum = 0;
	double piNum = 1.0;
	double piApprox = 0.0;
	double payCheck = 0.0;
	double payCheckTotal = 0.0;
	string taxBracket = "";
	
	// Task 1
	cout << "Please enter an integer >= 0: ";
	cin >> userIntP1;
	// If else loop to test for int >= 0
	if(userIntP1 >= 0) {
	// While loop
	while(i <= userIntP1) {
	whileLoopA1 *= i;
	++i;
	}
	cout << "While loop solution: " << userIntP1 << "! = " << whileLoopA1 << endl;
	// For loop
	for(i = 1; i <= userIntP1; ++i) {
	forLoopA1 *= i;
	}
	cout << "For loop solution: " << userIntP1 << "! = " << forLoopA1 << endl;
	} else {
	cout << "Integer entered is not >= 0.\n";
	}

	// Q to continue
	cout << "\nPress Q to Continue: ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'Q');
	cout << endl;

	// Task 2
	cout << "Please enter number of pay stubs: ";
	cin >> payStubs;
	// For loop for pay stubs #
	for(i = 1; i <= payStubs; ++i) {
	cout << "Please enter amount for pay stub #" << i << ": ";
	cin >> payCheck;
	payCheckTotal += payCheck;
	}
	// If else loop for tax bracket
	if(payCheckTotal <= 15000) {
	taxBracket = "low income";
	} else if(payCheckTotal <= 200000) {
	taxBracket = "medium income";
	} else {
	taxBracket = "high income";
	}
	// Outputs which tax bracket loop is in
	cout << "Total salary for the year: $" << payCheckTotal << 	" Tax bracket: " << taxBracket << endl;
	
	// Q to continue
	cout << "\nPress Q to Continue: ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'Q');
	cout << endl;

	// Task 3
	cout << "Enter an integer to sum the digits of: ";
	cin >> userIntP3;
	digitOriginal = userIntP3;
	// for loop to get digits sum
	for(i = -10; i <= userIntP3; i++) {
	digitSum = digitSum + (userIntP3 % 10);
	userIntP3 /= 10;
	}
	// Outputs sum of digits in int
	cout << "Sum of " << digitOriginal << " is: " << digitSum << endl;
	
	// Q to continue
	cout << "\nPress Q to Continue: ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'Q');
	cout << endl;

	// Task 4
	cout << "Please enter the number of terms to approximate pi: ";
	cin >> pieLoop;
	// For loop for pie
	for(i = 0; i < pieLoop; ++i) {
	// if else to assign - and +
	if(i % 2 == 0) {
	piApprox = piApprox + 4.0/piNum;
	} else {
	piApprox = piApprox - 4.0/piNum;
	}
	piNum += 2;
	}
	cout << "Pi approximation: " << piApprox << endl;

	// Q to continue
	cout << "\nPress Q to Continue: ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'Q');
	cout << endl;

	// Task 5
	cout << "Please enter an integer: ";
	cin >> userIntP5;
	cout << "\nPart 1 of Task 5.\n";
	// For loop to print int
	for(i = 1; i <= userIntP5; ++i) {
		for(d = 1; d <= i; ++d) {
		cout << i;
		}
	cout << endl;
	}
	cout << "\nPart 2 of Task 5.\n";
	for(i = 1; i <= userIntP5; ++i) {
		for(d = 1; d <= i; ++d) {
		cout << i;
		forLoopSum = i + forLoopSum;
		}
	cout << " " << forLoopSum << endl;
	forLoopSum = 0;
	}

	// Q to End
	cout << "\nPress Q to End: ";
	cin.ignore(std::numeric_limits<streamsize>::max(),'Q');

	// Ending
	cout << "Program is done running.\n";


	return 0;
}
