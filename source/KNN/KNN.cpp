//--------------------------------------------------------------------------------------
//Name			:		SVM
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description	:		Implementation of the KNN functions
//Copyright		:
//Version		:
//Modified Date	:
//--------------------------------------------------------------------------------------

#include <iostream>
#include <armadillo>
#include "KNN.h"


using namespace std;
using namespace arma;
//Constructor for the SVM
KNN::KNN(uword K_val) {
	K = K_val;
}


//Implementation of the Fit function
void KNN::train(const mat& X, const colvec& Y, uword epoch = 1) {
	Xtrain = X;
	Ytrain = Y;
}


//Implementation of the predict function 
void KNN::predict(const mat& Xtest, colvec& Ytest) {
    uword n = size(Xtest, 0);
    Ytest.zeros(n, 1);

	/*
	We compute the square of the Euclidean distance between n training examples and m test examples 
	X2 - Stores the 2-norm of the n training data in a n*1 vector
	Y2 - Stores the 2-norm of the m training data in a 1*m vector 
	XY - Stores the twice of the element wise dot product of Xtrain and Xtest in a n*m matrix
	dist - Stores the square of the distances between every test data from every train data in a n*m matrix
	*/
 	mat X2 = sum(Xtrain % Xtrain, 1);
	mat Y2 = (sum(Xtest % Xtest, 1)).t();
	mat XY = 2* Xtrain * Xtest.t();
	mat dist = XY.each_col() + X2;
	dist = dist.each_row() - Y2;

	/*
	Sorting and finding the top K-nearest neighbors 
	A majority voting is done amongst the labels of the neighbors 
	The most common label is chosen as the answer 
	*/
	uword m = size(dist, 1);
	for (uword i = 0; i < m; i++) {
		uvec c = sort_index(dist.col(i));
		c = c(span(0, K - 1));

		uword total = sum(Ytrain.elem(c)); 

		if (total >= 0)
			Ytest(i) = 1;
		else
			Ytest(i) = -1;
	}	
}
