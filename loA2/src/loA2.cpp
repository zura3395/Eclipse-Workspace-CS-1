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
	cout << "Part 2: Screen Size Calculator" << endl << "What is the width of your screen in pixels?" << endl;
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
	cout << setw(20) << left << "Cost per mile:" << "$" << setw(6) << right << costPerMile << endl;
}
