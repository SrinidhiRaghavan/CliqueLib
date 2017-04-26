//============================================================================
// Name        : logistic_regression.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Logistic Regression definition
//============================================================================

#ifndef __LOGISTIC_REGRESSION_STD_H__
#define __LOGISTIC_REGRESSION_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <map>
#include <utility>
#include <limits>


using namespace std;

class LogisticRegressionStd
{
    public:
        //default constructor
        LogisticRegressionStd(vector<vector<float> > train_file) : LogisticRegressionStd(train_file, 100, 0.01){}

        //constructor
        LogisticRegressionStd(vector<vector<float> > train_file, int num_epochs, float learning_rate);

        //get num_epochs
        int get_num_epochs() { return num_epochs; }

        //get learning_rate
        float get_learning_rate() { return learning_rate; }

        //set num_epochs
        void set_num_epochs(int num_epochs) { this->num_epochs = num_epochs; }

        //set learning_rate
        void set_learning_rate(float learning_rate) { this->learning_rate = learning_rate; }

	//calculate sigmoid function
	float sigmoid_function(float z);

        //Train - returns a vector of coefficients
        vector<float> train();

        //Predict
        float predict(vector<float> instance, vector<float> coefficients, bool binary = false);
       
    private:
	int num_epochs;
        float learning_rate;
        vector<vector<float> > train_file;
};

#endif
