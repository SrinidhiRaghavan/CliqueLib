/**
main.cpp
Stan Peceny
skp2140
4/1/2017
*/

#include <armadillo>
#include "tests.h"
using namespace arma;

int main()
{
    /*
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

    //test naive bayes functions
    test_naive_bayes();

    //test adaboost
    test_adaboost();
    */

    mat X;
    colvec Y;
    read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    cout << "X:" << X << endl;
    cout << "Y:" << Y << endl;

    return 0;
}
