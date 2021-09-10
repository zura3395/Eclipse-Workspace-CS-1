//============================================================================
// Name        : loA1.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 1
//============================================================================

#include <iostream>
#include <string>
using namespace std;

int main() {
	// Part 1
	int daysWorked;
	float hoursWorked;

	// Ask the user how many days they worked last week.
	cout << "Part 1: Average Work Hour Calculator" << endl << "How many days have you worked last week?" << endl;
	cin >> daysWorked;

	// Next, ask the user how many hours they worked last week.
	cout << "How many hours have you worked last week?" << endl;
	cin >> hoursWorked;

	// Calculate average hours worked per day last week.
	float avgHours = hoursWorked/daysWorked;

	// if statement to prevent grammatical error.
	if ((avgHours != 1)) {
		cout << "You worked an average of " << avgHours << " hours per day." << endl << endl; // Tell the user the hours they worked per day last week.
	}
	else {
		cout << "You worked an average of one hour per day." << endl << endl ; // Tell the user they worked one hour per day last week.
	}

	// Part 2
	float tempFahrenheit;

	// Ask the user to enter a temperature, in Fahrenheit.
	cout << "Part 2: Temperature Conversion" << endl << "Enter the temperature in Fahrenheit." << endl;
	cin >> tempFahrenheit;

	// Convert the temperature from Fahrenheit to centigrade.
	float tempCentigrade = (tempFahrenheit-32) * 5/9;

	// Tell the user what that is in Centigrade.
	cout << "The temperature is " << tempCentigrade << " in centigrade." << endl << endl;

	// Part 3
	string IDnumber, item1Name, item2Name, item3Name;
	float item1Price, item2Price, item3Price;

	// Ask the user for their student ID number.
	cout << "Part 3: School Cafeteria" << endl << "Please enter your ID number." << endl;
	cin >> IDnumber;

	// Next, ask the user for three pairs of cafeteria items and prices.
	cout << "What is the name of the first item? No spaces please." << endl;
	cin >> item1Name;

	cout << "Please enter its price." << endl;
	cin >> item1Price;

	cout << "What is the name of the second item? No spaces please." << endl;
	cin >> item2Name;

	cout << "Please enter its price." << endl;
	cin >> item2Price;

	cout << "What is the name of the third item? No spaces please." << endl;
	cin >> item3Name;

	cout << "Please enter its price." << endl;
	cin >> item3Price;

	// Calculate and print a receipt containing the items, the subtotal, the tax, and the grand total. The tax is 9.25% of the subtotal.
	float subtotal = item1Price + item2Price + item3Price;
	float taxRate = 0.0925;
	float totalTax = subtotal * taxRate;
	float grandTotal = subtotal + totalTax;

	cout << "-------Receipt for " << IDnumber << "-------" << endl;
	cout << item1Name << " - $" << item1Price << endl;
	cout << item2Name << " - $" << item2Price << endl;
	cout << item3Name << " - $" << item3Price << endl;
	cout << "Subtotal - $" << subtotal << endl;
	cout << "Tax - $" << totalTax << endl;
	cout << "Total - $" << grandTotal << endl;
	cout << "----------------------------";

	return 0;
}
