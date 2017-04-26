//============================================================================
// Name        : knnstd.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Knnstd definition
//============================================================================

#ifndef __KNNSTD_H__
#define __KNNSTD_H__

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

class KNNStd
{
    public:
        //default constructor
        KNNStd(vector<vector<float> > train_file) : KNNStd(train_file, 1){}

        //constructor
        KNNStd(vector<vector<float> > train_file, int k);

        //get k
        int getK() { return k; }

        //set k
        void setK(int k) { this->k = k; }
        
        // calculate Euclidean Distance
        float euclideanDistance (int length, vector<float> instance1, vector<float> instance2);

        //find K neighbors
        vector<vector<float> > findNeighbors(vector<float> instance);

        //determine class
        float findClass(vector<vector<float> > k_neighbors);

        //Train 
        vector<vector<float> > train();

        //Predict
        float predict(vector<float> instance);
       
    private:
        int k;
        vector<vector<float> > train_file;
};

#endif
