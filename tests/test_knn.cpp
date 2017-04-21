/**
test_knn.cpp
Stan Peceny
skp2140
4/2/2017
*/

#include "tests.h"

void test_knn()
{
    //TEST KNN OF CSV FILES
    vector<vector<float> > file;
    vector<vector<float> > train_file;
    vector<vector<float> > test_file;

    //Test 1
    std::cout << "\nTESTING KNN CSV FILE 1" << std::endl;
    file = read_csv("./samples_csv/test_file_1_title_true.csv", true);
    split_test_train(file, 0.6, train_file, test_file);  

    KNN knn1 (train_file, 1);
    assert(knn1.getK() == 1);
    assert(knn1.train() == train_file);
    vector<float> class_ex1 = {3, 9};
    knn1.classify(class_ex1);
    cout << "\nKNN Test 1 passed\n";

    //Test 2
    std::cout << "\nTESTING KNN CSV FILE 2" << std::endl;
    file = read_csv("./samples_csv/test_file_2_title_false.csv", false);
    split_test_train(file, 0.5, train_file, test_file); 

    KNN knn2 (train_file, 2);
    assert(knn2.getK() == 2);
    assert(knn2.train() == train_file);
    vector<float> class_ex2 = {3, 7.4};
    knn2.classify(class_ex2);
    cout << "\nKNN Test 2 passed\n";

    //Test 3
    std::cout << "\nTESTING KNN CSV FILE 3" << std::endl;
    file = read_csv("./samples_csv/test_file_3_title_default.csv");
    split_test_train(file, 0.75, train_file, test_file); 

    KNN knn3 (train_file, 2);
    assert(knn3.getK() == 2);
    assert(knn3.train() == train_file);
    vector<float> class_ex3 = {3, 7.4, 2};
    knn3.classify(class_ex3);
    cout << "\nKNN Test 3 passed\n";

    //Test 4
    std::cout << "\nTESTING KNN CSV FILE 4" << std::endl;
    file = read_csv("./samples_csv/test_file_4_separate_ex_space.csv", false, ' ');
    split_test_train(file, 1, train_file, test_file); 

    KNN knn4 (train_file, 2);
    assert(knn4.getK() == 2);
    assert(knn4.train() == train_file);
    vector<float> class_ex4 = {3, 7.4};
    knn4.classify(class_ex4);
    cout << "\nKNN Test 4 passed\n";

    //Test 5
    std::cout << "\nTESTING KNN CSV FILE 5" << std::endl;
    file = read_csv("./samples_csv/test_file_5_separate_ex_semicolon.csv", false, ';');
    split_test_train(file, 0, train_file, test_file); 

    KNN knn5 (train_file, 2);
    assert(knn5.getK() == 2);
    assert(knn5.train() == train_file);
    vector<float> class_ex5 = {3, 7.4};
    knn5.classify(class_ex5);
    cout << "\nKNN Test 5 passed\n";

    //Test 6
    std::cout << "\nTESTING KNN CSV FILE 6" << std::endl;
    file = read_csv("./samples_csv/test_file_6_separate_ex_default.csv", false);
    split_test_train(file, 0.9, train_file, test_file); 

    KNN knn6 (train_file, 2);
    assert(knn6.getK() == 2);
    assert(knn6.train() == train_file);
    vector<float> class_ex6 = {3, 7.4, 2, 3};
    knn6.classify(class_ex6);
    cout << "\nKNN Test 6 passed\n";

    //Test 7
    std::cout << "\nTESTING KNN CSV FILE 7" << std::endl;
    file = read_csv("./samples_csv/test_file_7_comment_star.csv", true,',', '*');
    split_test_train(file, 0.1, train_file, test_file); 

    KNN knn7 (train_file, 1);
    assert(knn7.getK() == 1);
    assert(knn7.train() == train_file);
    vector<float> class_ex7 = {3, 7.4, 8, 4};
    knn7.classify(class_ex7);
    cout << "\nKNN Test 7 passed\n";

    //Test 8
    std::cout << "\nTESTING KNN CSV FILE 8" << std::endl;
    file = read_csv("./samples_csv/test_file_8_comment_default.csv");
    split_test_train(file, 0.99, train_file, test_file); 

    KNN knn8 (train_file, 1);
    assert(knn8.getK() == 1);
    assert(knn8.train() == train_file);
    vector<float> class_ex8 = {3, 7.4, 2, 3};
    knn8.classify(class_ex8);
    cout << "\nKNN Test 8 passed\n";

    //Test 9
    std::cout << "\nTESTING KNN CSV FILE 9" << std::endl;
    file = read_csv("./samples_csv/test_file_9_origin_wine.csv", true);    
    split_test_train(file, 0.01, train_file, test_file); 

    KNN knn9 (train_file, 1);
    assert(knn9.getK() == 1);
    assert(knn9.train() == train_file);
    vector<float> class_ex9 = {3, 7.4, 3, 4.4};
    knn9.classify(class_ex9);
    cout << "\nKNN Test 9 passed\n";

    //Test 10
    std::cout << "\nTESTING KNN CSV FILE 10" << std::endl;
    file = read_csv("./samples_csv/test_file_2_title_false.csv", false);  
    split_test_train(file, 0.01, train_file, test_file);  

    KNN knn10 (train_file, 2);
    assert(knn10.getK() == 2);
    assert(knn10.train() == train_file);
    vector<float> class_ex10 = {3, 7.4};
    knn10.classify(class_ex10);
    cout << "\nKNN Test 10 passed\n";

    //Test 11
    std::cout << "\nTESTING KNN EUCLIDEAN DISTANCE 11" << std::endl;
    KNN knn11 (train_file, 2);
    vector<float> examp1 = {2, 2, 2, 2, 1};
    vector<float> examp2 = {4, 4, 4, 4, 0};
    assert(knn11.euclideanDistance(4, examp1, examp2) == 4.0);
    cout << "\nKNN Test 11 passed\n";

    //Test 12
    //machinelearningmastery.com
    std::cout << "\nTESTING KNN FIND CLASS 12" << std::endl;
    KNN knn12 (train_file, 3);
    vector<vector<float> > neighb;
    vector<float> subn1 = {1,1,1,0};
    vector<float> subn2 = {2,2,2,0};
    vector<float> subn3 = {3,3,3,1};
    neighb.push_back(subn1);
    neighb.push_back(subn2);
    neighb.push_back(subn3);
    assert(knn12.findClass(neighb) == 0.0);
    cout << "\nKNN Test 12 passed\n";

}

