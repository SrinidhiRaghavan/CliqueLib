/**
naive_bayes.cpp
Stan Peceny
skp2140
4/20/2017
*/

#include "naive_bayes.h"

//Constructor
NB::NB(vector<vector<float> > train_file)
{
    this->train_file = train_file;
}

//Mean
float NB::mean_average(vector<float> attributes)
{
    float sum = 0;
    for (auto& attr : attributes)
        sum += attr;
    return sum / attributes.size();
}

//Standard deviation
float NB::standard_deviation(vector<float> attributes)
{
    float mean_avg = mean_average(attributes);
    vector<float> differences(attributes.size());
    transform(attributes.begin(), attributes.end(),
              differences.begin(), [mean_avg](float attr) {return attr - mean_avg; } );
    float square_sum = inner_product(differences.begin(), differences.end(),
                                   differences.begin(), 0.0);
    return sqrt(square_sum / (attributes.size() - 1));
}



//separate the examples by class
map<float, vector<vector<float> > > NB::separate_each_class()
{
    map<float, vector<vector<float> > > separate_classes;
    for (unsigned int i = 0; i < train_file.size(); i++)
    {
        vector<float> vec_attributes = train_file[i];
        //if (separate_classes.find(vec_attributes[vec_attributes.size() - 1]) == separate_classes.end())        
            //separate_classes[vec_attributes[vec_attributes.size() - 1]] = ;
        //else
        separate_classes[vec_attributes[vec_attributes.size() - 1]].push_back(vec_attributes); 
    }
    return separate_classes;
}


//Train
vector<vector<float> > NB::train()
{
    return train_file;
}

//Classify
float NB::classify(vector<float> instance)
{
    return 0.0;
}

