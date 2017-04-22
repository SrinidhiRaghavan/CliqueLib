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

//Summary 
vector<pair<float, float> > NB::summary(vector<vector<float> > class_dataset)
{
    vector<pair<float, float> > summarize_attributes;
    //get all attributes into a single vector
    vector<float> combine_attributes;
    for (auto& examp : class_dataset)    
        for (unsigned int j = 0; j < examp.size() - 1; j++)        
            combine_attributes.push_back(examp[j]);

    unsigned int count = 0;
    while (count < class_dataset[0].size() - 1)
    {
        vector<float> segmented_attributes;
        for (unsigned int i = count; i < combine_attributes.size(); i += class_dataset[0].size() - 1)
            segmented_attributes.push_back(combine_attributes[i]);
     
        summarize_attributes.push_back(make_pair(
                                       mean_average(segmented_attributes),
                                       standard_deviation(segmented_attributes)
                                       ));
        count++;
    }
    return summarize_attributes;
}

//separate the examples by class
map<float, vector<vector<float> > > NB::separate_each_class()
{
    map<float, vector<vector<float> > > separate_classes;
    for (unsigned int i = 0; i < train_file.size(); i++)
    {
        vector<float> vec_attributes = train_file[i];
        separate_classes[vec_attributes[vec_attributes.size() - 1]].push_back(vec_attributes); 
    }
    return separate_classes;
}


//Train
map<float, vector<pair<float, float> > > NB::train()
{
    map<float, vector<vector<float> > > separated_classes = separate_each_class();
    map<float, vector<pair<float, float> > > attribute_summaries;
    map<float, vector<vector<float> > >::iterator iter = separated_classes.begin();
    while (iter != separated_classes.end())
        attribute_summaries[iter->first] = summary(iter->second);
    return attribute_summaries;
}

//Classify
float NB::classify(vector<float> instance)
{
    return 0.0;
}

