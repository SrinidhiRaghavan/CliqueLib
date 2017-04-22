//============================================================================
// Name        : VotingClassifier.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib VotingClassifier definition
//============================================================================


#ifndef __VOTINGCLASSIFIER_H__
#define __VOTINGCLASSIFIER_H__

#pragma once
#include <armadillo>
#include "BaseClassifier.h"

class VotingClassifier {
	std::vector<BaseClassifer*> base_estimators;
	//arma::uword n_estimators;
	//arma::uword max_samples;

public:
	VotingClassifier(arma::uword, arma::uword);
	void train(const arma::mat&, const arma::colvec&, arma::uword);
	void predict(const arma::mat&, arma::colvec&);
    void addClassifier(BaseClassifer*);
};

#endif
