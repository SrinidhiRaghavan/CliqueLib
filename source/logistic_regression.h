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


using namespace std;

class LogisticRegression
{
    public:
        //default constructor
        LogisticRegression(vector<vector<float> > train_file) : LogisticRegression(train_file, 1){}

        //constructor
        LogisticRegression(vector<vector<float> > train_file, int k);

        //get k
        int getK() { return k; }

	//calculate sigmoid function
	float sigmoid_function(float z);

        //Train 
        vector<vector<float> > train();

        //Classify
        float classify(vector<float> instance, vector<float> coefficients);
       
    private:
        int k;
        vector<vector<float> > train_file;
};

#endif
