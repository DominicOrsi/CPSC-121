/*
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: September 20, 2020
Programming Assignment: PA1
Description: Chat bot that asks for name and later on dream car and price. Then computes a loan payment for that car.
Notes: Extra credit was attempted
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
	string userName = "";
	string userFrom = "";
	string userCar = "";
	string trashBin = "";
	int yearBorn = 0;
	int userAge = 0;
	int botAge = 3;
	int carPrice = 0;
	int loanYears = 0;
	int totalPrice = 0;
	int n = 0;
	double carMPG = 0;
	double yearsOlder = 0.0;
	double annualI = 0.0;
	double monthlyI = 0.0;
	double monthlyPaymentTop = 0.0;
	double monthlyPaymentBottom = 0.0;
	double monthlyPaymentTotal = 0.0;

	cout << "Heyo! My name is Box Bot. What is your name?" << endl;
	// Introduces Bot and asks name
	getline(cin, userName);
	cout << "Hello " << userName << ", it is nice to meet you." << endl; 
	// Greats them
	cout << "Where are you from " << userName << "?" << endl;
	getline(cin, userFrom);
	// Gets location of user
	cout << userFrom << " is a really nice place, I have always wanted to visit there.";
	cout << endl;
	// Talks to user about location
	cout << "What year were you born in " << userName << "?" << endl;
	cin >> yearBorn;
	userAge = 2020 - yearBorn;
	// Gets users age from year born
	yearsOlder = userAge / (static_cast<double>(botAge));
	// Divides users age to bots age to get how man times they are older than bot
	cout << "You are " << userAge << " years old, which makes you ";
	cout << yearsOlder << " times older than me! I am only ";
	cout << botAge << " years old!" << endl;
	// Sets decimal place to 2 and returns users age compared to bots age
	cout << "What is your dream car?" << endl;
	getline(cin,trashBin);
	getline(cin, userCar);
	// Gets users dream car
	cout << "I really like the " << userCar << ", what is its MPG?" << endl;
	cin >> carMPG;
	if( carMPG >= 34.1) {
	cout << "Awesome, it exceeds the US Governments new MPG expectations." << endl;
	} else {
	cout << "Sadly this car doesn't meet the US Governments new MPG expectations of 34.1 MPG." << endl;
	} 
	// Gives a statement on MPG
	cout << "How much does " << userCar << " cost?" << endl;
	cin >> carPrice;
	// Gets cars price from user
	if( carPrice < 30000) {
	cout << "Wow that is a pretty good price!" << endl;
	} else if( carPrice < 60000) {
	cout << "That is a little pricy but still manageable." << endl;
	} else if( carPrice < 100000) {
	cout << "Oh man, that is a lot of money!" << endl;
	} else {
	cout << "Could probaly put a down payment on a house with that amount of money!" << endl;
	}
	// Gives a statement based off price
	cout << "How many years would you take a loan out for " << userCar << "." << endl;
	cin >> loanYears;
	// Gets loan length
	cout << "What is the annual intrest(%) on a " << loanYears << " year long loan for a(n) ";
	cout << userCar << "." << endl;
	cin >> annualI;
	// Gets annual intrest on the loan
	n = loanYears * 12;
	// Gets n for pow function
	monthlyI = (annualI / 100) / 12;
	monthlyPaymentTop = monthlyI * (static_cast<double>(carPrice));
	monthlyPaymentBottom = 1 - pow(1 + monthlyI, -n);
	monthlyPaymentTotal = monthlyPaymentTop / monthlyPaymentBottom;
	totalPrice = (monthlyPaymentTotal * 12) * loanYears;
	// Does monthly payment formula
	cout << "Your monthly payment would be $" << monthlyPaymentTotal << ", if you bought ";
	cout << userCar << "." << " That is a total of $" << totalPrice << "!" << endl;
	cout << "It was nice talking with you " << userName << "!" << endl;
	return 0;
}
