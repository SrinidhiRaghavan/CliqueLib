//============================================================================
// Name        : logistic_regression.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Logistic Regression definition
//============================================================================

#ifndef __LOGISTIC_REGRESSION_STD_H__
#define __LOGISTIC_REGRESSION_H__

#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <limits>

using namespace std;

/**
 * LogisticRegressionStd is CliqueLib's implementation of the Logistic Regression algorithm with
 * vector<vector> > data structures rather than Armadillo. Logistic regression, also called logit
 * regression, is a machine learning algorithm used for binary 
 * classification. Logistic regression is named after its core function, the logistic function, also called 
 * the sigmoid function. The algorithm predicts what the probability is of an input belonging to one of the 
 * two classes. If the probability is more than 0.5, the output is a prediction for that class. Otherwise, 
 * the prediction is for the other class.
 */
class LogisticRegressionStd
{
    public:
        //default constructor
        LogisticRegressionStd(vector<vector<float> > train_file) : LogisticRegressionStd(train_file, 100, 0.01){} 
                                 /**< A default constructor for Logistic Regression is available and sets the 
                                      default learning rate alpha to 0.01 and the number of epochs to 100.
                                  */

        //constructor
        LogisticRegressionStd(vector<vector<float> > train_file, int num_epochs, float learning_rate);
                                /**< A logistic regression object is created by a constructor wherein the
                                     user must specify the learning rate alpha alongside the integer number
                                     of epochs and the training dataset train_file. The learning rate is used
                                     when calculating the coefficients with stochastic gradient descent.
                                 */

        //get num_epochs
        int get_num_epochs() { return num_epochs; } /**< The user can retrieve the number of epochs by calling 
                                                       the function's get_num_epochs() getter 
                                                     */

        //get learning_rate
        float get_learning_rate() { return learning_rate; } /**< The user can retrieve the learning rate by 
                                                                 calling the function's get_learning_rate() getter 
                                                              */

        //set num_epochs
        void set_num_epochs(int num_epochs) { this->num_epochs = num_epochs; }
                                                           /**< The user can change 
                                                                the value of alpha by calling 
                                                                the function's set_learning_rate setter 
                                                            */

        //set learning_rate
        void set_learning_rate(float learning_rate) { this->learning_rate = learning_rate; }
                                                           /**< The user can change 
                                                                the value of the learning rate alpha by calling 
                                                                the function's set_learning_rate setter 
                                                            */

	//calculate sigmoid function
	float sigmoid_function(float); /**< The sigmoid function calculates the sigmoid function. 
                                            The function receives a float for input and 
                                            returns a float as a result. The logistic function 
                                            transforms any input into the range (0, 1). 
                                        */

        //Train - returns a vector of coefficients
        vector<float> train();  /**< The train function trains the model for logistic regression and returns a vector
                                     of coefficients. The coefficients are obtained using stochastic gradient descent.
                                     The training dataset is iterated over num_epochs times and coefficients are
                                     consistently modified to build a reliable model.
                                 */
        //Predict
        float predict_label(vector<float>, vector<float>, bool); /**< Predict_label predicts the label for a
                                                                      single example. On the other hand, the
                                                                      predict function takes a vector of
                                                                      examples and predicts a label for every
                                                                      one of them. Predict_label takes 3 inputs as 
                                                                      predict, however, vector<float> is passed 
                                                                      for a single instance rather than the vector 
                                                                      of instances passed to predict. 
                                                                  */

        //Predict multiple labels
        vector<float> predict(vector<vector<float> >, vector<float>, bool binary = true);
                                                         /**< Predict_label predicts the label for a
                                                            single example. On the other hand, the
                                                            predict function takes a vector of
                                                            examples and predicts a label for every
                                                            one of them. The function accepts as input the
                                                            vector<vector<float> > of instances to predict, vector<float>
                                                            of coefficients, and a boolean binary which states whether 
                                                            the results should be returned as a real value [0, 1] or 
                                                            as a binary - 0 or 1.
                                                        */
       
    private:
	int num_epochs; /*!< num_epochs is the integer number of iterations that will be used 
                             to refine the coefficients. 
                         */
        float learning_rate; /*!< alpha is a learning rate, which states how much the coefficients change 
                                  every time they are updated. 
                              */
        vector<vector<float> > train_file; /*!< The train file is used for training the model, and thus the 
                                                coefficients 
                                            */
};

#endif
