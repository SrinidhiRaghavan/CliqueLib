//============================================================================
// Name        : Perceptron.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Perceptron implementation
//============================================================================

#include "Perceptron.h"

using namespace std;
using namespace arma;

//Implementation of the Perceptron Constructor
Perceptron:: Perceptron(double n){
	neta = n;
}


//Implementation of the Fit function
void Perceptron::train(const mat& data, const colvec& Y, uword epoch) 
{
	/*
	n - Number of data entries in data
	d - Dimension of each entry in data
	w - Weight vector including the bias
	*/

	uword n = size(data, 0);
	uword d = size(data, 1);
	colvec w(d + 1);
	w.fill(0);


	//Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
	mat X = join_horiz(data, ones(n));

	//Applying Gradient Descent to update the weights 
	for (uword t = 0; t < epoch; t++) {
		colvec delta(d+1);
		delta.fill(0);
		for(uword i = 0; i < n; i++){	
			uword f_word =  -1;
			if (dot(X.row(i),w) >= 0)
			    f_word = 1;

			if (f_word * Y(i) < 0)
				delta = delta - f_word*X.row(i).t();
		}

		w = w - neta/n * delta;
	}
	weight = w;
}


//Implementation of the predict function 
void Perceptron::predict(const mat& data, colvec& Y) 
{
	//n - Number of data entries in data
	uword n = size(data, 0);
	Y.zeros(n, 1);

	//Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
	mat X = join_horiz(data, ones(n));

	/*
	Making the Predictions
	Step 1 - Find the product of the data entries and the weight
	Step 2 - If the product >= 0, then predict 1 else -1
	*/
	colvec A = X*weight;
	for (uword i = 0; i < n; i++)
        {
		if (A(i) >= 0)
			Y(i) = 1;
		else
			Y(i) = -1;
        }
}



