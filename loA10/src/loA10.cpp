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
		inFile.seekg(0);

		// Create arrays based on number of restaurants counted
		int restaurantRatings [numberofRestaurants][3];
		string restaurantNames [numberofRestaurants];
		string rawInput;
		int i = 0, rowNumber = 0, colNumber = 0, foodSum = 0, serviceSum = 0, cleanSum = 0;
		double foodAvg = 0, serviceAvg = 0, cleanAvg = 0, restaurantAvg = 0;

		getline (inFile, input); // Skips rater name line

		// Read and parse restaurant data
		getline (inFile, input);
		while (!inFile.eof()) {
			// Automates substring parsing to reduce the number of string variables needed to get the ratings
			colNumber = 0;
			for (i = 0; i < 6; (i = i + 2)) {
				rawInput = input.substr(i,2);
				restaurantRatings [rowNumber][colNumber] = stoi(rawInput);
				colNumber++;
			}
			foodSum += restaurantRatings [rowNumber][0];
			serviceSum += restaurantRatings [rowNumber][1];
			cleanSum += restaurantRatings [rowNumber][2];
			rawInput = input.substr(6, 20);
			restaurantNames [rowNumber] = rawInput;
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

	char gradeLetter;
	string rawInput, rawCreditHours;
	int creditHours = 0, numericGrade = 0, gradePointTotal = 0, totalCreditHours = 0;
	double GPA;
	unsigned long long int i; // This makes the compiler shut up about the warning without having to set compiler flag

	vector <char> gradeLetterData;
	vector <int> creditHoursData;

	// Ask user for grades
	cout << "Enter grade and hours, or \"stop\"" << endl;
	getline (cin,input);
	while (input != "stop") {
		gradeLetter = input[0];
		gradeLetterData.push_back(gradeLetter);
		rawCreditHours = input.substr(1,1);
		creditHours = stoi(rawCreditHours);
		creditHoursData.push_back(creditHours);
		cout << "Enter grade and hours, or \"stop\"" << endl;
		getline (cin, input);
	}

	cout << "The data entered was: " << endl;
	for (i = 0; i < gradeLetterData.size(); i++) {
		cout << gradeLetterData [i] << " " << creditHoursData [i] << endl;
		if (gradeLetterData [i] == 'A') {
			numericGrade = 4;
		}
		else if (gradeLetterData [i] == 'B') {
			numericGrade = 3;
		}
		else if (gradeLetterData [i] == 'C') {
			numericGrade = 2;
		}
		else if (gradeLetterData [i] == 'D') {
			numericGrade = 1;
		}
		else if (gradeLetterData [i] == 'F') {
			numericGrade = 0;
		}
		gradePointTotal += (numericGrade * creditHoursData [i]);
		totalCreditHours += creditHoursData [i];
	}
	GPA = (gradePointTotal / static_cast<double>(totalCreditHours));
	cout << "GPA = " << GPA << endl;

	return 0;
}
