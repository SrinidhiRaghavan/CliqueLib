//============================================================================
// Name        : Perceptron.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Perceptron definition
//============================================================================

#ifndef __Perceptron_H__
#define __Perceptron_H__

#pragma once
#include <iostream>
#include <armadillo>
#include <cmath>
#include "BaseClassifier.h"

using namespace std;
using namespace arma;

/**
 * Perceptron is a supervised learning algorithm for binary classification. The predictions are made
 * on a linear predictor function that combines a set of weights in the feature vector. 
 */
class Perceptron : public BaseClassifier
{
    private:
	colvec weight; /*!< Weight is a column vector of coefficients and is evaluated using stochastic
                            gradient descent
                        */

	double neta;   /*!< neta is a learning rate, which states how much the coefficients change 
                           every time they are updated 
                       */

    public:
        Perceptron() : Perceptron(0.01){} /**< A default constructor for Perceptron is available
                                              and sets the default learning rate alpha to 0.01
                                          */

	Perceptron(double);  /**< A Perceptron object is created by a constructor wherein the
                                  user must specify the learning rate neta. The learning rate is used
                                  when calculating the coefficients with stochastic gradient descent.
                              */

	void train(const mat&, const colvec&, uword); /**< The train function accepts a matrix of
                                                           sample inputs, a column vector of sample
                                                           labels, and a uword representing the number
                                                           of epochs. Given these inputs, perceptron 
                                                           is able to generate a model for
                                                           predicting on new inputs. 
                                                       */

	void predict(const mat&, colvec&); /**< The predict function accepts a matrix of inputs 
                                                and a column vector of labels initialized to 0. 
                                                As the column vector is passed by reference, the
                                                algorithm simply inserts the computed predictions into
                                                the vector and returns void. 
                                            */
};

#endif
