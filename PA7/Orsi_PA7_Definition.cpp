/*
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: November 2, 2020
Programming Assignment: PA7
Notes: Function Delcarations and Definition.cpp  file of Orsi_PA7
*/
#include "Orsi_PA7.h"
/*
Function: read_word () 
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: This function takes infile, string array, and a pass through reference int q. It then pulls a random word out of the infile that was put in the string array. Q is passed by reference so that string array knows what word was pulled out
Returns: string word
Pre: The infile's contents are seperate from the array  
Post: Each part of the array has a string and then it choses a random one
*/
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
/*
Function: fill avalible letters
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: fills an array with the alphabet
Returns: nothing
Pre: Array is mismash of unassinged chars
Post: Puts chars into order of the alphabet
*/
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
/*
Function: fill visible letters
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Takes an array an fills it with dashes -
Returns: nothing
Pre: Array of mismash chars
Post: Fills in array with dashes
*/
void fill_visible_letters(char array[]) {
	int z = 0;
	for(z = 0; z < MAX_NUM; z++) {
		array[z] = '-';
	}
}
/*
Function: display avalible letters
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Prints out avalible letters array
Returns: nothing
Pre: array is not printed out
Post: Array is printed out
*/
void display_avalible_letters(char array[]) {
	int z = 0;
	for(z = 0; z < ALPHABET_NUM; z++) {
		cout << array[z];
	}
	cout << endl;
}
/*
Function: avalible letters to space
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Takes chars in array and turns them into spaces if the guessed char is the same as it
Returns: nothing
Pre: Alphabet array and guessed char taken in
Post: Alphabet array has a space where guessed char was
*/
void avalible_letters_to_space(char array[], char guessedChar) {
	int z = 0;
	for(z = 0; z < ALPHABET_NUM; z++) {
		if(array[z] == guessedChar) {
			array[z] = ' ';
		}
	}
}
/*
Function: displat visible lettters
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: takes visible letters array and prints out aonly as many as the word is long
Returns: nothing
Pre: Array and word are taken in
Post: Array is printed out to the length of the word
*/
void display_visible_letters(char array[], string word) {
	int z = 0;
	for(z = 0; z < word.size(); z++) {
		cout << array[z];
	}
}
/*
Function: tries left
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Prints out how many tires you have left to guess
Returns:  none
Pre: takes in reference int tries
Post: Prints out how many tries you have left and subracts tries to 7
*/
void tries_left(int& tries) {
	cout << "You have " << 7 - tries << " guess(es) remaining.\n";
}
/*
Function: Avalible letters vs guess
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Takes in the guessed char and alphabet array and checks to see if the char was already guessed
Returns: none
Pre: Alphabet array and guessed char 
Post: Tells you whether or not you already guessed that char/letter
*/
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
		for(z = 0; z < ALPHABET_NUM; z++) {
			if(guess == array[z]) {
				match = true;
				break;
			} 
		}
	}
}
/*
Function: string to char array
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Takes in word and array and splits the words letters into there respective parts in the array
Returns: none
Pre: Array and word with array being blank
Post: Array has the words letters in their repective spots on it
*/
void string_to_char_array(string word, char array[]) {
	int z = 0;
	for(z = 0; z < word.length(); z++) {
		array[z] = word.at(z);
	}
}
/*
Function: fully complete letters to word
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: takes in word, visible letters array and word array to then check and see if you have guessed all the letters correctly
Returns: Count
Pre: Visible letter array and word array are sperate and not compared
Post: Compares visible letter array to word array to check if all the letters are correct and if they word is complete
*/
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
/*
Function: checking if guessing is correct
Date Created: 11/11/20  
Date Last Modified: 11/11/20 
Description: Takes in word, visible letter array, avalible letter array, char guess and, int wrong
Returns: Wrong
Pre: All the arrays and char and sperate and not compared
Post: Compares the word and guess char to see if letter is in the word. If so it then replaces visible array part with the char in the correct spot and then puts a space where the char would be on the avalible letters array. While if the letter is not on the word it says that and also removes it from the avalible letters and adds 1 to wrong.
*/
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
				vLArray[z] = guess;
				avalible_letters_to_space(aLArray, guess);
			} 
		}
	}
	return wrong;
}

