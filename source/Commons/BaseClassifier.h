//============================================================================
// Name        : BaseClassifier.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : BaseClassifier interface
//============================================================================

#pragma once
#include <armadillo>

/**
 * BaseClassifier provides an interface that each Armadillo-based algorithm in the library implements. 
 * Each algorithm constains at least a train function and a predict function that needs 
 * to be implemented by that particular algorithm.
 */
class BaseClassifier 
{
    public:
	virtual void train(const arma::mat&, const arma::colvec&, arma::uword) = 0; /**< The train function is virtual 
                                                                                         and is implemented by every
                                                                                         Armadillo-based algorithm in
                                                                                         CliqueLib. The train function
                                                                                         accepts a matrix of
                                                                                         sample inputs, a column vector of
                                                                                         sample labels, and a uword
                                                                                         representing the number of epochs.
                                                                                         Given these inputs, the algorithms
                                                                                         are able to generate a model for
                                                                                         predicting on new inputs. 
                                                                                     */

	virtual void predict(const arma::mat&, arma::colvec&) = 0; /**< The predict function is virtual and is
                                                                        implemented by every Armadillo-based algorithm in
                                                                        CliqueLib. The predict function accepts a matrix 
                                                                        of inputs and a column vector of labels
                                                                        initialized to 0. As the column vector is passed by
                                                                        reference, the
                                                                        algorithm simply inserts the computed predictions
                                                                        into the vector and returns void. 
                                                                    */
};
