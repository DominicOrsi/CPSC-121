#include<iostream>

using namespace std;

int main () {
	int i = 0;
	int n = 0;
	int diceFour = 0;
	int diceTen = 0;
	
	cout << "Enter number of dice rolls: ";
	cin >> n;
	srand(time(0));
		
	for(i = 0;	i < n; i++) {
	diceFour = (rand () % (4 - 1 + 1)) + 1;
	diceTen = (rand () % (10 - 1 + 1)) + 1;
	cout << "You rolled a " << diceFour << " (out of 4) and a " << diceTen << " (out of 10).\n";
	}

	return 0;
}
