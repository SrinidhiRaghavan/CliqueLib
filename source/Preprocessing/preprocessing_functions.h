/**
preprocessing_functions.h
Stan Peceny
skp2140
4/1/2017
*/

#ifndef __PREPROCESSING_FUNCTIONS_H__
#define __PREPROCESSING_FUNCTIONS_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <armadillo>

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
void split_test_train(vector<vector<float> > file, 
		      float train_part,
		      vector<vector<float> >& train_file,
		      vector<vector<float> >& test_file
		     );

#endif
