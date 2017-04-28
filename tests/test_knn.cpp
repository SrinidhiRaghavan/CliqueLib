//============================================================================
// Name        : test_knn.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib KNN testing
//============================================================================

#include "tests.h"

void test_knn()
{
    mat X;
    colvec Y;
    read_csv("samples_csv/linear.csv", X, Y, true, ',', '#');

    std::cout << "\nTESTING KNN" << std::endl;
    Dataset data;
    split_train_test(X, Y, data, 0.8);
    KNN knn_clfr;
    knn_clfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_knn;
    knn_clfr.predict(data.Xtest, preds_knn);
    std::cout << "\nTests Passed" << std::endl;
}

