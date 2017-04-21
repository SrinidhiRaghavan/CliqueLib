/**
test_naive_bayes.cpp
Stan Peceny
skp2140
4/20/2017
*/

#include "tests.h"

void test_naive_bayes()
{
    vector<vector<float> > file;

    //TEST NAIVE BAYES 1 SEPARATE_EACH_CLASS
    //machinelearningmastery.com example
    vector<vector<float> > example_dataset;
    vector<float> ed1 = {1, 20, 1};
    vector<float> ed2 = {2, 21, 0};
    vector<float> ed3 = {3, 22, 1};
    example_dataset.push_back(ed1);
    example_dataset.push_back(ed2);
    example_dataset.push_back(ed3);
    NB nb1(example_dataset);
    map<float, vector<vector<float> > >  separate_class = nb1.separate_each_class();
    cout << "\nNB Test 1 passed\n";
}

