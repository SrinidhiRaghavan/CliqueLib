//============================================================================
// Name        : SVM.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib SVM definition
//============================================================================

#ifndef __SVM_H__
#define __SVM_H__

#pragma once
#include <iostream>
#include <armadillo>
#include "BaseClassifier.h"

using namespace std;
using namespace arma;

class SVM : public BaseClassifier 
{
    private:
	colvec weight; /*!< Weight is a column vector of coefficients computed by the Pegasos Algorithm 
                            for Linear Kernels
                        */
	double C; /*!< C is a regularization parameter, which is used in the SVM train function
                       to compute the lambda parameter for SVM. The Lambda parameter is 
                       then used in the Pegasos algorithm to find the weight vector.
                   */
	
    public:
	SVM() : SVM(0.1) {} /**< A default constructor for SVM is available
                                 and sets the default double C, the regularization parameter, to 0.01.
                             */

	SVM(double); /**< An SVM object is created by a constructor wherein the
                          user must specify the regularization parameter C. The regularization parameter 
                          is used in the SVM train function to compute the lambda parameter for SVM. 
                          The Lambda parameter is then used in the Pegasos algorithm to find the weight vector.
                      */

	void train(const mat&, const colvec&, uword); /**< The train function accepts a matrix of
                                                           sample inputs, a column vector of sample
                                                           labels, and a uword representing the number
                                                           of epochs. Given these inputs, SVM
                                                           can apply the Pegasos algorithm for Linear Kernels 
                                                           to Find the Ideal Weight Vector which constitutes 
                                                           a model for predicting on new inputs. 
                                                       */

	void predict(const mat&, colvec&); /**< The predict function accepts a matrix of inputs 
                                                and a column vector of labels initialized to 0. 
                                                As the column vector is passed by reference, the
                                                algorithm simply inserts the computed predictions into
                                                the vector and returns void. There are two major steps to SVM
                                                predictions:
                                                Step 1 - Find the product of the data entries and the weight 
                                                Step 2 - If the product >= 0, then predict 1 else -1
                                            */
        
        //get Regularization Parameter C
        double getRegularizationParameter() { return C; }; /**< The user can retrieve the regularization parameter C by
                                                                calling the getRegularizationParameter getter. 
                                                            */
        
        //set Regularization Parameter C
        void setRegularizationParameter(double C) { this->C = C; } /**<  The user can change 
                                                                         the value of the regularization parameter C by
                                                                         calling the setRegularizationParameter setter. 
                                                                     */
};

#endif
