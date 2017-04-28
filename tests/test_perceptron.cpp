//============================================================================
// Name        : test_perceptron.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Perceptron testing
//============================================================================

#include "tests.h"

void test_perceptron()
{
    mat X;
    colvec Y;
    read_csv("samples_csv/linear.csv", X, Y, true, ',', '#');

    std::cout << "\nTESTING PERCEPTRON" << std::endl;
    Dataset data;
    split_train_test(X, Y, data, 0.8);
    Perceptron pcptr_clfr;
    pcptr_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_pcptr;
    pcptr_clfr.predict(data.Xtest, preds_pcptr);
    std::cout << "\nTests Passed" << std::endl;
}
