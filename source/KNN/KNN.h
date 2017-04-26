//============================================================================
// Name        : KNN.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib KNN definition
//============================================================================

#ifndef __KNN_H__
#define __KNN_H__

#pragma once
#include <iostream>
#include <armadillo>
#include "BaseClassifier.h"

using namespace std;
using namespace arma;

/**
 * K-Nearest Neighbors (kNN) algorithms differs greatly from many machine learning algorithms since 
 * it does not implement a model. In fact, the entire training dataset could be considered as the
 * model for kNN. The kNN algorithm searches through the training example for k closest instances. 
 * The prevailing prediction of these k nearest neighbors is returned as the prediction for the new
 * input. Euclidean distance is used for measuring the similarity between instances.
 */
class KNN : public BaseClassifier {
	uword K; /*!< K represents the number of nearest neighbors of an input instance. */
	mat Xtrain; /*!< Xtrain is the matrix representing the training dataset of attributes.  */
	colvec Ytrain; /*!< Ytrain is the column vector representing the labels corresponding to the
                            examples in the training dataset. 
                        */

public:
        KNN() : KNN(3){} /**< A default constructor for KNN is available
                             and sets the default value of K to 3.
                          */
        
	KNN(uword); /**< A KNN object is created by a constructor wherein the user must specify 
                         the value k representing k nearest neighbors.
                     */
	void train(const mat&, const colvec&, uword); /**< The train function accepts a matrix of 
                                                           sample inputs, a column vector of sample 
                                                           labels, and a uword representing the number 
                                                           of epochs. The number of epochs is never
                                                           used in KNN but was kept for consistency.
                                                           Given the other inputs, KNN 
                                                           is able to generate a model 
                                                           for predicting on new inputs. 
                                                       */
	void predict(const mat&, colvec&); /**< The predict function accepts a matrix of inputs and 
                                                a column vector of labels initialized to 0. As the
                                                column vector is passed by reference, the algorithm
                                                simply inserts the computed predictions into the
                                                vector and returns void. 
                                            */

        uword getK() { return K; } /**< The user can retrieve K by calling the function's getter. */

        void setK(uword K) { this->K = K; } /**< The user can change the value of K by calling 
                                                 the function's setter. 
                                             */
};

#endif
