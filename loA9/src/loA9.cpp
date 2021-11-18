//============================================================================
// Name        : loA9.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 9
//============================================================================

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
	// Part 1: Temperature report
	cout << "Part 1: Temperature report" << endl << endl;

	ifstream inFile;
	string input;

	// Open payroll file
	inFile.open ("D:/CS 1 Assignment Data/Assignment 9/a9data1F21.txt",ios::in); // File path
	if (inFile.is_open()) {
		// Useful variables
		string monthString, tempString;
		int monthNumber = 0, tempNumber = 0, totalNumberofTemps = 0;
		double averageTemp = 0, totalTempSum = 0, totalAverageTemp = 0;

		// Useful arrays
		string monthName[12] =
		{"January","February","March","April","May","June","July","August","September","October","November","December"};

		int i = 0;
		int monthCounter[12], tempSum[12];
		for (i = 0; i < 12; i++) {
			monthCounter[i] = tempSum[i] = 0;
		}

		getline (inFile, input);
		while (!inFile.eof()) {
			// Read and parse month
			monthString = input.substr(0,2);
			monthNumber = stoi(monthString);
			monthCounter[monthNumber-1]++;

			// Read and parse temperature
			tempString = input.substr(2,3);
			tempNumber = stoi(tempString);
			tempSum[monthNumber-1] += tempNumber;
			totalNumberofTemps++;

			getline (inFile, input);
		}
		inFile.close();

		// Display column headers
		cout << "Month" << setw(36) << "Number of temperatures" << setw(23) << "Average temperature" << endl;

		// Display data rows
		for (i = 0; i < 12; i++) {
			averageTemp = (double)tempSum[i]/monthCounter[i];
			totalTempSum += tempSum[i];
			cout << left << setw(28) << monthName[i] << setw(2) << right << monthCounter[i] << setw(27) << fixed << showpoint << setprecision(1) << averageTemp << endl;
		}

		// Display summary row
		totalAverageTemp = (double)totalTempSum/totalNumberofTemps;
		cout << left << setw(28) << "Year Total" << setw(2) << right << totalNumberofTemps << setw(27) << totalAverageTemp << endl;
	}
	else {
		cout << "Error: Temperature records file could not be opened." << endl;
		return 4;
	}

	// Part 2: School department report
	cout << endl << "Part 2: School department report" << endl << endl;

	inFile.open ("D:/CS 1 Assignment Data/Assignment 9/a9data2F21.txt",ios::in); // File path
	if (inFile.is_open()) {
		// Useful variables

		// Useful arrays

		getline (inFile, input);
		while (!inFile.eof()) {
			getline (inFile, input);
		}
		inFile.close();

		// Display column headers
		cout << right << "Department Name" << setw(20) << "Number of Majors" << endl;
	}
	else {
		cout << "Error: School department records file could not be opened." << endl;
		return 4;
	}

	return 0;
}
