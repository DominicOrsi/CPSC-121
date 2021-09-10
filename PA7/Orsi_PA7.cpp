#include <iostream>
#include <string>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Const declaration
const int ALPHABET_NUM = 26;
const int MAX_NUM = 100;

// Function prototype declarations
string read_word(ifstream& infile, string array[], int& q);
void fill_avalible_letters(char array[]);
void fill_visible_letters(char array[]);
void display_avalible_letters(char array[]);
void avalible_letters_to_space(char array[], char guessedChar);
void display_visible_letters(char array[], string word);
void tries_left(int& tries);
void avalible_letters_vs_guess(char array[], char guess);
void string_to_char_array(string word, char array[]);
int fully_complete_letters_to_word(string word, char vLArray[], char wArray[]);
int checking_if_guess_is_correct(string word, char vLArray[], char aLArray[], char guess, int wrong);

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

	word = read_word(infile, guessableWords, q);
	cout << word << " Testing\n";
	cout << q << " q\n";

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
		cout << endl;

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

// Function definitions
string read_word(ifstream& infile, string array[], int& q) {
	int	i = 0;
	int z = 0;
	string word;
	srand(time(0));

	for(z = 0; z < MAX_NUM; z++) {
		if(!infile.eof()) {
			getline(infile, array[z]);
			i++;
		}
	}
	q = (rand () % (i - 2) + 1);
	word = array[q];
	return word;
}

void fill_avalible_letters(char array[]) {
	char a = 'a';
	int z = 0;
	for(a = 'a'; a <= 'z'; a++) {
		if(z < ALPHABET_NUM) {
			array[z] = a;
		}
		z++;
	}
}

void fill_visible_letters(char array[]) {
	int z = 0;
	for(z = 0; z < MAX_NUM; z++) {
		array[z] = '-';
	}
}

void display_avalible_letters(char array[]) {
	int z = 0;
	for(z = 0; z < ALPHABET_NUM; z++) {
		cout << array[z];
	}
	cout << endl;
}

void avalible_letters_to_space(char array[], char guessedChar) {
	int z = 0;
	for(z = 0; z < ALPHABET_NUM; z++) {
		if(array[z] == guessedChar) {
			array[z] = ' ';
		}
	}
}

void display_visible_letters(char array[], string word) {
	int z = 0;
	for(z = 0; z < word.size(); z++) {
		cout << array[z];
	}
}

void tries_left(int& tries) {
	cout << "You have " << 7 - tries << " guess(es) remaining.\n";
}

void avalible_letters_vs_guess(char array[], char guess) {
	int z = 0;
	bool match = false;
	for(z = 0; z < ALPHABET_NUM; z++) {
		if(guess == array[z]) {
			match = true;
			break;
		} 
	}
	if(!match) {
			cout << "You have already guessed that letter, please enter a differnt letter\n";
			cin >> guess;
		}
}

void string_to_char_array(string word, char array[]) {
	int z = 0;
	for(z = 0; z < word.length(); z++) {
		array[z] = word.at(z);
	}
}

int fully_complete_letters_to_word(string word, char vLArray[], char wArray[]) {
	int z = 0;
	int count = 0;
	for(z = 0; z < word.length(); z++) {
		if(vLArray[z] == wArray[z]) {
			count++;
		}
	}
	return count;
}

int checking_if_guess_is_correct(string word, char vLArray[], char aLArray[], char guess, int wrong) {
	int z = 0;
	if(word.find(guess) == string::npos) {
		cout << "The letter " << guess << " is not in the word\n";
		avalible_letters_to_space(aLArray, guess);
		wrong += 1;
	} else {
		for(z = 0; z < word.length(); z++) {
			if(guess == word.at(z)) {
				cout << "Nice, " << guess << " is in the word!\n";
				cout << z << " Z\n";
				vLArray[z] = guess;
				cout << vLArray[z] << " vLArray\n";
				avalible_letters_to_space(aLArray, guess);
			} 
		}
	}
	return wrong;
}






