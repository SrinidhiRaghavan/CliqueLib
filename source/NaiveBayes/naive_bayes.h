/**
naive_bayes.h
Stan Peceny
skp2140
4/20/2017
*/

#ifndef __NAIVE_BAYES_H__
#define __NAIVE_BAYES_H__

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <numeric>

using namespace std;

class NB
{
    public:
        //default constructor
        //NB(vector<vector<float> > train_file) : NB(train_file, 1){}

        //constructor
        NB(vector<vector<float> > train_file);

        //separate the examples by class
        map<float, vector<vector<float> > > separate_each_class(); 

	//Mean
	float mean_average(vector<float> attributes);

	//Standard deviation
	float standard_deviation(vector<float> attributes);

        //Summary 
        vector<float> summary(vector<vector<float> > class_dataset);

        //Train 
        map<float, vector<float> > train();

        //Classify
        float classify(vector<float> instance);
       
    private:

        vector<vector<float> > train_file;
};

#endif
