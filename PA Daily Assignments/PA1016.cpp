#include <iostream>

using namespace std;

double getGradePoint(void);
int getCredit(void);
double computeWeightedCredits(double gpa1, double gpa2, double gpa3, int numCredits1, int numCredits2, int numCredits3);
int computeTotalCredits(int numCredits1, int numCredits2, int numCredits3);
double computeGPA(double weightedCredits, int totalCredits);
void displayGPA(double gpa);

int main() {
	double gp1, gp2, gp3, weightedCredits, gpa;
	int numCredits1, numCredits2, numCredits3, totalNumCredits;

	gp1 = getGradePoint();
	numCredits1 = getCredit();
	gp2 = getGradePoint();
	numCredits2 = getCredit();
	gp3 = getGradePoint();
	numCredits2 = getCredit();

	weightedCredits = computeWeightedCredits(gp1, gp2, gp3, numCredits1, numCredits2, numCredits3);

	totalNumCredits = computeTotalCredits(numCredits1, numCredits2, numCredits3);

	gpa = computeGPA(weightedCredits, totalNumCredits);

	displayGPA(gpa);

	return 0;
}

double getGradePoint(void) {
	double gp = 0.0;
	cout << "Please enter the grade for your course." << endl;
	cin >> gp;

	return gp;
}

int getCredit(void) {
	int credit = 0;
	cout << "Please enter a number of credits for your course." << endl;
	cin >> credit;

	return credit;
}

double computeWeightedCredits(double gpa1, double gpa2, double gpa3, int numCredits1, int numCredits2, int numCredits3) {
	double weightedCredits = 0.0;
	weightedCredits = (numCredits1 * gpa1) + (numCredits2 * gpa2) + (numCredits3 * gpa3);

	return weightedCredits;
}

int computeTotalCredits(int numCredits1, int numCredits2, int numCredits3) {
	
	return numCredits1 + numCredits2 + numCredits3;
}

double computeGPA(double weightedCredits, int totalCredits) {
	
	return weightedCredits / totalCredits;
}

void displayGPA(double gpa) {
	cout << "Your GPA is: " << gpa << endl;
	return;
}

