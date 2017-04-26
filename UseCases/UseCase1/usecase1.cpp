//============================================================================
// Name        : test_usecase1.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Use Case 1 function
//============================================================================

#include <armadillo>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>
#include "preprocessing_functions.h"
#include "Stump.h"
#include "AdaBoost.h"

using namespace arma;

double getAccuracy(colvec& a, colvec& b) 
{
    return double(accu(a==b))/size(a, 0);
}

//use case 1
int main()
{
    mat X;
    colvec Y;
    //read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    //read_csv("samples_csv/admits.csv", X, Y, false, ',', '#');
    read_csv("../../samples_csv/face_detection.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    //cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;
    mat Xtrain = X.rows(0, 1599);
    colvec Ytrain = Y.rows(0, 1599);
    mat Xtest = X.rows(1600, 1998);
    colvec Ytest = Y.rows(1600, 1998);
    /*BaggingClassifier<SVM> bgClfr_svm(10, 1200);
    bgClfr_svm.train(Xtrain, Ytrain, 100);
    colvec preds_bg_svm;
    bgClfr_svm.predict(Xtest, preds_bg_svm);
    auto acc_bg_svm = getAccuracy(Ytest, preds_bg_svm);
    cout << "Bg svm acc:" << acc_bg_svm << endl;*/
    AdaBoost clfr;
    clfr.train(Xtrain, Ytrain, 100);
    colvec preds;
    clfr.predict(Xtest, preds);
    auto acc = getAccuracy(Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl;

    return 0;
}
