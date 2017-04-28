//============================================================================
// Name        : SVM.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib SVM implementation
//============================================================================

#include <iostream>
#include <cmath>
#include <algorithm>
#include <armadillo>
#include <random>

#include "SVM.h"

using namespace std;
using namespace arma;

//Constructor for the SVM
SVM::SVM(double C_val) 
{
    C = C_val;
}


//Implementation of the train function
void SVM::train(const mat& data, const colvec& Y, uword epoch) 
{
	
    //n - Number of data entries in data
    //d - Dimension of each entry in data
    //L - Lambda parameter for SVM
    //w - Weight vector including the bias 
	
    uword n = size(data, 0);
    uword d = size(data, 1);
    double L = 1 / (n*C);
    colvec w(d+1);
    w.fill(0);
    
    //Uniform Random Generator used for Generating the data entry indices randomly
    default_random_engine generator;
    uniform_int_distribution<int> distribution(0, n-1); 
	
    //Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
    mat X = join_horiz(data, ones(n, 1));

    //Uses Pegasos Algorithm for Linear Kernels to Find the Ideal Weight Vector for the Data
    for (uword t = 0; t < epoch; t++) 
    {
		
        //nt - Learning rate which is dependent on Lambda and the epoch number 
	//r  - Random number generated which chooses a particular data from X uniformly
	//xt - rth row of X
	//yt - rth value of Y		

	double nt = 1 / (L*(t+1));
	uword r = distribution(generator);
	rowvec xt = X.row(r);
	double yt = Y(r);
	double a = dot(w, xt)*yt;
	if (a < 1.0)
	    w = (1 - nt*L)*w + nt*yt*xt.t();
	else
   	    w = (1 - nt*L)*w;
    }
    weight = w;
}


//Implementation of the predict function 
void SVM::predict(const mat& data, colvec& Y) 
{
    //n - Number of data entries in data
    uword n = size(data, 0);
    Y.ones(n, 1);
	
    //Concatenating the matrix X with a column of 1's. Bias is the weight corresponding to this column
    mat X = join_horiz(data, ones(n, 1));

    //Making the Predictions
    //Step 1 - Find the product of the data entries and the weight 
    //Step 2 - If the product >= 0, then predict 1 else -1
	
    colvec A = X*weight;
    uvec idx = find(A < 0);
    Y.elem(idx).fill(-1);
}

