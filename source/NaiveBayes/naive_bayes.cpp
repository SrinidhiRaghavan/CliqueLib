/**
naive_bayes.cpp
Stan Peceny
skp2140
4/20/2017
*/

#include "naive_bayes.h"

//Constructor
NaiveBayes::NaiveBayes(vector<vector<float> > train_file)
{
    this->train_file = train_file;
}

//Mean
float NaiveBayes::mean_average(vector<float> attributes)
{
    float sum = 0;
    for (auto& attr : attributes)
        sum += attr;
    return sum / attributes.size();
}

//Standard deviation
float NaiveBayes::standard_deviation(vector<float> attributes)
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
vector<pair<float, float> > NaiveBayes::summary(vector<vector<float> > class_dataset)
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

//Gaussian Probability Density function
float NaiveBayes::probability(float mean_average, float standard_deviation, float attribute_value)
{
    float expon = exp(-1 * (pow(attribute_value - mean_average, 2.0) / 
                      (2 * pow(standard_deviation, 2.0))));
    float gaussian_prob = expon * 1 / (sqrt(2 * M_PI) * standard_deviation);
    return gaussian_prob;
}


//separate the examples by class
map<float, vector<vector<float> > > NaiveBayes::separate_each_class()
{
    map<float, vector<vector<float> > > separate_classes;
    for (unsigned int i = 0; i < train_file.size(); i++)
    {
        vector<float> vec_attributes = train_file[i];
        separate_classes[vec_attributes[vec_attributes.size() - 1]].push_back(vec_attributes); 
    }
    return separate_classes;
}

/*
//Probability of instance being member of class
map<float, float> probabilities_class(map<float, vector<pair<float, float> > > summary, vector<float> instance)
{
    map<float, float> gaussian_probabilities;
    for (auto& smr : summary)
    {
        gaussian_probabilities[smr->first] = 1.0;
        for (unsigned int i = 0; i < smr->second.size(); i++)
        {
            
        } 
    }   
}*/

//Train
map<float, vector<pair<float, float> > > NaiveBayes::train()
{
    map<float, vector<vector<float> > > separated_classes = separate_each_class();
    map<float, vector<pair<float, float> > > attribute_summaries;
    map<float, vector<vector<float> > >::iterator iter = separated_classes.begin();
    while (iter != separated_classes.end())
        attribute_summaries[iter->first] = summary(iter->second);
    return attribute_summaries;
}

//Classify
float NaiveBayes::classify(vector<pair<float, float> > summary, vector<float> instance)
{
    // gaussian_probability = probability(, , );
    return 0.0;
}

