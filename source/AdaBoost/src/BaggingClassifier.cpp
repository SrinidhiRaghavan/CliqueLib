//============================================================================
// Name        : BaggingClassifier.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib BaggingClassifier implementation
//============================================================================

#include <iostream>
#include <armadillo>
#include <math.h>
#include "AdaBoost.h"
#include "BaggingClassifier.h"

using namespace std;
using namespace arma;

template<typename T>
BaggingClassifier<T>::BaggingClassifier(uword n_estimators, uword max_samples) {
	this->n_estimators = n_estimators;
	this->max_samples = max_samples;
}

template<typename T>
void BaggingClassifier<T>::fit(const mat& X, const colvec& Y, uword iter) {
	uword n = size(X, 0);

	for (uword i = 0; i < n_estimators; i++) {
		uvec randIdx = randi<uvec>(max_samples, 1, distr_param(0, n));
		T* clfr = new T();
		clfr->fit(X.rows(randIdx), Y.rows(randIdx), iter);
		base_estimators.push_back(clfr);
	}
}

template<typename T>
void BaggingClassifier<T>::predict(const mat& testX, colvec& labels) {
	uword n = size(testX, 0);
	mat predMat;
	predMat.zeros(n, n_estimators);
	labels.zeros(n, 1);

	auto baseIter = base_estimators.begin();
	for (uword i = 0; baseIter != base_estimators.end(); baseIter++, i++) {
		T* clfr = *baseIter;
		colvec preds;
		preds.zeros(n, 1);
		clfr->predict(testX, preds);
		predMat.col(i) = preds;
	}

	uvec idx = find(mean(predMat, 1) > 0);
	labels.fill(-1);
	labels.elem(idx).fill(1);
}

template class BaggingClassifier<AdaBoost>;