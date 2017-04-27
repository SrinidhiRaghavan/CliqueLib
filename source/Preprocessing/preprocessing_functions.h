//============================================================================
// Name        : preprocessing_functions.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Preprocessing functions definition
//============================================================================

#ifndef __PREPROCESSING_FUNCTIONS_H__
#define __PREPROCESSING_FUNCTIONS_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <armadillo>
#include "Dataset.h"

using namespace std;

void read_csv(string file,
                               arma::mat& X,
                               arma::colvec& Y,
	      			bool title = false,
	      			char separate_ex = ',', 
              			char comment = '#'
                              );
//Reading a *.csv file
vector<vector<float> > read_csv(string file,
	      			bool title = false,
	      			char separate_ex = ',', 
              			char comment = '#'
             			);

//Split the dataset into a train and test section
void split_train_test(const arma::mat& X, const arma::colvec& Y, Dataset& data, double trainProportion);

#endif
