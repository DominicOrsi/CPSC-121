#include <iostream>

using namespace std;

int getUserHeight();
double convertInchesToCentimeters(int inches);
int calculateSnowboardLength(int heightInches);
void displaySnowboardLength(int heightInches, int snowboardCM);

int main() {
	int inches = 0;
	int heightInches = 0;
	int snowboardCM = 0;
	
	heightInches = getUserHeight();
	inches = heightInches;
	snowboardCM = calculateSnowboardLength(inches);
	displaySnowboardLength(heightInches, snowboardCM);
	return 0;
}

int getUserHeight(void) {
	int userFeet = 0;
	int userInches = 0;
	int heightInches = 0;

	cout << "Please enter height in feet: ";
	cin >> userFeet;
	cout << "Please enter height with remaining inches: ";
	cin >> userInches;

	heightInches = userInches + (userFeet * 12);
	
	return heightInches;
}

double convertInchesToCentimeters(int inches) { // Dont get this function calling inches. 
												// I am lost as to why int inches exists as a variable
	inches *= 2.54;
	
	return inches;
}

int calculateSnowboardLength(int inches) { // changed to calling inches as that is what is converted to CM
	int snowboardCM = 0;
	
	snowboardCM = inches * .88;

	return snowboardCM;
}
	
void displaySnowboardLength(int heightInches, int snowboardCM) {
	cout << "A rider of " << heightInches << " inches should get a snowboard about " << snowboardCM << " centimeters long.\n";
	
	return;
}
