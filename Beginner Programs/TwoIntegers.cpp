/*
Name: Dominic Orsi
Class: CPSC 121, Fall 2020
Date: September 16, 2020
Programming Assignment: In-Class Activity 9-16
Description: Takes two integers and does addtion, subtraction, multiplication,
division, and modulus to them 
*/

#include <iostream>
#include <ios>
#include <iomanip>

using namespace std;

int main() {
	/*
	Where the variables are delcared for the code below
	*/
	int valueOne;
	int valueTwo;
	int Subtraction;
	int Addition;
	int Multiplication;
	double Division;
	int Modulus;
	/* 
	Prints out text asking for integer varaibles for the user
	*/
	cout << "Please input an integer: ";
	cin >> valueOne;
	cout << "Thank you" << endl;
	cout << "Please input another integer: ";
	cin >> valueTwo;
	cout << "Thank you" << endl;
	/*
	Does the math on the inputed variables and prints out the math being done for the user 		to see
	*/
	Addition = valueOne + valueTwo;
	cout << valueOne << " + " << valueTwo << " = " << Addition << endl;
	Subtraction = valueOne - valueTwo;
	cout << valueOne << " - " << valueTwo << " = " << Subtraction << endl;
	Multiplication = valueOne * valueTwo;
	cout << valueOne << " * " << valueTwo << " = " << Multiplication << endl;
	Division = valueOne / (static_cast<double>(valueTwo));
	cout << setprecision(2) << valueOne << " / " << valueTwo << " = " << Division << endl;
	Modulus = valueOne % valueTwo;
	cout << valueOne << " % " << valueTwo << " = " << Modulus << endl;

return 0;
}
