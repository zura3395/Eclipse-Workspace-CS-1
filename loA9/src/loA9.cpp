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

int convertDepartmentAbbr (string [], int, string);

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
		int monthNumber = 0, totalNumberofTemps = 0;
		double averageTemp = 0, totalTempSum = 0, totalAverageTemp = 0;

		// Useful arrays, index 13 so that index number = month number
		string monthName [13] =
			{"Months","January","February","March","April","May","June","July","August","September","October","November","December"};
		int i = 0;
		int monthCounter [13], tempSum [13];
		for (i = 0; i < 13; i++) {
			monthCounter [i] = tempSum [i] = 0;
		}

		getline (inFile, input);
		while (!inFile.eof()) {
			// Read and parse month
			monthString = input.substr(0,2);
			monthNumber = stoi(monthString);
			monthCounter [monthNumber]++;

			// Read and parse temperature
			tempString = input.substr(2,3);
			tempSum [monthNumber] += stoi(tempString);
			totalNumberofTemps++;

			getline (inFile, input);
		}
		inFile.close();

		// Display column headers
		cout << "Month" << setw(36) << "Number of temperatures" << setw(23) << "Average temperature" << endl << endl;

		// Display data rows
		for (i = 1; i < 13; i++) {
			averageTemp = (double)tempSum [i]/monthCounter [i];
			totalTempSum += tempSum [i];
			cout << left << setw(28) << monthName [i] << setw(2) << right << monthCounter [i] << setw(27) << fixed << showpoint << setprecision(1) << averageTemp << endl;
		}

		// Display summary row
		totalAverageTemp = (double)totalTempSum/totalNumberofTemps;
		cout << left << setw(28) << "Year Total" << setw(2) << right << totalNumberofTemps << setw(27) << totalAverageTemp << endl;
	}
	else {
		cout << "Error: Temperature records file could not be opened." << endl;
		return 4;
	}

	// Part 2: Student report
	cout << endl << "Part 2: Student report" << endl << endl;

	inFile.open ("D:/CS 1 Assignment Data/Assignment 9/a9data2F21.txt",ios::in); // File path
	if (inFile.is_open()) {
		// Useful variables
		string name, departmentAbbr;
		int numberofDepartments = 11, departmentIndex = 0;

		// Useful arrays
		string departmentAbbrArray [numberofDepartments] =
		{"MATH ", "PHYS ", "BIO  ", "COMSC", "ACCY ", "ARTH ", "POLS ", "USHST", "ELIT ", "ENGR ", "PSYC "};
		string departmentNamesArray [numberofDepartments] =
		{"Mathematics", "Physics", "Biology", "Computer Science", "Accounting", "Art History", "Political Science", "US History", "English Literature", "Engineering", "Psychology"};
		int departmentCounter [numberofDepartments];
		int i = 0;
		for (i = 0; i < numberofDepartments; i++) {
			departmentCounter [i] = 0;
		}

		// Display column headers
		cout << right << "Student Name" << setw(23) << "Major" << endl << endl;

		getline (inFile, input);
		while (!inFile.eof()) {
			// Read and parse student data
			name = input.substr(0,20);
			departmentAbbr = input.substr(20,5);
			departmentIndex = convertDepartmentAbbr (departmentAbbrArray, numberofDepartments, departmentAbbr);

			// Display data rows
			cout << left << setw(30) << name;

			if (departmentIndex >= 0) {
				cout << departmentNamesArray[departmentIndex] << endl;
				departmentCounter[departmentIndex]++;
			}
			else {
				cout << departmentAbbr << "(WARNING: Invalid abbreviation, revalidation of student records required)" << endl;
			}
			getline (inFile, input);
		}
		inFile.close();


		// Display column headers
		cout << endl << right << "Department Name" << setw(24) << "Number of Majors" << endl << endl;

		for (i = 0; i < numberofDepartments; i++) {
			cout << left << setw(30) << departmentNamesArray[i] << departmentCounter[i] << endl;
		}
	}
	else {
		cout << "Error: School department records file could not be opened." << endl;
		return 4;
	}
	return 0;
}

int convertDepartmentAbbr (string departmentAbbrArray [], int numberofDepartments, string departmentAbbr) {
	int i = 0;
	while (i < numberofDepartments) {
		if (departmentAbbr == departmentAbbrArray[i]) {
			return i;
		}
		else {
			i++;
		}
	}
	return -1;
}
