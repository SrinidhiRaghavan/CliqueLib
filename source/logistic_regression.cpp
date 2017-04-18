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


//Train
vector<vector<float> > LogisticRegression::train()
{
    return train_file;
}

//Classify
float LogisticRegression::classify(vector<float> instance)
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
    if ((unsigned int)num_attributes != this->train_file[0].size() - 1)
    {
        cerr << "Wrong number of attributes for the example to be classified";
        return 0;
    }

    vector<float> distances;
    //iterate over all examples
    for (unsigned int i = 0; i < train_file.size(); i++)
    { 
        //Calculate Euclidean Distance to each example
        float sum = 0.0;
        for (unsigned int j = 0; j < train_file[i].size() - 1; j++)
        {
            sum += pow(instance[j] - train_file[i][j], 2);
        }
        distances.push_back(pow(sum, 0.5));
    }
    //Find k nearest neighbors
    vector<float> ks;
    vector<int> ks_classes;
    vector<float> copy_distances = distances;
    sort(distances.begin(), distances.end());
    //k smallest distances
    for (int i = 0; i < this->k; i++)
        ks.push_back(distances[i]);
    //actual classes of the smallest distances
    for (int i = 0; i < this->k; i++)
    {
        for (unsigned int j = 0; j < copy_distances.size(); j++)
        {
            if (ks[i] == copy_distances[j]) 
            {
                //last column is the label
                ks_classes.push_back(train_file[j][train_file[j].size() - 1]);
            }
        }  
    }
    //which class occurs most times
    map<float, int> classification;

    for (unsigned int i = 0; i < ks_classes.size(); i++)    
        classification[ks_classes[i]] = 0;
    
    for (unsigned int i = 0; i < ks_classes.size(); i++)    
        classification[ks_classes[i]] +=1;
    
    //set to minimum
    int largest_val = numeric_limits<int>::min();
    float largest_class = numeric_limits<float>::min();
    for (unsigned int i = 0; i < ks_classes.size(); i++)
    {
        if (classification[ks_classes[i]] > largest_val)
        { 
            largest_val = classification[ks_classes[i]];
            largest_class = ks_classes[i];
        }
    }
	
    return largest_class;
}

