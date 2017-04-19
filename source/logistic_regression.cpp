/**
logistic_regression.cpp
Stan Peceny
skp2140
4/18/2017
*/

#include "logistic_regression.h"

//Constructor
LogisticRegression::LogisticRegression(vector<vector<float> > train_file, int k)
{
    this->k = k;
    this->train_file = train_file;
}

//calculate sigmoid function
float LogisticRegression::sigmoid_function(float z)
{
    float e = 2.718282;
    return 1.0 / (1.0 + pow(e, -z));
}


//Train - Returns a set of coefficients
vector<vector<float> > LogisticRegression::train()
{
    return train_file;
}

//Classify
float LogisticRegression::classify(vector<float> instance, vector<float> coefficients)
{
    //Last column contains the labels
    int num_attributes = instance.size() - 1;
    if ((unsigned int)num_attributes != this->train_file[0].size() - 1)
    {
        cerr << "Wrong number of attributes for the example to be classified";
        return 0;
    }

    //iterate over all attributes, the last column is the label
    float z = coefficients[0];
    for (unsigned int i = 0; i < instance.size() - 1; i++)
    {
        z += coefficients[i + 1] * instance[i];
    }	
    return sigmoid_function(z);
}

