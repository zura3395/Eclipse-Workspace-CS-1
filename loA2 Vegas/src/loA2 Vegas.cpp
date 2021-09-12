//============================================================================
// Name        : loA2.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
	cout << "Part 4: Las Vegas Dice Game" << endl;

	// Set random seed based on current time
	srand(time(NULL));

	// Roll two dice with % 6 + 1 to get a die value in the range 1 through 6 inclusive
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int roll1Total = die1 + die2;

	// Show user the values of each die and their total
	cout << "You rolled " << die1 << " for the first die and " << die2 << " for the second die." << endl;
	cout << "You got a total of " << roll1Total << " points." << endl;

	// Evaluate result based on the total points
	// Lose condition
	if((roll1Total == 2) || (roll1Total == 3) || (roll1Total == 12)){
		cout << endl << "Sorry, you lost.";
	}
	// Win condition
	else if((roll1Total == 7) || (roll1Total == 11)){
		cout << endl << "Congratulations, you won!";
	}
	// Reroll condition, show new values
	else {
		int die1 = rand() % 6 + 1;
		int die2 = rand() % 6 + 1;
		int roll2Total = die1 + die2;

		cout << endl << "You rolled again and got " << die1 << " for the first die and " << die2 << " for the second die." << endl;
		cout << "You got a total of " << roll2Total << " points." << endl;

		// Lose condition
		if((roll2Total != roll1Total)){
			cout << endl << "Sorry, you lost.";
		}

		// Win condition
		else {
			cout << endl << "Congratulations, you won!";
		}
	}

	return 0;
}
