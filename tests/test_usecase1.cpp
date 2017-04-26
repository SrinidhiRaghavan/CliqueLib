//============================================================================
// Name        : test_usecase1.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Use Case 1 testing
//============================================================================

#include "tests.h"

void test_usecase1()
{
    mat X;
    colvec Y;
    //read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    //read_csv("samples_csv/admits.csv", X, Y, false, ',', '#');
    read_csv("samples_csv/Cancer.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    //cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;

    mat Xtrain = X.rows(0, 499);
    colvec Ytrain = Y.rows(0, 499);
    mat Xtest = X.rows(500, 567);
    colvec Ytest = Y.rows(500, 567);

    AdaBoost clfr;
    clfr.train(Xtrain, Ytrain, 100);
    colvec preds;
    clfr.predict(Xtest, preds);

    auto acc = getAccuracy(Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl; 
}

