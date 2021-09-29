//============================================================================
// Name        : loA4.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// Menu
	cout << "Welcome, which service would you like to use?" << endl;
	cout << "A. Temperature conversion, F to C" << endl;
	cout << "B. Temperature conversion, C to F" << endl;
	cout << "C. Number guessing game" << endl;
	cout << "D. Temperature table, F to C, freezing to boiling" << endl;
	cout << "E. Draw a rectangle" << endl;
	cout << "F. Computer names voting" << endl;
	cout << "X. Exit" << endl;

	// Ask for selection, convert to uppercase in case user inputs lowercase
	char userSelection;
	cin >> userSelection;
	char menuSelection = toupper(userSelection);

	// Menu algorithm
	while (menuSelection != 'X') {
		if (menuSelection == 'A') {
			// A. Temperature conversion, F to C
			// Ask the user to enter a temperature, in Fahrenheit.
			cout << endl << "Temperature conversion, F to C" << endl << "Enter the temperature in Fahrenheit." << endl;
			double tempFahrenheit;
			cin >> tempFahrenheit;

			// Convert the temperature from Fahrenheit to centigrade.
			double tempCentigrade = (tempFahrenheit-32) * 5/9;

			// Tell the user what that is in Centigrade.
			cout << "That temperature is " << fixed << setprecision(2) << tempCentigrade << " in centigrade." << endl << endl;

			// Show menu again
			cout << "Which service would you like to use?" << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
		else if (menuSelection == 'B') {
			// B. Temperature conversion, C to F
			// Ask the user to enter a temperature, in Centigrade.
			cout << endl << "Temperature conversion, C to F" << endl << "Enter the temperature in Centigrade." << endl;
			double tempCentigrade;
			cin >> tempCentigrade;

			// Convert the temperature from Fahrenheit to centigrade.
			double tempFahrenheit = (tempCentigrade * 9/5) + 32;

			// Tell the user what that is in Centigrade.
			cout << "That temperature is " << fixed << setprecision(2) << tempFahrenheit << " in Fahrenheit." << endl << endl;

			// Show menu again
			cout << "Which service would you like to use?" << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
		else if (menuSelection == 'C') {
			// C. Number guessing game
			// Set random seed based on current time, use % 100 + 1 to get a random number in the range 1 through 100
			srand(time(0));
			int answer = rand() % 100 + 1, guess;

			// Ask user for their guess
			cout << endl << "Number guessing game" << endl <<"A random number in the range 1 to 100 has been generated. What is your guess?" << endl;
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

			// Show results
			if (guessCounter == 1){
				cout << "Wow, you guessed the answer correctly on your first try!" << endl << endl;
			}
			else {
				cout << "Correct! It took you " << guessCounter << " tries to guess the answer correctly." << endl << endl;
			}

			// Show menu again
			cout << "Which service would you like to use?" << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
		else if (menuSelection == 'D') {
			// D. Temperature table, F to C, freezing to boiling
			cout << endl << "Temperature table, F to C, freezing to boiling" << endl;
			cout << "Fahrenheit" << right << setw(14) << "Centigrade" << endl;
			for (float tableFahrenheit = -40; tableFahrenheit <= 220;) {
				float tableCentigrade = (tableFahrenheit-32) * 5/9;
				cout << right << setw(6) << noshowpoint << fixed << setprecision(0) << tableFahrenheit << right << setw(16) << showpoint << fixed << setprecision(2) << tableCentigrade << endl;
				tableFahrenheit = tableFahrenheit + 10;
			}
			cout << endl;

			// Show menu again
			cout << "Which service would you like to use?" << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
		else if (menuSelection == 'E') {
			// E. Draw a rectangle
			// Ask the user for dimensions
			cout << endl << "Draw a rectangle" << endl << "Please enter the height." << endl;
			int rectangleHeight;
			cin >> rectangleHeight;
			cout << "Please enter the width." << endl;
			int rectangleWidth;
			cin >> rectangleWidth;

			// Drawing algorithm
			for (int height = 0; height < rectangleHeight; height++) {
				for (int width = 0; width < rectangleWidth; width++) {
					cout << "*";
				}
				cout << endl;
			}
			cout << endl;

			// Show menu again
			cout << "Which service would you like to use?" << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
		else if (menuSelection == 'F') {
			// F. Computer names voting
			cout << endl << "Computer names voting" << endl;
			int grabmaCounter = 0, ligmaCounter = 0, sugmaCounter = 0;

			// Voting algorithm
			while ( (grabmaCounter < 3) && (ligmaCounter < 3) && (sugmaCounter < 3) ) {
				cout << "Which of the following names should we call our newest model? Please choose from grabma, ligma, or sugma." << endl;
				string vote;
				cin >> vote;
				if (vote == "grabma") {
					grabmaCounter++;
					cout << "Vote recorded." << endl;
				}
				else if (vote == "ligma") {
					ligmaCounter++;
					cout << "Vote recorded." << endl;
				}
				else if (vote == "sugma") {
					sugmaCounter++;
					cout << "Vote recorded." << endl;
				}
				else {
					cout << "Sorry, that isn't one of the names." << endl;
				}
			}

			// Show winner
			if (grabmaCounter == 3) {
				cout << "Thank you for your participation, the name grabma has won with 3 votes!" << endl << endl;
			}
			else if (ligmaCounter == 3) {
				cout << "Thank you for your participation, the name ligma has won with 3 votes!" << endl << endl;
			}
			else if (sugmaCounter == 3) {
				cout << "Thank you for your participation, the name sugma has won with 3 votes!" << endl << endl;
			}

			// Show results
			cout << "Voting results:" << endl;
			cout << right << setw(2) << "" << left << setw(10) << "grabma" << grabmaCounter << endl;
			cout << right << setw(2) << "" << left << setw(10) << "ligma" << ligmaCounter << endl;
			cout << right << setw(2) << "" << left << setw(10) << "sugma" << sugmaCounter << endl << endl;

			// Show menu again
			cout << "Which service would you like to use?" << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
		else {
			cout << "Sorry, that is not a valid input. Please enter the letter that corresponds to the service you would like to use." << endl;
			cout << "A. Temperature conversion, F to C" << endl;
			cout << "B. Temperature conversion, C to F" << endl;
			cout << "C. Number guessing game" << endl;
			cout << "D. Temperature table, F to C, freezing to boiling" << endl;
			cout << "E. Draw a rectangle" << endl;
			cout << "F. Computer names voting" << endl;
			cout << "X. Exit" << endl;
			cin >> userSelection;
			menuSelection = toupper(userSelection);
		}
	}
	cout << "Thank you for using our services." << endl;
	return 0;
}
