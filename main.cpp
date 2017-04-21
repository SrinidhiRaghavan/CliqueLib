/**
main.cpp
Stan Peceny
skp2140
4/1/2017
*/

#include "tests.h"

int main()
{
    //reading csv file tests
    test_read_csv();

    //test splitting csv files
    test_split_test_train_dataset();

    //test knn functions
    test_knn();

    //test logistic regression functions
    test_logistic_regression();

    //test naive bayes functions
    test_naive_bayes();

    //test adaboost
    test_adaboost();

    return 0;
}
