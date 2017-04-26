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
    //TEST READING CSV FILES
    vector<vector<float> > file;
    vector<vector<float> > train_file;
    vector<vector<float> > test_file;

    //Test 1
    std::cout << "\nTESTING SPLITTING CSV FILE 1" << std::endl;
    file = read_csv("./samples_csv/test_file_1_title_true.csv", true);
    split_test_train(file, 0.6, train_file, test_file);    

    //Test 2
    std::cout << "\nTESTING SPLITTING CSV FILE 2" << std::endl;
    file = read_csv("./samples_csv/test_file_2_title_false.csv", false);
    split_test_train(file, 0.5, train_file, test_file); 

    //Test 3
    std::cout << "\nTESTING SPLITTING CSV FILE 3" << std::endl;
    file = read_csv("./samples_csv/test_file_3_title_default.csv");
    split_test_train(file, 0.75, train_file, test_file); 

    //Test 4
    std::cout << "\nTESTING SPLITTING CSV FILE 4" << std::endl;
    file = read_csv("./samples_csv/test_file_4_separate_ex_space.csv", false, ' ');
    split_test_train(file, 1, train_file, test_file); 

    //Test 5
    std::cout << "\nTESTING SPLITTING CSV FILE 5" << std::endl;
    file = read_csv("./samples_csv/test_file_5_separate_ex_semicolon.csv", false, ';');
    split_test_train(file, 0, train_file, test_file); 

    //Test 6
    std::cout << "\nTESTING SPLITTING CSV FILE 6" << std::endl;
    file = read_csv("./samples_csv/test_file_6_separate_ex_default.csv", false);
    split_test_train(file, 0.9, train_file, test_file); 

    //Test 7
    std::cout << "\nTESTING SPLITTING CSV FILE 7" << std::endl;
    file = read_csv("./samples_csv/test_file_7_comment_star.csv", true,',', '*');
    split_test_train(file, 0.1, train_file, test_file); 

    //Test 8
    std::cout << "\nTESTING SPLITTING CSV FILE 8" << std::endl;
    file = read_csv("./samples_csv/test_file_8_comment_default.csv");
    split_test_train(file, 0.99, train_file, test_file); 

    //Test 9
    std::cout << "\nTESTING SPLITTING CSV FILE 9" << std::endl;
    file = read_csv("./samples_csv/test_file_9_origin_wine.csv", true);    
    split_test_train(file, 0.01, train_file, test_file); 
}
