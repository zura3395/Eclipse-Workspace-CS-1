//============================================================================
// Name        : loA11.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Assignment 11
//============================================================================

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

struct restaurant {
	string name;
	int foodRating;
	int serviceRating;
	int cleanRating;
	float avg;
};

int main() {
	ifstream inFile;
	string input;

	// Open restaurant ratings file
	inFile.open ("D:/CS 1 Assignment Data/Assignment 10/a10dataF21.txt",ios::in); // File path
	if (inFile.is_open()) {
		// Display rater name
		getline (inFile, input);
		cout << "Rater: " << input << endl << endl;

		restaurant ratings[100];
		string rawInput;
		int i = 0, foodSum = 0, serviceSum = 0, cleanSum = 0, numberofRestaurants = 0;
		float totalFoodAvg = 0, totalServiceAvg = 0, totalCleanAvg = 0, restaurantSum = 0, totalRestaurantAvg = 0;

		// Read and parse restaurant data
		getline (inFile, input);
		while (!inFile.eof()) {
			rawInput = input.substr(0,2);
			ratings[i].foodRating = stoi(rawInput);
			foodSum += ratings[i].foodRating;

			rawInput = input.substr(2,2);
			ratings[i].serviceRating = stoi(rawInput);
			serviceSum += ratings[i].serviceRating;

			rawInput = input.substr(4,2);
			ratings[i].cleanRating = stoi(rawInput);
			cleanSum += ratings[i].cleanRating;

			rawInput = input.substr(6, 20);
			ratings[i].name = rawInput;
			ratings[i].avg = ((ratings[i].foodRating + ratings[i].serviceRating + ratings[i].cleanRating) / static_cast<float>(3));
			restaurantSum += ratings[i].avg;
			numberofRestaurants++;
			i++;
			getline(inFile, input);
		}
		inFile.close();

		// Show table
		cout << left << setw(25) << "Restaurant Name" << setw(11) << "Food" << setw(10) << "Service" << setw(14) << "Cleanliness" << "Average" << endl;
		cout << right << setw(30) << "Rating" << setw(12) << "Rating" << setw(12) << "Rating" << setw(12) << "Rating" << endl;
		for (i = 0; i < numberofRestaurants; i++) {
			cout << left << setw(27) << ratings[i].name << setw(12) << ratings[i].foodRating << setw(12) << ratings[i].serviceRating << setw(11) << ratings[i].cleanRating << setprecision(3) << ratings[i].avg << endl;
		}
		// Calculate and show column averages
		totalFoodAvg = foodSum / static_cast<float>(numberofRestaurants);
		totalServiceAvg = serviceSum / static_cast<float>(numberofRestaurants);
		totalCleanAvg = cleanSum / static_cast<float>(numberofRestaurants);
		totalRestaurantAvg = restaurantSum / static_cast<float>(numberofRestaurants);
		cout << setw(24) << "Averages:" << setw(12) << totalFoodAvg << setw(12) << totalServiceAvg << setw(14) << totalCleanAvg << totalRestaurantAvg;
	}
	else {
		cout << "Error: Restaurant ratings file could not be opened" << endl;
		return 4;
	}
	return 0;
}
