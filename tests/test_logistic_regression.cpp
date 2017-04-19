/**
test_logistic_regression.cpp
Stan Peceny
skp2140
4/18/2017
*/

#include "tests.h"

void test_logistic_regression()
{
    //TEST KNN OF CSV FILES
    vector<vector<float> > file;
    vector<vector<float> > train_file;
    vector<vector<float> > test_file;

    //Test 1
    std::cout << "\nTESTING Sigmoid Function" << std::endl;
    file = read_csv("./samples_csv/test_file_1_title_true.csv", true);

    LogisticRegression lr1 (file, 1);
    cout << lr1.sigmoid_function(1) << " ~ " << 0.731 << endl;
    cout << lr1.sigmoid_function(0) << " ~ " << 0.5 << endl;
    cout << lr1.sigmoid_function(2) << " ~ " << 0.881 << endl;

    //test the classify function with predetermined coefficients
    std::cout << "\nTESTING CLASSIFY() OF LOGISTIC REGRESSION WITH CSV FILE 1" << std::endl;
    file = read_csv("./samples_csv/test_file_10_logistic.csv", ',');
    LogisticRegression lr2 (file, 1); 
    //coefficients - http://machinelearningmastery.com/
    vector<float> coefficients = {-0.406605464, 0.852573316, -1.104746259};
    cout << "predicted: " << lr2.classify(file[0], coefficients) 
         << " real: " << file[0][file[0].size() - 1]<< endl;
    cout << "predicted: " << lr2.classify(file[1], coefficients) 
         << " real: " << file[1][file[1].size() - 1]<< endl;
    cout << "predicted: " << lr2.classify(file[2], coefficients) 
         << " real: " << file[2][file[2].size() - 1]<< endl;
    
/*
    //Test 2
    std::cout << "\nTESTING KNN CSV FILE 2" << std::endl;
    file = read_csv("./samples_csv/test_file_2_title_false.csv", false);
    split_test_train(file, 0.5, train_file, test_file); 

    KNN knn2 (train_file, 2);
    assert(knn2.getK() == 2);
    assert(knn2.train() == train_file);
    vector<float> class_ex2 = {3, 7.4};
    knn2.classify(class_ex2);

    //Test 3
    std::cout << "\nTESTING KNN CSV FILE 3" << std::endl;
    file = read_csv("./samples_csv/test_file_3_title_default.csv");
    split_test_train(file, 0.75, train_file, test_file); 

    KNN knn3 (train_file, 2);
    assert(knn3.getK() == 2);
    assert(knn3.train() == train_file);
    vector<float> class_ex3 = {3, 7.4, 2};
    knn3.classify(class_ex3);

    //Test 4
    std::cout << "\nTESTING KNN CSV FILE 4" << std::endl;
    file = read_csv("./samples_csv/test_file_4_separate_ex_space.csv", false, ' ');
    split_test_train(file, 1, train_file, test_file); 

    KNN knn4 (train_file, 2);
    assert(knn4.getK() == 2);
    assert(knn4.train() == train_file);
    vector<float> class_ex4 = {3, 7.4};
    knn4.classify(class_ex4);

    //Test 5
    std::cout << "\nTESTING KNN CSV FILE 5" << std::endl;
    file = read_csv("./samples_csv/test_file_5_separate_ex_semicolon.csv", false, ';');
    split_test_train(file, 0, train_file, test_file); 

    KNN knn5 (train_file, 2);
    assert(knn5.getK() == 2);
    assert(knn5.train() == train_file);
    vector<float> class_ex5 = {3, 7.4};
    knn5.classify(class_ex5);

    //Test 6
    std::cout << "\nTESTING KNN CSV FILE 6" << std::endl;
    file = read_csv("./samples_csv/test_file_6_separate_ex_default.csv", false);
    split_test_train(file, 0.9, train_file, test_file); 

    KNN knn6 (train_file, 2);
    assert(knn6.getK() == 2);
    assert(knn6.train() == train_file);
    vector<float> class_ex6 = {3, 7.4, 2, 3};
    knn6.classify(class_ex6);

    //Test 7
    std::cout << "\nTESTING KNN CSV FILE 7" << std::endl;
    file = read_csv("./samples_csv/test_file_7_comment_star.csv", true,',', '*');
    split_test_train(file, 0.1, train_file, test_file); 

    KNN knn7 (train_file, 1);
    assert(knn7.getK() == 1);
    assert(knn7.train() == train_file);
    vector<float> class_ex7 = {3, 7.4, 8, 4};
    knn7.classify(class_ex7);

    //Test 8
    std::cout << "\nTESTING KNN CSV FILE 8" << std::endl;
    file = read_csv("./samples_csv/test_file_8_comment_default.csv");
    split_test_train(file, 0.99, train_file, test_file); 

    KNN knn8 (train_file, 1);
    assert(knn8.getK() == 1);
    assert(knn8.train() == train_file);
    vector<float> class_ex8 = {3, 7.4, 2, 3};
    knn8.classify(class_ex8);

    //Test 9
    std::cout << "\nTESTING KNN CSV FILE 9" << std::endl;
    file = read_csv("./samples_csv/test_file_9_origin_wine.csv", true);    
    split_test_train(file, 0.01, train_file, test_file); 

    KNN knn9 (train_file, 1);
    assert(knn9.getK() == 1);
    assert(knn9.train() == train_file);
    vector<float> class_ex9 = {3, 7.4, 3, 4.4};
    knn9.classify(class_ex9);

    //Test 10
    std::cout << "\nTESTING KNN CSV FILE 10" << std::endl;
    file = read_csv("./samples_csv/test_file_2_title_false.csv", false);  
    split_test_train(file, 0.01, train_file, test_file);  

    KNN knn10 (train_file, 2);
    assert(knn10.getK() == 2);
    assert(knn10.train() == train_file);
    vector<float> class_ex10 = {3, 7.4};
    knn10.classify(class_ex10);
*/
}

