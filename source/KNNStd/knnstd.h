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
        float euclideanDistance (int, vector<float>, vector<float>);

        //find K neighbors
        vector<vector<float> > findNeighbors(vector<float>);

        //determine class
        float findClass(vector<vector<float> >);

        //Train 
        vector<vector<float> > train();

        //Predict a single label
        float predict_label(vector<float>);

        //Predict multiple labels
        vector<float> predict(vector<vector<float> >);
       
    private:
        int k;
        vector<vector<float> > train_file;
};

#endif
