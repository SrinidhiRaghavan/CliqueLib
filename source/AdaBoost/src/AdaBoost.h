//============================================================================
// Name        : AdaBoost.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib AdaBoost definition
//============================================================================

#pragma once
#include <iostream>
#include <armadillo>
#include "Stump.h"

class AdaBoost {
	std::vector<Stump*> weakClassifiers;
	std::vector<double> weights;

public:
	AdaBoost();
	void fit(const arma::mat&, const arma::colvec&, arma::uword);
	void predict(const arma::mat&, arma::colvec&);
	Stump* buildStump(const arma::mat&, const arma::colvec&, const arma::colvec&);
};