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

// calculate Euclidean Distance
float KNN::euclideanDistance (int num_attributes, vector<float> instance1, vector<float> instance2)
{
    //Calculate Euclidean Distance to each example
    float sum = 0.0;
    for (int j = 0; j < num_attributes; j++)
    {
        sum += pow(instance1[j] - instance2[j], 2);
    }
    return pow(sum, 0.5);
}



//Train
//Although KNN has no model, this function was created for consistency with other algorithms
//Easier for Machine Learning beginners 
vector<vector<float> > KNN::train()
{
    return train_file;
}


bool pairCompare(const pair<float, vector<float>>& firstEl, const std::pair<float, vector<float>>& secondEl) 
{
    return firstEl.first < secondEl.first;
}


//find K neighbors
vector<vector<float> > KNN::findNeighbors(vector<float> instance)
{
    //store the examples with their distances in a vector of tuples
    vector<pair<float, vector<float>>> distances;
    //iterate over all examples
    for (unsigned int i = 0; i < train_file.size(); i++)
    { 
	float sum = euclideanDistance(train_file[i].size() - 1, instance, train_file[i]);
        distances.push_back(make_pair(sum, train_file[i]));
    }
    sort(distances.begin(), distances.end(), pairCompare);

    vector<vector<float> > k_neighbors;
    for (int i = 0; i < this->k; i++)
    {
        k_neighbors.push_back(distances[i].second);  
    } 
    return k_neighbors;   
}

//determine class
float KNN::findClass(vector<vector<float> > k_neighbors)
{
    //which class occurs most times
    map<float, int> classification;
    //class is last attribute for each neighbor
    for (unsigned int i = 0; i < k_neighbors.size(); i++) 
    {
        float neighbor_label = k_neighbors[i][k_neighbors.size()];
        if (classification.find(neighbor_label) != classification.end())        
            classification[neighbor_label] +=1;        
        else   
            classification[neighbor_label] = 1;
    }

    //set to minimum
    int largest_val = numeric_limits<int>::min();
    float largest_class = numeric_limits<float>::min();
    for (unsigned int i = 0; i < k_neighbors.size(); i++)
    {
        if (classification[k_neighbors[i][k_neighbors.size() - 1]] > largest_val)
        { 
            largest_val = classification[k_neighbors[i][k_neighbors.size()]];
            largest_class = k_neighbors[i][k_neighbors.size()];
        }
    }
    return largest_class;
}

//Classify
float KNN::classify(vector<float> instance)
{
    int num_attributes = instance.size();
    if ((unsigned) this->k > train_file.size())
    {
        cerr << "K must be smaller than number of examples";
        return 0.0;
    }
    if (train_file.size() == 0)
    {
        cerr << "Training file has 0 examples";
        return 0.0;
    }
    if ((unsigned int)num_attributes != this->train_file[0].size() - 1)
    {
        cerr << "Wrong number of attributes for the example to be classified";
        return 0.0;
    }

    //find k Nearest Neighbors
    vector<vector<float> > k_neighbors = findNeighbors(instance);

    //select the prevalent class from the neighbors
    return findClass(k_neighbors);
}

