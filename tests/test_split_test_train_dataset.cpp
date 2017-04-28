//============================================================================
// Name        : test_split_test_train_dataset.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib splitting training and testing dataset testing
//============================================================================

#include "tests.h"

void test_split_test_train_dataset()
{
    //Test 1
    std::cout << "\nTESTING SPLITTING CSV FILE" << std::endl;
    mat X;
    colvec Y;
    read_csv("samples_csv/face_detection.csv", X, Y, true, ',', '#');
    X = X.rows(0, 999);
    Y = Y.rows(0, 999);
    
    Dataset data;
    split_train_test(X, Y, data, 0.6);

    cout << endl;
    cout << "size Xtrain:" << arma::size(data.Xtrain) << " = 600X576" << endl;
    cout << "size Ytrain:" << arma::size(data.Ytrain) << " = 600X1" << endl;
    cout << "size Xtest:" << arma::size(data.Xtest) << " = 400X576" << endl;
    cout << "size Ytest:" << arma::size(data.Ytest) << " = 400X1"<< endl;

    std::cout << "\nTest Passed" << std::endl;
}
