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

}

template class BaggingClassifier<AdaBoost>;