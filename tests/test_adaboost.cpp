//============================================================================
// Name        : driver.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Demo
//============================================================================

#include "tests.h"

using namespace std;
using namespace arma;

void test_adaboost()
{
	//cout << "it begins !!!" << endl;
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

	//cout << "size(x)" << arma::size(x) << " x.size()" << x.size() << endl;
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
	//cout << "z:" << z << endl;

	//cout << "x:" << x << endl;
	//cout << "y:" << y << endl;

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

	//cout << "a:" << a << endl;
	//cout << "size(a)" << arma::size(a) << " size(a, 0):" << size(a, 0) << " size(a, 1):" << size(a, 1) << endl;

	//Stump* s = new Stump(0);
	//double error, thres;
	//s->calculateThreshold(x.col(1), y, w, "lesser", error, thres);
	//s->buildOneDStump(x.col(1), y, w);
	//AdaBoost ad;
	//Stump* s = buildStump(x, y, w);
	//cout << s;


	AdaBoost ad;
	uword iter = 2;
	ad.train(x, y, iter);

	colvec labels(arma::size(y));
	//cout << "here!" << endl;

	ad.predict(x, labels);

	//s->predictStump(x, labels);
	cout << "labels:" << labels;

	uvec randA = randi<uvec>(3, 1, distr_param(0, N-1));
	
	cout << "x:" << x << endl;
	cout << "randA:" << randA << endl;
	cout << "x(randA):" << x.rows(randA) << endl;
	x.rows(randA).fill(0.5);
	x.col(0) = y;
	cout << "x:" << x << endl;
	cout << "x:" << find(sum(x, 1) > 5) << endl;
	
}
