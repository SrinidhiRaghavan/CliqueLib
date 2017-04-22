//============================================================================
// Name        : BaggingClassifier.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib BaggingClassifier definition
//============================================================================


#ifndef __BAGGINGCLASSIFIER_H__
#define __BAGGINGCLASSIFIER_H__

#pragma once
#include <armadillo>

template<typename T>
class BaggingClassifier {
	std::vector<T*> base_estimators;
	arma::uword n_estimators;
	arma::uword max_samples;

public:
	BaggingClassifier(arma::uword, arma::uword);
	void train(const arma::mat&, const arma::colvec&, arma::uword);
	void predict(const arma::mat&, arma::colvec&);
};

#endif
