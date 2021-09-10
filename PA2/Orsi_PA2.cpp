/*
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: September 27, 2020
Programming Assignment: PA2
Description: Asks questions and asks for the users input, then compares user input to determine if the answer is correct
Notes: I used this url as inspiration for the test and questions https://www.allthetests.com/quiz31/quiz/1392858965/Minecraft-Quiz
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
	string q1 = "";
	string q2 = "";
	int q3 = 0;
	int q4 = 0;
	int q5 = 0;
	int q6 = 0;
	int q7 = 0;
	string q8 = "";
	string q9 = "";
	int q10 = 0;
	int score = 0;

	// States what the test is
	cout << "Welcome to a test on your Minecraft knowledge. There are 10 questions that will test your knowledge, goodluck." << endl;
	
	// Question 1
	cout << "\nQuestion 1: What is the defualt player skin in Minecraft called? Please enter a character A-E.\n" << "A) Jane\nB) Steve\nC) Carl\nD) Frannie\nE) David\n";
	cin >> q1;
	if (q1 == "B") {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is B) Steve." << endl;
	}

	// Question 2
	cout << "\nQuestion 2: Which of these listed Mobs is always hostile to the player? Please enter a character A-E.\n" << "A) Horse\nB) Dolphin\nC) Zombie\nD) Turtle\nE) Wolf\n";
	cin >> q2;
	if (q2 == "C") {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is C) Zombie." << endl;
	}

	// Question 3
	cout << "\nQuestion 3: How many building blocks are there in Minecraft? Please enter an integer." << endl;
	cin >> q3;
	if (q3 == 145) {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is 145." << endl;
	}

	// Question 4
	cout << "\nQuestion 4: How many mobs are there in Minecraft (hostile and passive)? Please enter an integer." << endl;
	cin >> q4;
	if ( q4 == 31) {
	cout << "Correct!" << endl;	
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is 31." << endl;
	}

	// Question 5
	cout << "\nQuestion 5: A Minecraft world goes on indefinitely, true or false. Please enter 1 for true and 0 for false." << endl;
	cin >> q5;
	if (static_cast<bool>(q5) == false) {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is false." << endl;
	}

	// Question 6
	cout << "\nQuestion 6: Spiders only attack you at night, true or false. Please enter 1 for true and 0 for false." << endl;
	cin >> q6;
	if (static_cast<bool>(q6) == true) {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is true." << endl;
	}
	
	// Question 7
	cout << "\nQuestion 7: Do dolphins give you a speed boost when you are swimming near them, true or false. Please enter a 1 for true and a 0 for false." << endl;
	cin >> q7;
	if (static_cast<bool>(q7) == true) {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is true." << endl;
	}
	
	// Question 8
	cout << "\nQuestion 8: How long is the day and night cycle in Minecraft? Please enter a character A-E." << endl;
	cout <<"A) 1 Hour\nB) 30 Mins\nC) 40 Mins\nD) 20 Mins\nE) 50 Mins" << endl;
	cin >> q8;
	if (q8 == "D") {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is D) 20 Mins." << endl;
	}

	// Question 9
	cout << "\nQuestion 9: What mob was created out of a coding bug in Minecraft? Please enter a character A-E." << endl;
	cout << "A) Endermen\nB) Blaze\nC) Creeper\nD) Skeleton\nE) Cow" << endl;
	cin >> q9;
	if (q9 == "C") {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is C) Creeper." << endl;
	}

	// Question 10
	cout << "\nQuestion 10: Minecraft was created by Notch, a Swedish programmer, true or false. Please enter a 1 for true and a 0 for false." << endl;
	cin >> q10;
	if (static_cast<bool>(q10) == true) {
	cout << "Correct!" << endl;
	score = score + 1;
	} else {
	cout << "That is the wrong answer, the correct answer is true." << endl;
	}

	// Score
	if (score <= 5) {
	cout << "You scored " << score << " out of 10, you may wanna play some Minecraft to help improve your knowledge." << endl;
	} else if (score <= 8) {
	cout << "You scored " << score << " out of 10, not sure if you know your Minecraft knowledge or just a lucky guesser." << endl;
	} else {
	cout << "WOW you scored " << score << " out of 10! Congrats, a true Minecraft expert!" << endl;
	}

	return 0;
}
