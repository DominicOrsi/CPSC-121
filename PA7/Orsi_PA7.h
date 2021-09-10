/*
Name: Dominic Orsi
Class: CPCS 121, Fall 2020
Date: November 11, 2020
Programming Assignment: PA7
Notes: Header File
*/
#ifndef Orsi_PA7_H
#define Orsi_PA7_H

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

#endif
