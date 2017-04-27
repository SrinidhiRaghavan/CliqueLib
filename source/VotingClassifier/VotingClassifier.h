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
	std::vector<std::shared_ptr<BaseClassifier>> base_estimators; /*!< base_estimators contains all the classifiers
                                                                           added into the ensemble
                                                                       */

    public:
	VotingClassifier() {} /**< The constructor VotingClassifier creates a very simple VotingClassifier object */

	void train(const arma::mat&, const arma::colvec&, arma::uword); /**< The train function calls the train function
                                                                             for the corresponding classifier in
                                                                             base_estimators
                                                                         */
	void predict(const arma::mat&, arma::colvec&); /**< The predict function calls the predict function
                                                            for each corresponding classifier in base_estimators, 
                                                            and takes the majority vote to yield predictions
                                                        */

        void addClassifier(std::shared_ptr<BaseClassifier>); /**< addClassifier method adds a classifier to base_estimators,
                                                                  and hence adds an extra model to the
                                                                  ensemble               
                                                              */
};

#endif
