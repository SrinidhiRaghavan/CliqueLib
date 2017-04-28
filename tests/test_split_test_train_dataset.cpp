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

    std::cout << "\nTest Passed" << std::endl;
}
