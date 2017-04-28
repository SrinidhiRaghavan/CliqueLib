//============================================================================
// Name        : test_adaboost.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib AdaBoost testing
//============================================================================

#include "tests.h"

using namespace std;
using namespace arma;

void test_adaboost()
{
        std::cout << "\nTESTING ADABOOST" << std::endl;
	mat x;
	x << 1 << 2 << endr
		<< 2 << 4 << endr
		<< 3 << 6 << endr
		<< 4 << 8 << endr
		<< 1 << 10 << endr;

	mat xTest;
	xTest << 2 << 1 << 3 << 4 << endr
	      << 1 << 2 << 3 << 4 << endr
	      << 3 << 2 << 3 << 4 << endr;

	uword N = size(x, 0);
	colvec w;
	w.ones(N, 1);
	w.fill(0.2);

	colvec y;
	y << 1.0 << endr
	  << -1.0 << endr
	  << 1.0 << endr
	  << -1.0 << endr
	  << -1.0 << endr;

	auto z = x.col(0) % w;

	vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	mat a(v);
	a.reshape(3, 2);
	a = a.t();

	AdaBoost ad;
	uword iter = 2;
	ad.train(x, y, iter);

	colvec labels(arma::size(y));

	ad.predict(x, labels);

	cout << "\nlabels:\n" << labels;

	uvec randA = randi<uvec>(3, 1, distr_param(0, N-1));
	
	cout << "x:\n" << x << endl;
	cout << "randA:\n" << randA << endl;
	cout << "x(randA):\n" << x.rows(randA) << endl;
	x.rows(randA).fill(0.5);
	x.col(0) = y;
	cout << "x:\n" << x << endl;
	cout << "x:\n" << find(sum(x, 1) > 5) << endl;	

        std::cout << "\nTests Passed" << std::endl;
}
