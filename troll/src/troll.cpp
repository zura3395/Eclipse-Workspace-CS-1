//============================================================================
// Name        : troll.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <ctime>
#include <iomanip>
using namespace std;

/*

int func(int salesWest, int salesEast) {
	salesWest++;
	salesWest = salesWest + salesEast;
	return salesWest;
}

int main() {
    int var1, sum, salesWest;
    var1 =3;
    salesWest =4;
    sum = func(salesWest, var1);
    cout << "salesWest = " << sum;
    return 0;
}


int func6 (int a, int &b) {
	a++;
	b++;
	return a+b;
}

int main () {
	int var1 = 10;
	int var2 = 20;
	cout << var1 << " " << var2 << endl;
	int sum = func6 (var1, var2);
	cout << var1 << " " << var2 << endl;
	return 0;
}

*/

double funcA (double parameter) {
	if (parameter < 100) {
		return 15;
	}
	else if (parameter >= 100) {
		return 16;
	}
}

int main () {
	int i = 100;
	double cock = funcA(i);
	cout << cock;
	return 0;
}
