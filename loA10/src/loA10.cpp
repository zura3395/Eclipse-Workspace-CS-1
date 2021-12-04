//============================================================================
// Name        : loA10.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 10
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
	// Part 1: Restaurant ratings
	cout << "Part 1: Restaurant ratings" << endl << endl;

	ifstream inFile;
	string input;

	// Open restaurant ratings file
	inFile.open ("D:/CS 1 Assignment Data/Assignment 10/a10dataF21.txt",ios::in); // File path
	if (inFile.is_open()) {
		int numberofRestaurants = 0;

		// Display rater name
		getline (inFile, input);
		cout << "Rater: " << input << endl << endl;

		// Count number of restaurants
		getline (inFile, input);
		while (!inFile.eof()) {
			numberofRestaurants++;
			getline (inFile, input);
		}
		inFile.clear();
		inFile.seekg(0, ios::beg);

		// Create arrays based on number of restaurants counted
		int restaurantRatings [numberofRestaurants][3];
		string restaurantNames [numberofRestaurants];
		int i = 0, rowNumber = 0, colNumber = 0, foodSum = 0, serviceSum = 0, cleanSum = 0;
		double foodAvg = 0, serviceAvg = 0, cleanAvg = 0, restaurantAvg = 0;

		getline (inFile, input); // Skips rater name line

		// Read and parse restaurant data
		getline (inFile, input);
		while (!inFile.eof()) {
			// Automates substring parsing to reduce the number of string variables needed to get the ratings
			colNumber = 0;
			for (i = 0; i < 6; (i = i + 2)) {
				restaurantRatings [rowNumber][colNumber] = stoi(input.substr(i,2));
				colNumber++;
			}
			foodSum += restaurantRatings [rowNumber][0];
			serviceSum += restaurantRatings [rowNumber][1];
			cleanSum += restaurantRatings [rowNumber][2];
			restaurantNames [rowNumber] = input.substr(6, 20);
			rowNumber++;
			getline(inFile, input);
		}
		inFile.close();

		// Show table
		cout << left << setw(25) << "Restaurant Name" << setw(11) << "Food" << setw(10) << "Service" << setw(14) << "Cleanliness" << "Average" << endl;
		cout << right << setw(30) << "Rating" << setw(12) << "Rating" << setw(12) << "Rating" << setw(12) << "Rating" << endl;
		for (rowNumber = 0; rowNumber < numberofRestaurants; rowNumber++) {
			restaurantAvg = ((restaurantRatings [rowNumber][0] + restaurantRatings [rowNumber][1] + restaurantRatings [rowNumber][2]) / static_cast<double>(3));
			cout << left << setw(27) << restaurantNames [rowNumber] << setw(12) << restaurantRatings [rowNumber][0] << setw(12) << restaurantRatings [rowNumber][1] << setw(11) << setprecision(3) << restaurantRatings [rowNumber][2] << restaurantAvg << endl;
		}
		// Calculate and show column averages
		foodAvg = (foodSum / static_cast<double>(numberofRestaurants));
		serviceAvg = (serviceSum / static_cast<double>(numberofRestaurants));
		cleanAvg = (cleanSum / static_cast<double>(numberofRestaurants));
		cout << setw(24) << "Averages:" << setw(12) << foodAvg << setw(12) << serviceAvg << setw(12) << cleanAvg << endl << endl;
	}
	else {
		cout << "Error: Restaurant ratings file could not be opened" << endl;
		return 4;
	}

	// Part 2: GPA Calculator
	cout << "Part 2: GPA Calculator" << endl << endl;

	int numericGrade = 0, gradePointTotal = 0, totalCreditHours = 0;
	unsigned long long int i; // This makes the compiler shut up about the warning without having to set compiler flag

	vector <char> gradeLetters;
	vector <int> creditHours;

	// Ask user for grades
	cout << "Enter grade and hours, or \"stop\"" << endl;
	getline (cin,input);
	while (input != "stop") {
		gradeLetters.push_back(input[0]);
		creditHours.push_back(stoi(input.substr(1,1)));
		cout << "Enter grade and hours, or \"stop\"" << endl;
		getline (cin, input);
	}

	// Show user the recorded data and calculated GPA
	cout << "The data entered was: " << endl;
	for (i = 0; i < gradeLetters.size(); i++) {
		cout << gradeLetters [i] << " " << creditHours [i] << endl;
		if (gradeLetters [i] == 'A') {
			numericGrade = 4;
		}
		else if (gradeLetters [i] == 'B') {
			numericGrade = 3;
		}
		else if (gradeLetters [i] == 'C') {
			numericGrade = 2;
		}
		else if (gradeLetters [i] == 'D') {
			numericGrade = 1;
		}
		else if (gradeLetters [i] == 'F') {
			numericGrade = 0;
		}
		gradePointTotal += (numericGrade * creditHours [i]);
		totalCreditHours += creditHours [i];
	}
	double gpa = (gradePointTotal / static_cast<double>(totalCreditHours));
	cout << "GPA = " << gpa << endl;
	return 0;
}
