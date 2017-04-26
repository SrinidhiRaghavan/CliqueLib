//--------------------------------------------------------------------------------------
//Name			:		Logistic Regression
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description		:		Header for the Logistic
//Copyright		:
//Version		:
//Modified Date		:		04/22/2017
//--------------------------------------------------------------------------------------


#ifndef __Logistic_H__
#define __Logistic_H__

#pragma once
#include <iostream>
#include <armadillo>
#include "BaseClassifier.h"

using namespace std;
using namespace arma;

/**
 * Logistic regression, also called logit regression, is a machine learning algorithm used for binary 
 * classification. Logistic regression is named after its core function, the logistic function, also called 
 * the sigmoid function. The algorithm predicts what the probability is of an input belonging to one of the 
 * two classes. If the probability is more than 0.5, the output is a prediction for that class. Otherwise, 
 * the prediction is for the other class.
 */
class Logistic : public BaseClassifier {
	colvec weight; /*!< Weight is a column vector of coefficients and is evaluated using stochastic
                            gradient descent
                        */
	double alpha; /*!< alpha is a learning rate, which states how much the coefficients change 
                           every time they are updated 
                       */
                    
public:
        Logistic() : Logistic(0.01){} /**< A default constructor for Logistic Regression is available
                                           and sets the default learning rate alpha to 0.01
                                       */

	Logistic(double); /**< A logistic regression object is created by a constructor wherein the
                               user must specify the learning rate alpha. The learning rate is used
                               when calculating the coefficients with stochastic gradient descent.
                           */
	void train(const mat&, const colvec&, uword); /**< The train function accepts a matrix of
                                                           sample inputs, a column vector of sample
                                                           labels, and a uword representing the number
                                                           of epochs. Given these inputs, logistic
                                                           regression is able to generate a model for
                                                           predicting on new inputs. 
                                                       */

	void predict(const mat&, colvec&); /**< The predict function accepts a matrix of inputs 
                                                and a column vector of labels initialized to 0. 
                                                As the column vector is passed by reference, the
                                                algorithm simply inserts the computed predictions into
                                                the vector and returns void. 
                                            */

	colvec sigmoid(const colvec&); /**< The sigmoid function calculates the sigmoid function. 
                                            The function receives a column vector for input and 
                                            returns a column vector as a result. The logistic function 
                                            transforms any input into the range (0, 1). 
                                        */

        double getLearningRate() { return alpha; } /**< The user can retrieve alpha by calling 
                                                       the function's getter 
                                                   */

        void setLearningRate(double alpha) { this->alpha = alpha; } /**< The user can change 
                                                                         the value of alpha by calling 
                                                                         the function's setter 
                                                                     */
        
};

#endif
