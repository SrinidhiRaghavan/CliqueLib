//============================================================================
// Name        : logistic_regression.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Logistic regression implementation
//============================================================================

#include <iostream>
#include <armadillo>
#include <math.h>
#include "logistic_regression.h"


using namespace std;
using namespace arma;

//Constructor for the SVM
Logistic::Logistic(double alpha) {
	this->alpha = alpha;
}


//Implementation of the Fit function
void Logistic::train(const mat& data, const colvec& Y, uword epoch) {
	/*
	n - Number of data entries in data
	d - Dimension of each entry in data
	w - Weight vector including the bias
	*/
	uword n = size(data, 0);
	uword d = size(data, 1);
	colvec w(d + 1);
	w.fill(0);

	colvec labels(n);
	for(uword i = 0; i<n; i++){
		if (Y(i) == -1)
		    labels(i) = 0;
		else
		    labels(i) = 1;
	
	}

	//Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
	mat X = join_horiz(data, ones(n, 1));

	//Applying Gradient Descent to update the weights 
	for (uword t = 0; t < epoch; t++) {
		w += (alpha/(t+1)) * X.t() * (labels - sigmoid(X*w));
	}
	weight = w;
}


//Implementation of the predict function 
void Logistic::predict(const mat& data, colvec& Y) {
	//n - Number of data entries in data
	uword n = size(data, 0);
	Y.zeros(n, 1);

	//Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
	mat X = join_horiz(data, ones(n, 1));

	/*
	Making the Predictions
	Step 1 - Find the product of the data entries and the weight
	Step 2 - If the product >= 0, then predict 1 else -1
	*/
	colvec A = X*weight;
	for (uword i = 0; i < n; i++)
		if (A(i) >= 0.5)
			Y(i) = 1;
		else
			Y(i) = -1;
}

//Implementation of the Sigmoid Function 
colvec Logistic::sigmoid(const colvec& Z) {
	double e = 2.71828;
	uword n = size(Z, 0);
	colvec eZ(n);

	for (uword i = 0; i < n; i++) 
		eZ(i) = (1.0 / (1.0 + pow(e, -1 * Z(i))));

	return eZ;
}


