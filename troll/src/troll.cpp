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

int main() {
    cout << "Time start!" << endl;
    long start = 0;
    long end = 0;
    start = clock();
    for (int i; i<1000000000; )
        i++;
    end = clock();
    cout << setprecision(8) << fixed << difftime(end, start)/CLOCKS_PER_SEC << " seconds."<< endl;
    return 0;
}
