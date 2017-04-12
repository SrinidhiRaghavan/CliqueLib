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
    int num_attributes = instance.size();
    if (this->k > num_attributes)
    {
        cerr << "K must be smaller than number of examples";
        return 0.0;
    }
    if (train_file.size() == 0)
    {
        cerr << "Training file has 0 examples";
        return 0;
    }
    if (num_attributes != this->train_file[0].size() - 1)
    {
        cerr << "Wrong number of attributes for the example to be classified";
        return 0;
    }
    float dist_formula = 0;
    vector<float> distances;
    //iterate over all examples
    for (int i = 0; i < train_file.size(); i++)
    {
        //Calculate Euclidean Distance to each example
        for (int j = 0; j < train_file[i].size(); j++)
        {
            cout << train_file[i][j];
        }
    }    

    return 1.0;
}

