//============================================================================
// Name        : benchmark_logisticregression.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Main function for benchmarking Logistic Regression
//============================================================================

#include <iostream>
#include <armadillo>
#include <vector>
#include <chrono>
#include "preprocessing_functions.h"
#include "logistic_regression.h"
#include "logistic_regression_std.h"

using namespace arma;

/*
Sample Output:

Time with CliqueLib's Armadillo Implementation: 25744 microseconds.
Time with CliqueLib's Vector Implementation: 63410 microseconds.

*/

int main()
{
    //CliqueLib Armadillo Implementation

    mat X;
    colvec Y;
    read_csv("../../samples_csv/Cancer.csv", X, Y, true, ',', '#');

    //Logistic Regression with learning rate == 1 & number of epochs == 100
    //takes on average  25000 microseconds on a very slow computer
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();    
    Logistic logistic_clfr(0.01);
    logistic_clfr.train(X, Y, 100);
    colvec preds_log;
    logistic_clfr.predict(X, preds_log);

    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time with CliqueLib's Armadillo Implementation: " 
         << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
         << " microseconds." << endl;

    //CliqueLib Vector Implementation

    vector<vector<float> > test_file = read_csv("../../samples_csv/Cancer.csv",
	                                        true, ',', '#');
    vector<vector<float> > train_file = test_file;
    for (auto& instance : test_file)    
        instance[instance.size() - 1] = 0;

    //Logistic Regression with learning rate == 1 & number of epochs == 100
    //takes on average 64000 microseconds on a very slow computer
    start = std::chrono::steady_clock::now();
    LogisticRegressionStd log_vec (train_file, 100, 0.01);
    vector<float> coefficients = log_vec.train();
    log_vec.predict(test_file, coefficients);
    end = std::chrono::steady_clock::now();
    cout << "Time with CliqueLib's Vector Implementation: " 
         << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
         << " microseconds." << endl;

    return 0;
}
