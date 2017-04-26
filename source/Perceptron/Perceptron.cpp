//--------------------------------------------------------------------------------------
//Name			:		Perceptron
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description		:		Implementation of the Perceptron Algorithm
//Copyright		:
//Version		:
//Modified Date		:		04/26/2017
//--------------------------------------------------------------------------------------


#include <iostream>
#include <armadillo>
#include <math.h>
#include "Perceptron.h"


using namespace std;
using namespace arma;

//Implementation of the Fit function
void Perceptron::train(const mat& data, const colvec& Y, uword epoch) {
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
		for(uword i = 0; i < n; i++){	
			uword f_word;
			if (X.row(i)*w > 0)
				f_word = 1;
			else
				f_word = -1;
			w = w + (f_word*Y(i))*X.row(i).t();			
		}
	}
	weight = w;
}


//Implementation of the predict function 
void Perceptron::predict(const mat& data, colvec& Y) {
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
		if (A(i) > 0)
			Y(i) = 1;
		else
			Y(i) = 0;
}



