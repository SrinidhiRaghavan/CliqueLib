/**
naive_bayes.cpp
Stan Peceny
skp2140
4/2/2017
*/

#include "naive_bayes.h"

//Constructor
NB::NB(vector<vector<float> > train_file, int k)
{
    this->k = k;
    this->train_file = train_file;
}


//Train
//Although KNN has no model, this function was created for consistency with other algorithms
//Easier for Machine Learning beginners 
vector<vector<float> > NB::train()
{
    return train_file;
}

//Classify
float NB::classify(vector<float> instance)
{
    return 0.0;
}

