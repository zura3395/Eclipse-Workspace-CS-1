//============================================================================
// Name        : loA3.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 3
//============================================================================

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

int main() {

	// Part 1
	cout << "Part 1" << endl;

	// Display the numbers from 1 through 10 inclusive along with their square roots.
	int counter1 = 1;
	double squareRoot;

	while (counter1 <= 10) {
		cout << counter1 << endl;
		squareRoot = sqrt(counter1);
		cout << "sqrt(" << counter1 << ") = " << fixed << setprecision(2) << squareRoot << endl << endl;
		counter1++;
	}

	// Part 2
	cout << "Part 2" << endl;

	// Calculate the sum of the integers in the range 10 to 20 inclusive
	int counter2 = 10;
	int sum2 = 0;

	while (counter2 <= 20) {
		sum2 = sum2 + counter2;
		counter2++;
	}

	// Display summation
	cout << "The sum of the integers in the range 10 to 20 inclusive is " << sum2 << "." << endl << endl;

	// Part 3
	cout << "Part 3" << endl;

	// Ask the user for bounds
	int lowerBound;
	cout << "What is the lower bound of the summation?" << endl;
	cin >> lowerBound;
	int counter3 = lowerBound;

	int upperBound;
	cout << "What is the upper bound of the summation?" << endl;
	cin >> upperBound;

	// Calculate the sum of the integers in the range
	int sum3 = 0;

	while (counter3 <= upperBound) {
		sum3 = sum3 + counter3;
		counter3++;
	}

	// Display the two bounds and the sum
	cout << endl << "You entered " << lowerBound << " as the lower bound and " << upperBound << " as the upper bound." << endl << "The sum of the integers in that range is " << sum3 << "." << endl << endl;

	// Part 4
	// Ask user for input
	cout << "Part 4" << endl << "Please enter Dagny, Hank, or Francisco." << endl;
	string name;
	cin >> name;

	// Evaluate input
	while( (name != "Dagny") && (name != "Hank") && (name != "Francisco") ) {
		cout << "Error. Please enter Dagny, Hank, or Francisco." << endl;
		cin >> name;
	}
	cout << endl << "Thank you for entering " << name << "." << endl << endl;


	// Part 5
	// Ask user for number
	cout << "Part 5" << endl << "Please enter a number." << endl;
	int number;
	cin >> number;

	// Evaluate input and show names, ask for new number, or end the program accordingly
	while (number >= 0) {
		if (number == 1){
			cout << "Abigail" << endl;
			cout << endl << "Please enter a number." << endl;
			cin >> number;

		}
		else if (number == 2){
			cout << "Bobby" << endl;
			cout << endl << "Please enter a number." << endl;
			cin >> number;
		}
		else if (number == 3){
			cout << "Charmaine" << endl;
			cout << endl << "Please enter a number." << endl;
			cin >> number;
		}
		else if (number > 3) {
			cout << "Error, you entered a number greater than 3. Please enter a number." << endl;
			cin >> number;
		}
	}
	cout << "You entered a negative number." << endl;


	return 0;
}
