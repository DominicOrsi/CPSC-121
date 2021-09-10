#include "SnowboardLengthFun.h"

int main() {

	int userHeight = 0;
	double userHeightCM = 0.0;
	int snowboardLength = 0;

	// main() is the calling function for this call getUserHeight()
	userHeight = getUserHeight();
	// main() is the calling function for this call to convertInchesToCM()
	userHeightCM = convertInchesToCM(userHeight);

	cout << "height in cm: " << userHeightCM << endl;

	snowboardLength = calculateSnowboardLength(userHeightCM);
	displaySnowboardLength(userHeightCM, snowboardLength);

	return 0;
}
