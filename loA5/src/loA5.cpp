//============================================================================
// Name        : loA5.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 5
//============================================================================

#include <iostream>
#include <fstream>
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
		cout << "Average rating: " << ratingAvg << endl;
	}
	else {
		cout << "Error: Restaurant ratings file could not be opened" << endl;
		return 4;
	}

	// Part 2: Payroll
	cout << endl << "Part 2: Payroll" << endl;

	// Open payroll file
	inFile.open ("D:/CS 1 Assignment 5 Data/a5data2F21.txt",ios::in); // File path
	if (inFile.is_open()) {
		getline (inFile, input);
		while (!inFile.eof()) {
			cout << input << endl;
			getline (inFile, input);
		}
		inFile.close();
	}
	else {
		cout << "Error: Payroll file could not be opened" << endl;
		return 4;
	}
	return 0;
}
