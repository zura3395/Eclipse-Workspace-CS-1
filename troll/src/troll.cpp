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
	string restZip = "5952-L2W";
	int firstPart = stoi( restZip.substr(0,4) );
	string secondPart = restZip.substr(5,3);
	cout << firstPart << endl;
	cout << secondPart << endl;
return 0;
}
