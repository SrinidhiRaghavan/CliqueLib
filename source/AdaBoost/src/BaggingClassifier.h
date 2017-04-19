//============================================================================
// Name        : BaggingClassifier.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib BaggingClassifier definition
//============================================================================

#pragma once
#include <armadillo>

template<typename T>
class BaggingClassifier {
	std::vector<T*> base_estimators;
	arma::uword n_estimators;
	arma::uword max_samples;

public:
	BaggingClassifier(arma::uword, arma::uword);
	void fit(const arma::mat&, const arma::colvec&, arma::uword);
};