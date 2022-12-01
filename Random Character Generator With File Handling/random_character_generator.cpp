#include <iostream>   
#include <fstream>  
#include <cstdlib>  // for functions rand() and srand() 
#include "random_character_generator.h"
using namespace std;


void run()
{
	int choice;
	bool quit = false;

	while (!quit) 
	{   
		printMenu();
		cin >> choice;

		switch (choice) 
		{
		case 1:
			generateAndSaveInFile();
			break;
		case 2:
			readFromFile();
			break;
		case 3:
			quit = true;
			cout << "\nYou chose to quit the program...\n";
			break;
		default:
			cout << "Incorrect number picked. Please try again...\n";
		}
	}
}

void printMenu()
{
	cout << "\n\nChoose one of the following options:\n"
		<< "\t1) Generate random letters and save them in file letters.txt\n"
		<< "\t2) Read all the letters from letters.txt and print them on the screen\n"
		<< "\t3) Quit the program\n\n"
		<< "\tWhat is your choice? ";
}

void generateAndSaveInFile() {
	char charArray[15];

	srand(time(0));   // seeding rand() generator to make sure that it generates a different set of numbers each time it is used (it would otherwise always generate the same numbers as per program instance)
	int randomNumber;

	for (int i = 0; i < 15; i++) {
		do
		{
			randomNumber = (rand() % 58) + 65;    // to start from ASCII 65 (letter 'A') and to set up a span of 58 positions (65 + 58 = 123) keeping in mind that modulo 58 can only reach 57 as a result (which in fact is a desired span)
		} while (randomNumber > 90 && randomNumber < 97);    // excluding ASCII letters 91-96 (they are not letters; as per design the program should only generate letters)

		charArray[i] = (char)randomNumber; 
	}

	ofstream file("letters.txt");  // it creates a new letters.txt file if it did not exist earlier or it opens an existing letters.txt

	if (!file) {    
		cout << "An error occurred during attempt to open file letters.txt\nPlease try again" << endl;
		return;
	}

	for (int i = 0; i < 15; i++) {
		if (!file.put(charArray[i])) {  
			cout << "An error occurred during an attempt to write to file letters.txt\n";
			return;
		}
	}

	if (file) {    // final check whether any of stream error flags has been set
		cout << "\nRandom letters array has been successfully generated and saved to file letters.txt";
	}
}


void readFromFile() {
	ifstream file("letters.txt");  

	if (!file) {   // in case the desired file does not yet exist
		cout << "\nAn error occurred during the attempt to open file letters.txt. Please make sure that this file exists by first choosing option 1)\n";
		return;
	}


	cout << "The current set of 15 randomly generated letters in the file letters.txt is as follows:\n\t";
	char letter;
	while (file.get(letter)) {  
		cout << letter;
	}

	if (!file.eof()) {  // if above reading of file characters has been completed but somehow the end of file has not yet been reached
		cout << "\nAn error occurred when reading from letters.txt\n";
	}
}