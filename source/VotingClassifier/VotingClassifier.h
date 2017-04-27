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
#include <memory>
#include <armadillo>
#include "BaseClassifier.h"

class VotingClassifier 
{
    private:
	std::vector<std::shared_ptr<BaseClassifier>> base_estimators;

    public:
	VotingClassifier() {}
	void train(const arma::mat&, const arma::colvec&, arma::uword);
	void predict(const arma::mat&, arma::colvec&);
        void addClassifier(std::shared_ptr<BaseClassifier>);
};

#endif
