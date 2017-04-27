//============================================================================
// Name        : benchmark_knn.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Main function for benchmarking KNN
//============================================================================

#include <iostream>
#include <memory>
#include <armadillo>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>
#include <chrono>
#include "preprocessing_functions.h"
#include "Dataset.h"
#include "KNN.h"
#include "knnstd.h"

using namespace arma;

double getAccuracy(colvec& a, colvec& b) {
    return double(accu(a==b))/size(a, 0);
}

int main()
{
    //CliqueLib Armadillo Implementation

    mat X;
    colvec Y;
    read_csv("../../samples_csv/Cancer.csv", X, Y, true, ',', '#');    
    
    //KNN with k=23
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

    return 0;
}
