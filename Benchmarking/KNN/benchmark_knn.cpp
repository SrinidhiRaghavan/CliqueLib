//============================================================================
// Name        : benchmark_knn.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Main function for benchmarking KNN
//============================================================================

#include <iostream>
#include <armadillo>
#include <vector>
#include <chrono>
#include "preprocessing_functions.h"
#include "KNN.h"
#include "knnstd.h"

using namespace arma;

/*
Sample Output:

Time with CliqueLib's Armadillo Implementation: 48177 microseconds.
Time with CliqueLib's Vector Implementation: 358849 microseconds.

*/

int main()
{
    //CliqueLib Armadillo Implementation

    mat X;
    colvec Y;
    read_csv("../../samples_csv/Cancer.csv", X, Y, true, ',', '#');    
    
    //KNN with k=23 takes approximately 52000 microseconds on a very slow computer
    std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();
    KNN knn_clfr(23);
    knn_clfr.train(X, Y, 100);
    colvec preds_knn;
    knn_clfr.predict(X, preds_knn);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    cout << "Time with CliqueLib's Armadillo Implementation: " 
         << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
         << " microseconds." << endl;

    //CliqueLib Vector Implementation

    vector<vector<float> > test_file = read_csv("../../samples_csv/Cancer.csv",
	                                        true, ',', '#');
    vector<vector<float> > train_file = test_file;
    for (auto& instance : test_file)    
        instance.pop_back();

    //KNN with k=23 takes approximately 360000 microseconds on a very slow computer
    start = std::chrono::steady_clock::now();    
    KNNStd knn_vec (train_file, 23);
    knn_vec.train();
    knn_vec.predict(test_file);
    end = std::chrono::steady_clock::now();
    cout << "Time with CliqueLib's Vector Implementation: " 
         << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count()
         << " microseconds." << endl;

    return 0;
}
