#include "SnowboardLengthFun.h"

int getUserHeight(void) {
	int feet, inches, totalInches;

	cout << "Enter your height in feet and inches: ";
	cin >> feet >> inches;
	totalInches = feet * INCHES_IN_FEET + inches;

	return totalInches;
}

double convertInchesToCM(int inches) {
	return inches * CM_IN_INCH;
}

int calculateSnowboardLength(int heightInches) {
	int length = 0;

	// rounds or truncates??
	length = heightInches * SNOWBOARD_HEIGHT_PERCENTAGE;

	return length;
}

void displaySnowboardLength(int height, int length) {
	cout << "If you are " << height << "cm tall, you should ride a " << length << "cm snowboard" << endl;
}


