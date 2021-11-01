//============================================================================
// Name        : loA7.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 7
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// Global variable
float taxRate = 0.0525;

// Function prototypes
void calcPay(float &hours, float &rate, float &regPay, float &ovPay);
float calcTax(float &totalPay, float &taxRate);
int getIntegerFromUser (string message, int lowerBound, int upperBound);
string getStringFromUser (string message);

// Main program
int main() {
	// Part 1: Payroll
	cout << "Part 1: Payroll" << endl;

	ifstream inFile;
	string input;
	string name, rawHours, rawRate;
	float hours, rate, regPay, ovPay, totalPay, tax, netPay;

	// Open payroll file
	inFile.open ("D:/CS 1 Assignment Data/Assignment 7/a7data.txt",ios::in); // File path
	if (inFile.is_open()) {

		// Display column headers
		cout << "Employee Name" << setw(14) << "Hours" << setw(7) << "Rate" << setw(8) << "Reg" << setw(8) << "Ov" << setw(11) << "Total" << setw(8) << "Tax" << setw(9) << "Net" << endl;
		cout << setw(42) << "Pay" << setw(9) << "Pay" << setw(9) << "Pay" << setw(18) << "Pay" << endl << endl;

		// Parse, calculate, and display each line of data
		getline (inFile, input);
		while (!inFile.eof()) {
			// Read info
			name = input.substr(0,20);
			rawHours = input.substr(20,5);
			rawRate = input.substr(25,5);

			// Convert raw strings to floats and call calcPay function to calculate regular, overtime, and total pay
			hours = stof(rawHours);
			rate = stof(rawRate);
			calcPay (hours, rate, regPay, ovPay);
			totalPay = regPay + ovPay;

			// Call calcTax function to calculate pay
			tax = calcTax (totalPay, taxRate);
			netPay = totalPay - tax;

			// Display data rows
			cout << name << setw(7) << fixed << showpoint << setprecision(2) << hours << setw(7) << rate << setw(9) << regPay << setw(9) << ovPay << setw(9) << totalPay << setw(9) << tax << setw(9) << netPay << endl;
			getline (inFile,input);
		}
		inFile.close();
	}
	else {
		cout << "Error: Payroll file could be opened." << endl;
		return 4;
	}

	// Part 2: Input validation tests
	cout << "Part 2: Input validation tests" << endl;
	bool testA7part2();
	if (testA7part2()) {
		cout << "All part 2 tests passed." << endl;
	}
	else {
		cout << "Part 2 failed." << endl;
	}

	return 0;
}

// Part 1 functions
void calcPay(float &hours, float &rate, float &regPay, float &ovPay) {
	if (hours > 40) {
		regPay = 40 * rate;
		ovPay = (hours - 40) * (1.5 * rate);
	}
	else {
		regPay = hours * rate;
		ovPay = 0;
	}
}

float calcTax(float &totalPay, float &taxRate) {
	float tax = totalPay * taxRate;
	return tax;
}


// Part 2 functions
int getIntegerFromUser(string message, int lowerBound, int upperBound){
	cout << message << endl;
	string input;
	getline(cin, input);
	int i = stoi(input);
	while ((i < lowerBound) || (i > upperBound)){
		cout << "Error: " << message << endl;
		getline(cin, input);
		i = stoi(input);
	}
	return i;
}

string getStringFromUser (string message){
	cout << message << endl;
	string input;
	getline(cin, input);
	while (input.length() <= 0) {
		cout << "Error: " << message << endl;
		getline(cin, input);
	}
	return input;
}

bool testA7part2()
{
	string message = "enter an integer in the range 5 to 10 inclusive";
	int i = getIntegerFromUser (message, 5, 10);
	if (i >= 5 and i <= 10)
	{
		cout << "integer validation function OK" << endl;
		message = "enter your favorite book's title";
		string s = getStringFromUser (message);
		if (s.length() > 0)
		{
			cout << "string validation function OK" << endl;
			return true;
		}
		else
		{
			cout << "string validation function failed" << endl;
		}
	}
	else
	{
		cout << "integer validation function failed" << endl;
	}
	return false;
}
