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
#include <memory>
#include <armadillo>

template<class C> concept bool Classifier = requires(C c, const arma::mat& X, const arma::colvec& Y, arma::uword iter, arma::colvec& labels) 
{
    { c.train(X, Y, iter) };
    { c.predict(X, labels) };
};

template<Classifier C>
class BaggingClassifier 
{
    private:
	std::vector<std::shared_ptr<C>> base_estimators; /*!< base_estimators variable represents the number of classifiers
                                                              in an ensemble.
                                                          */
	arma::uword n_estimators;
	arma::uword max_samples;

    public:
	BaggingClassifier(arma::uword, arma::uword); /**< The BaggingClassifier object contains two  main variables, the
                                                          first of which represents the number of estimators and is
                                                          accompanied with max samples.
                                                      */


	void train(const arma::mat&, const arma::colvec&, arma::uword); /**< The train function accepts a matrix of
                                                                             sample inputs, a column vector of sample
                                                                             labels, and a uword representing the number
                                                                             of epochs. Given these inputs, the bagging 
                                                                             classifier iterates over the number of
                                                                             estimators and calls the train functions of
                                                                             corresponding algorithms. As this is bagging,
                                                                             the sets are randomized and models are
                                                                             inserted into base_estimators
                                                                         */

	void predict(const arma::mat&, arma::colvec&); /**< The predict function iterates over base_estimators, which
                                                            contains all the classifiers in the ensemble, and predicts 
                                                            on each model in the ensemble. Consequently, given the
                                                            predictions from all models, the ensemble combines the 
                                                            outputs and yields a final vector of labels. 
                                                        */
};

#endif
