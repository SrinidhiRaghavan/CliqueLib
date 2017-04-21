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

using namespace std;

class NB
{
    public:
        //default constructor
        NB(vector<vector<float> > train_file) : NB(train_file, 1){}

        //constructor
        NB(vector<vector<float> > train_file, int k);

        //Train 
        vector<vector<float> > train();

        //Classify
        float classify(vector<float> instance);
       
    private:
        int k;
        vector<vector<float> > train_file;
};

#endif
