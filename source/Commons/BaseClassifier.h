//============================================================================
// Name        : BaseClassifier.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : BaseClassifier interface
//============================================================================

#pragma once
#include <armadillo>

class BaseClassifier {
public:
	virtual void train(const arma::mat&, const arma::colvec&, arma::uword) = 0;
	virtual void predict(const arma::mat&, arma::colvec&) = 0;
};
