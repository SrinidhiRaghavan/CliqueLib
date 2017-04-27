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

void AdaBoost::train(const mat& X, const colvec& Y, uword iter) {
	uword n = size(X, 0); //number of samples
	colvec sampleWts(n);
	double initWt = 1.0 / n;
	sampleWts.fill(initWt);

	for (uword i = 0; i < iter; i++) {
		auto clfr = buildStump(X, Y, sampleWts);
		double err = clfr->getError();
		double alpha = 0.5*log((1 - err) / err);

		colvec preds(n);
		preds.zeros();
		clfr->predictStump(X, preds);

		sampleWts = sampleWts % exp(-alpha * Y % preds);
		sampleWts = sampleWts / accu(sampleWts);

		weakClassifiers.push_back(clfr);
		weights.push_back(alpha);
	}
}

void AdaBoost::predict(const mat& testX, colvec& preds) {
	uword n = size(testX, 0); //number of samples
	colvec labels;
	colvec sum;
	sum.zeros(n, 1);
	labels.zeros(n, 1);
	preds.zeros(n, 1);

	auto weakIter = weakClassifiers.begin();
	auto wtIter = weights.begin();
	for (; weakIter != weakClassifiers.end(); weakIter++, wtIter++) {
		auto clfr = *weakIter;
		double wt = *wtIter;

		clfr->predictStump(testX, labels);
		sum += wt*labels;
	}
	preds.fill(-1);
	uvec idx = find(sum > 0);
	preds.elem(idx).fill(1);
}

shared_ptr<Stump> AdaBoost::buildStump(const mat& X, const colvec& y, const colvec& weight) {
	uword d = size(X, 1);
	vector<std::shared_ptr<Stump>> stumps;
	rowvec errors;
	errors.zeros(1, d);
	for (unsigned int i = 0; i < d; i++) {
		auto s = make_shared<Stump>(i);
		stumps.push_back(s);
		s->buildOneDStump(X.col(i), y, weight);
		errors(0, i) = s->getError();
	}
	uword min_idx = index_min(errors);
	return stumps[min_idx];
}
