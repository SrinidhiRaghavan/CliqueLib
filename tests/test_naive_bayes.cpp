//============================================================================
// Name        : test_naive_bayes.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Naive Bayes testing
//============================================================================

#include "tests.h"

void test_naive_bayes()
{
    vector<vector<float> > file;

    //TEST NAIVE BAYES 1 SEPARATE_EACH_CLASS
    //machinelearningmastery.com example
    std::cout << "\nTESTING NAIVEBAYES SEPARATE_EACH_CLASS 1" << std::endl;
    vector<vector<float> > example_dataset;
    vector<float> ed1 = {1, 20, 1};
    vector<float> ed2 = {2, 21, 0};
    vector<float> ed3 = {3, 22, 1};
    example_dataset.push_back(ed1);
    example_dataset.push_back(ed2);
    example_dataset.push_back(ed3);
    NaiveBayes nb1(example_dataset);
    map<float, vector<vector<float> > >  separate_class = nb1.separate_each_class();
    cout << endl;
    for (auto const &el : separate_class)
    {
        for (unsigned int i = 0; i < el.second.size(); i++)
            for (unsigned int j = 0; j < el.second[i].size(); j++)
                cout << el.second[i][j] << " ";
    }
    cout << endl;
    cout << "Expected: 2 21 0 1 20 1 3 22 1" << endl;
    cout << "\nNaiveBayes Test 1 passed\n";

    //TEST NAIVE BAYES 2 MEAN_AVERAGE AND STANDARD DEVIATION
    //machinelearningmastery.com example
    std::cout << "\nTESTING NAIVEBAYES MEAN_AVERAGE AND STANDARD DEVIATION 2" << std::endl;
    vector<float> mean_std = {1, 2, 3, 4, 5};
    assert(nb1.mean_average(mean_std) == 3.0);
    cout << "\nPredicted: " << nb1.standard_deviation(mean_std) <<
            " Real: " << 1.581139 << endl;
    cout << "\nNaiveBayes Test 2 passed\n";


    //TEST NAIVE BAYES 3 SUMMARY
    //machinelearningmastery.com example
    std::cout << "\nTESTING NAIVEBAYES SUMMARY 3" << std::endl;
    vector<vector<float> > example_dataset2;
    vector<float> ed21 = {1, 20, 0};
    vector<float> ed22 = {2, 21, 1};
    vector<float> ed23 = {3, 22, 0};
    example_dataset2.push_back(ed21);
    example_dataset2.push_back(ed22);
    example_dataset2.push_back(ed23);
    NaiveBayes nb2(example_dataset2);
    vector<pair<float, float> > summaries = nb2.summary(example_dataset2);
    cout << endl;
    for (auto const &pr : summaries)
    {
        cout << pr.first << " " << pr.second << " ";
    }
    cout << endl;
    cout << "Expected: 2.0 1.0 21.0 1.0" << endl;
    cout << "\nNaiveBayes Test 3 passed\n";

    //TEST NAIVE BAYES 4 GAUSSIAN PROBABILITY
    //machinelearningmastery.com example
    std::cout << "\nTESTING NAIVEBAYES GAUSSIAN PROBABILITY 4" << std::endl;
    float attr_val = 71.5;
    float stdv = 6.2;
    float mean_avg = 73;
    cout << endl;
    cout << "Calculated ~ " << nb2.probability(mean_avg, stdv, attr_val) << endl;
    cout << "Expected ~ " << 0.0624897 << endl;
    cout << "\nNaiveBayes Test 4 passed\n";
}

