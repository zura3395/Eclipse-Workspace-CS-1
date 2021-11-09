//============================================================================
// Name        : loA8.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 8
//============================================================================

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
using namespace std;

// Function prototype
int rollem();

int main() {
	// Part 1
	string input;
	int temperaturesP1[8];
	int i = 0, sum = 0;

	// User inputs eight integer temperatures
	cout << "Part 1" << endl;
	cout << "Enter temperature 1: ";
	getline(cin, input);
	temperaturesP1[i] = stoi(input);
	i++;
	while (i < 8){
		cout << "Enter temperature " << (i+1) << ": ";
		getline(cin, input);
		temperaturesP1[i] = stoi(input);
		i++;
	}

	// Format and display user inputs, calculate sum
	for (i = 0; i < 8; i++){
		cout << "You entered " << temperaturesP1[i] << " as temperature " << (i+1) << endl;
		sum+=temperaturesP1[i];
	}

	// Calculate and display average
	double tempAvg = sum/static_cast<double>(8);
	cout << "The average temperature was " << showpoint << fixed << setprecision(2) << tempAvg << endl << endl;

	// Part 2
	cout << "Part 2" << endl;
	int temperaturesP2[100];
	int numberOfElements = 0;
	sum = 0;

	// Ask user for temperatures
	cout << "Enter a temperature, or stop: ";
	getline(cin, input);
	while (input != "stop") {
		temperaturesP2[numberOfElements] = stoi(input);
		numberOfElements++;
		cout << "Enter a temperature, or stop: ";
		getline(cin, input);
	}

	// Display user inputs and calculate average temperature
	for (i = 0; i < numberOfElements; i++){
		cout << "You entered " << temperaturesP2[i] << endl;
		sum+=temperaturesP2[i];
	}

	tempAvg = sum/static_cast<double>(numberOfElements);
	cout << "The average temperature is " << showpoint << fixed << setprecision(2) << tempAvg << endl << endl;

	// Part 3
	cout << "Part 3" << endl;
	cout << "How many times would you like to roll the dice?" << endl;
	getline(cin, input);
	int rolls = stoi(input);
	int rollResult;

	// Create random seed
	srand(time(0));

	// Initialize array
	int rollArray[11];
	for (i = 0; i < 11; i++){
		rollArray[i] = 0;
	}

	// We do a little rolling
	for (i = 0; i < rolls; i++){
		rollResult = rollem();
		rollArray[(rollResult-2)]++; // Increments counter for the roll result
	}

	double rollOccurAvg;
	for (i = 0; i < 11; i++){
		rollOccurAvg = (rollArray[i] / static_cast<double>(rolls)) * 100;
		cout << "Roll" << setw(3) << (i+2) << " occurrences" << setw(10) << rollArray[i] << setw(7) << rollOccurAvg << setw(2) << "%" << endl;
	}

	return 0;
}

// Die rolling function
int rollem() {
	int die1 = rand() % 6 + 1;
	int die2 = rand() % 6 + 1;
	return (die1 + die2);
}
