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
	std::vector<std::shared_ptr<Stump>> weakClassifiers; /*!< A sequence of decision stumps trained on different dimension of data 
                                                            */
	std::vector<double> weights; /*!< Sequence of weights learnt during training for each of the weak classifier
                                    */


    public:
    AdaBoost() {}
	void train(const arma::mat&, const arma::colvec&, arma::uword); /**< The train function accepts a matrix of sample inputs,
                                                                         a column vector of labels representing the ground truth,
                                                                         and number of Stumps to create for training and prediction.
                                                                        */

	void predict(const arma::mat&, arma::colvec&); /**< The predict function accepts a matrix of inputs
                                                        and a reference to an empty column vector which
                                                        shall be filled with the predicted labels
                                                        */

	std::shared_ptr<Stump> buildStump(const arma::mat&, const arma::colvec&, const arma::colvec&); /**< buildStump Optimally selects dimensions to built
                                                                                                        decision stumps over.
                                                                                                    */

};

#endif
