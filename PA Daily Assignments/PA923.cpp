#include <iostream>

using namespace std;

int main() {
	// SW development method
	// 1. problem requirements
	// To get a desired grade from the user then their current course score,
	// and lastly the final percentage of the course grade to calculate what they need to
	// score on their final to get their desired grade.
	
	// 2. analyze the problem
	// inputs: Desired grade, minimum average required, current average in course, and final percentage.
	// outputs: Score needed on the final to achive desired grade 
	// relationships: Final weighted value divied by 100 then minus one. Times that by
	// current grade then that minus grade wanted in class. Lastly divide that by 
	// percentage weight of final exam
	
	// 3. design the algorithm (pseudocode)
	// Ask for desired letter grade from user
	// Ask user for percetnage of desired letter grade
	// Ask user for their current course grade
	// Ask the user how much the final counts as a percentage to the course grade
	// Do the math to get score needed to achive desired grade
	// Output the score needed to get desired letter grade
	
	// 4. implement the algorithm (C++)
	
	string letterGrade = "";
	double letterGradePercentage = 0.0;
	double currentGrade = 0.0;
	double finalWorth = 0.0;
	double requiredTop = 0.0;
	double requiredScore = 0.0;

	cout << "Enter desired letter grade: ";
	getline(cin, letterGrade);
	cout << "Enter minimum average required: ";
	cin >> letterGradePercentage;
	cout << "Enter  current average in course: ";
	cin >> currentGrade;
	cout << "Enter how much the final counts as a percentage toward the course grade: ";
	cin >> finalWorth;
	
	requiredTop = letterGradePercentage - ((1 - (finalWorth / 100)) * currentGrade);
	requiredScore = requiredTop / (finalWorth / 100);

	cout << "You need a score of " << requiredScore << " on the final to get a " << letterGrade << ".\n";
	
	// 5. test the completed program
	// test with values from sheet
	
	
	// 6. maintain the program

	return 0;
}
