//--------------------------------------------------------------------------------------
//Name			:		Logistic Regression
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description	:		Implementation of the Logistic Regression functions
//Copyright		:
//Version		:
//Modified Date	:		04/22/2017
//--------------------------------------------------------------------------------------

#include <iostream>
#include <armadillo>
#include <math.h>
#include "Logistic.h"


using namespace std;
using namespace arma;

//Constructor for the SVM
Logistic::Logistic(uword C_val = 0.1) {
	C = C_val;
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
	rowvec w(d + 1);
	w.fill(0);


	//Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
	mat X = join_horiz(data, ones(n));

	//Applying Gradient Descent to update the weights 
	for (uword t = 0; t < epoch; t++) {
		w += C * X.t() * (Y - sigmoid(X*w));
	}
	weight = w;
}


//Implementation of the predict function 
void Logistic::predict(const mat& data, colvec& Y) {
	//n - Number of data entries in data
	uword n = size(data, 0);

	//Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
	mat X = join_horiz(data, ones(n));

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
			Y(i) = 0;
}

//Implementation of the Sigmoid Function 
colvec sigmoid(const colvec& Z) {
	double e = 2.71828;
	uword n = size(Z, 0);
	colvec eZ(n);

	for (uword i = 0; i < n; i++) 
		eZ(i) = (1.0 / (1.0 + pow(e, -1 * Z(i))));

	return eZ;
}

