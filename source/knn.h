/**
knn.h
Stan Peceny
skp2140
4/2/2017
*/

#ifndef __KNN_H__
#define __KNN_H__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

class KNN
{
    public:
        //default constructor
        KNN(vector<vector<float> > train_file) : KNN(train_file, 1){}

        //constructor
        KNN(vector<vector<float> > train_file, int k);

        //Train 
        vector<vector<float> > train();

        //Classify
        float classify(vector<float> instance);
       
    private:
        int k;
        vector<vector<float> > train_file;
};

#endif
