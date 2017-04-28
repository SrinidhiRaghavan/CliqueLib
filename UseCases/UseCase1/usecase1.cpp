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
    return (100 * (double(accu(a==b))/size(a, 0)));
}

//use case 1
int main()
{
    cout << "" << endl;
    cout << "Initiating Face Detection using AdaBoost..." << endl;
    cout << "" << endl;
    cout << "We draw 1000 samples from face_detection.csv which has" << endl;
    cout << "images of faces and non-faces of size 24x24 flattened" << endl;
    cout << "to give a feature vector with 576 features" << endl;
    cout << "" << endl;
    
    mat X;
    colvec Y;
    read_csv("../../samples_csv/face_detection.csv", X, Y, true, ',', '#');
    X = X.rows(0, 999);
    Y = Y.rows(0, 999);
    
    Dataset data;
    split_train_test(X, Y, data, 0.6);
    
    AdaBoost clfr;
    cout << "Using Train-Test data split of 60-40%" << endl;
    cout << "Training AdaBoost with 5 decision Stumps..." << endl;
    clfr.train(data.Xtrain, data.Ytrain, 5);
    
    colvec trainPreds;
    clfr.predict(data.Xtrain, trainPreds);
    auto acc = getAccuracy(data.Ytrain, trainPreds);
    cout << "Training accuracy: " << acc << "%" << endl;
    
    colvec testPreds;
    clfr.predict(data.Xtest, testPreds);
    acc = getAccuracy(data.Ytest, testPreds);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    return 0;
}
