/**
logistic_regression.h
Stan Peceny
skp2140
4/18/2017
*/

#ifndef __LOGISTIC_REGRESSION_H__
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
//#include "BaseClassifier.h"


using namespace std;

class LogisticRegression //: public BaseClassifier
{
    public:
        //default constructor
        LogisticRegression(vector<vector<float> > train_file) : LogisticRegression(0.01){}

        //constructor
        LogisticRegression(float learning_rate);

        //get learning_rate
        float get_learning_rate() { return learning_rate; }

        //set learning_rate
        void set_learning_rate(float learning_rate) { this->learning_rate = learning_rate; }

	//calculate sigmoid function
	float sigmoid_function(float z);

        //Train - returns a vector of coefficients
        void train(vector<vector<float> >& train_file, vector<float>& labels_sample, int num_epochs);

        //Predict
        void predict(vector<vector<float> >& instances, vector<float>& labels_found, bool binary = true);
       
    private:
        float learning_rate;
	vector<vector<float> > coefficients;

};

#endif
