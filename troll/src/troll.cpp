//============================================================================
// Name        : troll.cpp
// Author      : Ericson Lo
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

int main (){
	int nums[10] = {4,7,9,2,1,5,0,8,3,4};
	int i = 0;
	while (i< 10){
		if (nums[i] == 4) {
			cout << "pog" << endl;
		}
		else {
			cout << "not" << endl;
		}
		i++;
	}
}
