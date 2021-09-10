/*
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: November 11, 2020
Programming Assignment: PA7
Notes: See inline comments and this is the Main.cpp of Orsi_PA7
*/
#include "Orsi_PA7.h"

int main() {
	int q = 0;
	int triesWrong = 0;
	int correct = 0;
	char guess = ' ';
	char avalibleLetters[ALPHABET_NUM];
	char visibleLetters[MAX_NUM];
	char wordArray[MAX_NUM];
	string guessableWords[MAX_NUM];
	string word = "";
	string inputFileName = "HangmanWords.txt";
	ifstream infile;
	
	// Open file
	infile.open(inputFileName);

	// Function to read word on infile
	word = read_word(infile, guessableWords, q);

	// Function to fill avalible letters with a-z
	fill_avalible_letters(avalibleLetters);

	// Function to fill visible letters with -
	fill_visible_letters(visibleLetters);

	// Fuction string to char array
	string_to_char_array(word, wordArray);
	
	// Telling us word length
	cout << "The word is " << word.size() << " letters long.\n";

	// While loop for guessing the word
	while(triesWrong < 7 && correct != word.length()) {
		cout << endl;

		// Function to display visible letters
		display_visible_letters(visibleLetters, word);
		cout << endl;

		// Function to display avalible letters
		cout << "Avalible letters: ";
		display_avalible_letters(avalibleLetters);

		// Function to display guesses left
		tries_left(triesWrong);

		// Function to check guess
		cout << "Please enter your guess: \n";
		cin >> guess;
		avalible_letters_vs_guess(avalibleLetters, guess);

		// Function to check if guess is correct  
		triesWrong = checking_if_guess_is_correct(word, visibleLetters, avalibleLetters, guess, triesWrong);

		// Fucntion to see if word guessed is correct yet
		correct = fully_complete_letters_to_word(word, visibleLetters, wordArray);
	}

	// If else for winning or lossing
	if(correct == word.length()) {
		cout << "Congrats, you guessed the word!\n";
	} else {
		cout << "You didn't guess the word.\n";
	}
	
	
	return 0;
}







