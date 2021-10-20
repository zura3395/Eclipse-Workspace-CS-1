//============================================================================
// Name        : loA6.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 6
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

void displayMenu() {
	cout << "Which service would you like to use?" << endl;
	cout << "A. Temperature conversion, F to C" << endl;
	cout << "B. Temperature conversion, C to F" << endl;
	cout << "C. Number guessing game" << endl;
	cout << "D. Draw a rectangle" << endl;
	cout << "E. Temperature table, F to C, freezing to boiling" << endl;
	cout << "F. Computer names voting" << endl;
	cout << "X. Exit" << endl;
}

double FtoCconversion(double fahrenheit) {
	double centigrade = (fahrenheit-32) * 5/9;
	return centigrade;
}

double CtoFconversion(double centigrade) {
	double fahrenheit = (centigrade * 9/5) + 32;
	return fahrenheit;
}

int guessingGame(int upperBound) {
	// Set random seed based on current time, use % upperBound + 1 to get a random number in the range 1 through the upper bound value from the user.
	srand(time(0));
	int answer = rand() % upperBound + 1, guess;

	// Ask user for their guess
	cout << "A random number in the range 1 to " << upperBound << " has been generated. What is your guess?" << endl;
	cin >> guess;

	// Algorithm to evaluate guess and keep track of the number of guesses
	int guessCounter = 1;
	while (guess != answer) {
		if (guess > answer) {
			cout << "Your guess is too high, try again." << endl;
		}
		if (guess < answer ) {
			cout << "Your guess is too low, try again."<< endl;
		}
		cin >> guess;
		guessCounter++;
	}
	return guessCounter;
}

void drawRectangle(int rectangleHeight, int rectangleWidth) {
	// Drawing algorithm
	for (int height = 0; height < rectangleHeight; height++) {
		for (int width = 0; width < rectangleWidth; width++) {
			cout << "*";
		}
		cout << endl;
	}
	cout << endl;
}

void displayTemperatureTable() {
	cout << "Fahrenheit" << right << setw(14) << "Centigrade" << endl;
	for (float tableFahrenheit = -40; tableFahrenheit <= 220;) {
		float tableCentigrade = (tableFahrenheit-32) * 5/9;
		cout << right << setw(6) << noshowpoint << fixed << setprecision(0) << tableFahrenheit << right << setw(16) << showpoint << fixed << setprecision(2) << tableCentigrade << endl;
		tableFahrenheit = tableFahrenheit + 10;
	}
	cout << endl;
}

void nameVoting(string name1, string name2, string name3) {
	int name1Counter = 0, name2Counter = 0, name3Counter = 0;

	// Voting algorithm
	while ( (name1Counter < 3) && (name2Counter < 3) && (name3Counter < 3) ) {
		cout << "Which of the following names should we call our newest model? Please choose from " << name1 << ", " << name2 << ", or " << name3 << "." << endl;
		string vote;
		cin >> vote;
		if (vote == name1) {
			name1Counter++;
			cout << "Vote recorded." << endl;
		}
		else if (vote == name2) {
			name2Counter++;
			cout << "Vote recorded." << endl;
		}
		else if (vote == name3) {
			name3Counter++;
			cout << "Vote recorded." << endl;
		}
		else {
			cout << "Sorry, that isn't one of the names." << endl;
		}
	}

	// Show winner
	cout << "Thank you for your participation, the name ";
	if (name1Counter == 3) {
		cout << name1;
	}
	else if (name2Counter == 3) {
		cout << name2;
	}
	else if (name3Counter == 3) {
		cout << name3;
	}
	cout << " has won with 3 votes!" << endl << endl;

	// Show results
	cout << "Voting results:" << endl;
	cout << right << setw(2) << "" << left << setw(10) << name1 << name1Counter << endl;
	cout << right << setw(2) << "" << left << setw(10) << name2 << name2Counter << endl;
	cout << right << setw(2) << "" << left << setw(10) << name3 << name3Counter << endl << endl;
}

int main() {
	// Welcome user
	cout << "Welcome. ";
	displayMenu();

	// Ask for selection, convert case
	char userSelection;
	cin >> userSelection;
	userSelection = tolower(userSelection);

	// Menu algorithm
	while (userSelection != 'x') {
		if (userSelection == 'a') {
			// A. Temperature conversion, F to C
			// Ask the user to enter a temperature, in Fahrenheit.
			cout << endl << "Temperature conversion, F to C" << endl << "Enter the temperature in Fahrenheit." << endl;
			double tempFahrenheit;
			cin >> tempFahrenheit;

			// Convert the temperature from Fahrenheit to Centigrade.
			double tempCentigrade = FtoCconversion(tempFahrenheit);

			// Tell the user what that is in Centigrade.
			cout << "That temperature is " << fixed << setprecision(2) << tempCentigrade << " in centigrade." << endl << endl;

			// Show menu again
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
		else if (userSelection == 'b') {
			// B. Temperature conversion, C to F
			// Ask the user to enter a temperature, in Centigrade.
			cout << endl << "Temperature conversion, C to F" << endl << "Enter the temperature in Centigrade." << endl;
			double tempCentigrade;
			cin >> tempCentigrade;

			// Convert the temperature from Centigrade to Fahrenheit.
			double tempFahrenheit = CtoFconversion(tempCentigrade);

			// Tell the user what that is in Centigrade.
			cout << "That temperature is " << fixed << setprecision(2) << tempFahrenheit << " in Fahrenheit." << endl << endl;

			// Show menu again
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
		else if (userSelection == 'c') {
			// C. Number guessing game
			// Ask the user to enter an upper bound.
			cout << endl << "Number guessing game" << endl << "Please choose an upper bound for the game." << endl;
			int upperBound;
			cin >> upperBound;

			// Call game function
			int guesses = guessingGame(upperBound);

			// Show results
			if (guesses == 1){
				cout << "Wow, you guessed the number correctly on your first try!" << endl << endl;
			}
			else {
				cout << "Correct! It took you " << guesses << " tries to guess the number correctly." << endl << endl;
			}

			// Show menu again
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
		else if (userSelection == 'd') {
			// D. Draw a rectangle
			// Ask the user for dimensions
			cout << endl << "Draw a rectangle" << endl << "Please enter the height." << endl;
			int rectangleHeight;
			cin >> rectangleHeight;
			cout << "Please enter the width." << endl;
			int rectangleWidth;
			cin >> rectangleWidth;

			// Call drawing function
			drawRectangle(rectangleHeight, rectangleWidth);

			// Show menu again
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
		else if (userSelection == 'e') {
			// E. Temperature table, F to C, freezing to boiling
			cout << endl << "Temperature table, F to C, freezing to boiling" << endl;
			displayTemperatureTable();

			// Show menu again
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
		else if (userSelection == 'f') {
			// F. Computer names voting
			cout << endl << "F. Computer names voting" << endl;
			string name1 = "grabma", name2 = "ligma", name3 = "sugma";

			// Call voting function
			nameVoting(name1, name2, name3);

			// Show menu again
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
		else {
			displayMenu();
			cin >> userSelection;
			userSelection = tolower(userSelection);
		}
	}
	cout << "Thank you for using our services." << endl;
	return 0;
}
