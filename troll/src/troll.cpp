//============================================================================
// Name        : troll.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>
using namespace std;

int main() {
	// Part 2: Payroll
	     cout << "part 2: Payroll" << endl;
	     string input;
	     string  firstName, lastName, workHourRaw, payRateRaw; // What goes into here?
	     double payRate, workHour, pay; // Is that all?
	     ifstream inputFile;
	     ofstream outputFile;


	     // Open payRoll file.
	     inputFile.open("C:/Users/Ericson/Downloads/a5data2.txt",ios::in); // Input file.
	     outputFile.open ("C:/Users/Ericson/Downloads/A5out.txt",ios::out);// Output file.
	     if (inputFile.is_open()){
	        if(outputFile.is_open()== false){
	            cout << "Error: Payroll output file could not be written to." << endl;
	            return 4;
	        }

	    // Column.
	     cout << "Employee name" << setw(22) << "Payrate" << setw(13) << "Work Hours" << setw(8) << endl;
	     getline (inputFile, input);
	     cout <<"hehe"<<endl;
	     cout << input << endl;
	     while (!inputFile.eof()){

	            cout <<"idk"<<endl;

	            firstName = input.substr(0,10);
	            lastName = input.substr(10,10);
	            payRateRaw = input.substr(20,5);
	            payRate = stod(payRateRaw);
	            workHourRaw = input.substr(25,5);
	            workHour = stod(workHourRaw);
	            pay = workHour*payRate;
	            cout << pay <<endl;
	            getline (inputFile,input);
	    }
	}
	return 0;
}
