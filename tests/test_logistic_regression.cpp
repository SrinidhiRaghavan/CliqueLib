//============================================================================
// Name        : test_logistic_regression.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Logistic regression testing
//============================================================================

#include "tests.h"

void test_logistic_regression()
{
    mat X;
    colvec Y;
    read_csv("samples_csv/linear.csv", X, Y, true, ',', '#');

    std::cout << "\nTESTING LOGISTIC REGRESSION" << std::endl;
    Dataset data;
    split_train_test(X, Y, data, 0.8);
    Logistic logistic_clfr(0.01);
    logistic_clfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_log;
    logistic_clfr.predict(data.Xtest, preds_log);

    std::cout << "\nTests Passed" << std::endl;
}

