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
#include "Dataset.h"
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
    read_csv("../../samples_csv/face_detection.csv", X, Y, true, ',', '#');
    X = X.rows(0, 999);
    Y = Y.rows(0, 999);
    
    Dataset data;
    split_train_test(X, Y, data, 0.6);
    
    AdaBoost clfr;
    clfr.train(data.Xtrain, data.Ytrain, 5);
    colvec preds;
    clfr.predict(data.Xtest, preds);
    auto acc = getAccuracy(data.Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl;

    return 0;
}
