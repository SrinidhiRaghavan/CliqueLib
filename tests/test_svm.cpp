//============================================================================
// Name        : test_svm.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib SVM testing
//============================================================================

#include "tests.h"

void test_svm()
{
    mat X;
    colvec Y;
    read_csv("samples_csv/linear.csv", X, Y, true, ',', '#');

    std::cout << "\nTESTING SVM" << std::endl;
    Dataset data;
    split_train_test(X, Y, data, 0.8);
    SVM svm_clfr(0.1);
    svm_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_svm;
    svm_clfr.predict(data.Xtest, preds_svm);
    std::cout << "\nTests Passed" << std::endl;
}
