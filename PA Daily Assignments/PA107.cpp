#include<iostream>
#include<cstdlib>

using namespace std;

int main() {
	int diceRolls = 0;
	int whileLoopA = 0;
	int forLoopA= 0;
	int diceSide = 0;
	int i = 0;
	int userInt = 0;
	int numTwo = 0;
	int d = 1;
	int f = 0;
	
	srand(time(0));
	
	// Dice
	cout << "Enter number of dice rolls: ";
	cin >> diceRolls;
	// while loop
	while(i < diceRolls) {
	diceSide = (rand () % (6 - 1 + 1)) + 1;
	cout << "Dice rolled: " << diceSide << endl;
	i++;
	}
	// for loop
	cout << endl; // On purpose to different while loop output to for loop output
	for(i = 1; i <= diceRolls; ++i) {
	diceSide = (rand () % (6 - 1 + 1)) + 1;
	cout << "Dice rolled: " << diceSide << endl;
	}
	
	// IDK what this is but task 2
	cout << "Please enter a value: ";
	cin >> userInt;
	i = 0;
	// while loop
	while(i < userInt) {
	d = 1 + i + f;
	cout << i << "   " << d << endl;
	++i;
	++f;
	}
	f = 0;
	cout << endl;
	// for loop
	for(i = 0; i < userInt; ++i) {
	d = 1 + i + f;
	cout << i << "   " << d << endl;
	++f;
	}

	return 0;
}
