//============================================================================
// Name        : main.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Main function
//============================================================================

#include "tests.h"

using namespace arma;

double getAccuracy(colvec& a, colvec& b) {
    return double(accu(a==b))/size(a, 0);
}

int main()
{
    //reading csv file tests
    test_read_csv();

    //test splitting csv files
    test_split_test_train_dataset();

    //test knn functions
    test_knn();

    //test knn functions
    test_knn_std();

    //test logistic regression functions
    test_logistic_regression();

    //test logistic regression functions
    test_logistic_regression_std();

    //test adaboost
    test_adaboost();    

    return 0;
}
