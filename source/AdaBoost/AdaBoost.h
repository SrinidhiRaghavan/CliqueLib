//============================================================================
// Name        : AdaBoost.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib AdaBoost definition
//============================================================================


#ifndef __ADABOOST_H__
#define __ADABOOST_H__

#pragma once
#include <iostream>
#include <memory>
#include <armadillo>
#include "Stump.h"
#include "BaseClassifier.h"

class AdaBoost : public BaseClassifier 
{
    private:
	std::vector<std::shared_ptr<Stump>> weakClassifiers;
	std::vector<double> weights;

    public:
        AdaBoost() {}
	void train(const arma::mat&, const arma::colvec&, arma::uword);
	void predict(const arma::mat&, arma::colvec&);
	std::shared_ptr<Stump> buildStump(const arma::mat&, const arma::colvec&, const arma::colvec&);
};

#endif
