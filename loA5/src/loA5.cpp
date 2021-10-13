//============================================================================
// Name        : loA5.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 5
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	// Part 1: Restaurant ratings
	cout << "Part 1: Restaurant ratings" << endl;

	ifstream inFile;
	string input;
	string fname, lname, ratingRaw, restaurant;
	int rating, ratingAvg;
	int restaurantCounter = 0;
	int ratingSum = 0;

	// Open restaurant ratings file
	inFile.open ("D:/CS 1 Assignment 5 Data/a5data1F21.txt",ios::in); // File path
	if (inFile.is_open()) {
		// Display rater name
		getline (inFile, input);
		fname = input.substr(0,15);
		lname = input.substr(15,20);
		cout << "Rater: " << fname << lname << endl;

		// Parse and display restaurant names and respective ratings
		getline (inFile, input);
		while (!inFile.eof()) {
			ratingRaw = input.substr(0,2);
			rating = stoi(ratingRaw); // Convert string to integer
			ratingSum = ratingSum + rating;
			restaurant = input.substr(2,20);
			restaurantCounter++;
			cout << "Restaurant: " << restaurant << endl;
			cout << "Rating: " << rating <<endl;
			getline (inFile, input);
		}
		inFile.close();

		// Calculate and display average rating
		ratingAvg = double(ratingSum)/restaurantCounter; // Cast integer to float to show decimal place if average rating is non-integer
		cout << endl << "Average rating: " << ratingAvg << endl;
	}
	else {
		cout << "Error: Restaurant ratings file could not be opened" << endl;
		return 4;
	}

	// Part 2: Payroll
	cout << endl << "Part 2: Payroll" << endl;

	string employeeName, wagesRaw, taxRateRaw;
	double wages, taxRate, taxRateDecimal, tax, pay;
	ofstream outFile;

	// Open payroll file
	inFile.open ("D:/CS 1 Assignment 5 Data/a5data2F21-2.txt",ios::in); // Input file path
	outFile.open ("D:/CS 1 Assignment 5 Data/A5PayrollOutput.txt",ios::out); // Output file path
	if (inFile.is_open()) {

		// Check output file path validity
		if (outFile.is_open() == false) {
			cout << "Error: Payroll output file could not be written to." << endl;
			return 4;
		}

		// Column header
		cout << "Employee name" << setw(22) << "Wages" << setw(13) << "Tax Rate" << setw(8) << "Tax" << setw(11) << "Pay" << endl << endl;
		getline (inFile, input);
		while (!inFile.eof()) {
			employeeName = input.substr(0,25);
			wagesRaw = input.substr(25,6);
			wages = stod(wagesRaw); // Convert string to double
			taxRateRaw = input.substr(31,4);

			//Calculations
			taxRate = stod(taxRateRaw); // Convert raw tax rate to decimal for display
			taxRateDecimal = taxRate / 100; // Converts tax rate to decimal that can be used for calculations, example: "6.5" becomes "1.065"
			tax = wages * taxRateDecimal; // Commit theft
			pay = wages - tax;

			// Display payroll report row
			cout << employeeName << setw(5) << "$" << fixed << showpoint << setprecision(2) << setw(7) << wages << setw(11) << taxRate << setw(5) << "$" << setw(6) << tax << setw(5) << "$" << setw(7) << pay << endl;

			// Output employee name and pay to file
			outFile << employeeName << fixed << showpoint << setprecision(2) << setw(6) << pay << endl;
			getline (inFile, input);

		}
		
		inFile.close();
		outFile.close();

		else {
			cout << "Error: Payroll file could not be opened." << endl;
			return 4;
		}
	}
	return 0;
}
