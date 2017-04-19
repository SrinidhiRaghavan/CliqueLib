//============================================================================
// Name        : AdaBoost.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib AdaBoost implementation
//============================================================================

#include <iostream>
#include <armadillo>
#include <math.h>
#include "AdaBoost.h"

using namespace std;
using namespace arma;

AdaBoost::AdaBoost() {
}

void AdaBoost::fit(const mat& X, const colvec& Y, uword iter) {
	uword n = size(X, 0); //no. of samples
	colvec sampleWts(n);
	double initWt = 1.0 / n;
	cout << "fit: initWt:" << initWt << endl;
	sampleWts.fill(initWt);
	cout << "fit: sampleWts:" << sampleWts << endl;

	for (uword i = 0; i < iter; i++) {
		Stump* clfr = buildStump(X, Y, sampleWts);
		double err = clfr->getError();
		double alpha = 0.5*log((1 - err) / err);

		//cout << "fit: :" << << endl;
		cout << "fit: err:" << err << endl;
		cout << "fit: alpha:" << alpha << endl;

		colvec preds(n);
		preds.zeros();
		clfr->predictStump(X, preds);

		sampleWts = sampleWts % exp(-alpha * Y % preds);
		cout << "fit: before sampleWts:" << sampleWts << endl;
		sampleWts = sampleWts / accu(sampleWts);
		cout << "fit: after sampleWts:" << sampleWts << endl;

		weakClassifiers.push_back(clfr);
		weights.push_back(alpha);
	}
}

void AdaBoost::predict(const mat& testX, colvec& preds) {
	uword n = size(testX, 0); //no. of samples
	colvec labels;
	colvec sum;
	sum.zeros(n, 1);
	labels.zeros(n, 1);
	preds.zeros(n, 1);

	auto weakIter = weakClassifiers.begin();
	auto wtIter = weights.begin();
	for (; weakIter != weakClassifiers.end(); weakIter++, wtIter++) {
		Stump* clfr = *weakIter;
		double wt = *wtIter;

		clfr->predictStump(testX, labels);
		sum += wt*labels;
	}
	preds.fill(-1);
	uvec idx = find(sum > 0);
	preds.elem(idx).fill(1);
}

Stump* AdaBoost::buildStump(const mat& X, const colvec& y, const colvec& weight) {
	uword d = size(X, 1);
	vector<Stump*> stumps;
	rowvec errors;
	errors.zeros(1, d);
	for (unsigned int i = 0; i < d; i++) {
		Stump* s = new Stump(i);
		stumps.push_back(s);
		s->buildOneDStump(X.col(i), y, weight);
		errors(0, i) = s->getError();
	}
	uword min_idx = index_min(errors);
	return stumps[min_idx];
}