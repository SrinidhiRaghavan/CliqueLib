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
        float sum = 0;
        for (int j = 0; j < train_file[i].size(); j++)
        {
            sum += pow(instance[i] - train_file[i][j], 2);
        }
        distances.push_back(pow(sum, 0.5));
    }
    //Find k nearest neighbors
    vector<float> ks;
    vector<int> ks_classes;
    vector<float> copy_distances = distances;
    sort(distances.begin(), distances.end());
    for (int i = 0; i < this->k; i++)
        ks.push_back(distances[i]);
    for (int i = 0; i < this->k; i++)
    {
        for (int j = 0; j < copy_distances.size(); j++)
        {
            if (ks[i] == copy_distances[j]) 
                ks_classes.push_back(j);
        }  
    }
    //which class occurs most times
    /*map<float, int> classification;
    for (int i = 0; i < ks_classes.size(); i++)
    {
        classification[train_file[ks_classes[i]][train_file[ks_classes[i]].size() - 1]] = 0;
    }
    for (int i = 0; i < ks_classes.size(); i++)
    {
        classification[train_file[ks_classes[i]][train_file[ks_classes[i]].size() - 1]] +=1;
    }

    int largest_val = numeric_limits<int>::min();
    float largest_class = numeric_limits<float>::min();
    for( const auto& classification_pair : classification )
    {
        for( const auto& classification_pair : classification_pair.second )
        {
            if (classification_pair.)
            std::cout << "     " << sc_pair.first << '{' << sc_pair.second.a << ',' 
                      << sc_pair.second.b << ',' << sc_pair.second.d << "}\n" ;    
        }
    }*/
	
    return 0;
}

