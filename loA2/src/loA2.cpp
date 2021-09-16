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
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	// Part 1
	cout << "Part 1: Interest Calculator" << endl;

	// Ask user for principal
	double principal;
	cout << "Please enter the principal:" << endl;
	cin >> principal;

	// Ask user for interest rate percentage
	double interestRatePercentage;
	cout << "Please enter the interest rate percentage:" << endl;
	cin >> interestRatePercentage;

	// Calculations
	double interestRate = interestRatePercentage/100;
	double annualInterest = principal * interestRate;
	double annualBalance = principal + annualInterest;
	double dailyInterest = principal * pow( (1 + interestRate/365), 365 ) - principal;
	double dailyBalance = principal + dailyInterest;

	// Set floating-point values to two decimal places and show results
	cout << showpoint << setprecision(2) << fixed;
	cout << endl << setw(50) << left << "For a loan of" << "$" << setw(9) << right << principal << endl;
	cout << setw(50) << left << "with a rate of" << setw(10) << right << interestRatePercentage << " %" << endl;
	cout << setw(50) << left << "the interest, compounded annually, is" << "$" << setw(9) << right << annualInterest << endl;
	cout << setw(50) << left << "the balance at the end of the year would be" << "$" << setw(9) << right << annualBalance << endl;
	cout << setw(50) << left << "the interest, compounded daily, is" << "$" << setw(9) << right << dailyInterest << endl;
	cout << setw(50) << left << "the balance at the end of the year would be" << "$" << setw(9) << right << dailyBalance << endl << endl;

	// Part 2
	// Ask user for the height and width of screen
	double height, width;
	cout << "Part 2: Screen Size Calculator" << endl << "What is the width of your screen in inches?" << endl;
	cin >> width;
	cout << "What is the height of your screen in inches?" << endl;
	cin >> height;

	// Calculate and show results
	double diagonal = sqrt( pow( height, 2) + pow( width, 2) );
	cout << endl << "Your screen is " << diagonal << " inches diagonally." << endl << endl;

	// Part 3
	// Ask user for the cost of gas and miles driven
	double gasCost, milesDriven;
	cout << "Part 3: Gas Mileage Calculations" << endl << "How much did the tank of gas cost?" << endl;
	cin >> gasCost;
	cout << "How many miles have you driven?" << endl;
	cin >> milesDriven;

	// Calculate cost per mile and show results
	double costPerMile = gasCost/milesDriven;
	cout << endl << setw(20) << left << "Cost of gas:" << "$" << setw(6) << right << gasCost << endl;
	cout << setw(20) << left << "Miles driven:" << setw(7) << right << milesDriven << endl;
	cout << setw(20) << left << "Cost per mile:" << "$" << setw(6) << right << costPerMile << endl << endl;

	// Part 4
	// Set random seed based on current time
	srand(time(0));

	// Roll two dice with % 6 + 1 to get a die value in the range 1 through 6 inclusive
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	int roll1Total = die1 + die2;

	// Show user the values of each die and their total
	cout << "Part 4: Las Vegas Dice Game" << endl;
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
