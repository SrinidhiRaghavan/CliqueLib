/**
knn.cpp
Stan Peceny
skp2140
4/2/2017
*/

#include "knn.h"

//Constructor
KNN::KNN(vector<vector<float> > train_file, int k)
{
    this->k = k;
    this->train_file = train_file;
}

//Train
//Although KNN has no model, this function was created for consistency with other algorithms
//Easier for Machine Learning beginners 
vector<vector<float> > KNN::train()
{
    return train_file;
}

//Classify
float KNN::classify(vector<float> instance)
{
    //Calculate Euclidean Distance
    return 1.0;
}

