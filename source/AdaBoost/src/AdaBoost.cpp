//============================================================================
// Name        : svm.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

int main()
{
	mat A = randu<mat>(4, 5);
	mat B = randu<mat>(4, 5);

	cout << "Result:" << endl;
	cout << A*B.t() << endl;
	getchar();
	return 0;
}