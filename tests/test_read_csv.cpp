/**
test_read_csv.cpp
Stan Peceny
skp2140
4/1/2017
*/

#include "tests.h"

void test_read_csv()
{
    //TEST READING CSV FILES

    //Test 1
    std::cout << "\nTESTING READING CSV FILE 1" << std::endl;
    read_csv("./samples_csv/test_file_1_title_true.csv", true);
    
    //Test 2
    std::cout << "\nTESTING READING CSV FILE 2" << std::endl;
    read_csv("./samples_csv/test_file_2_title_false.csv", false);

    //Test 3
    std::cout << "\nTESTING READING CSV FILE 3" << std::endl;
    read_csv("./samples_csv/test_file_3_title_default.csv");

    //Test 4
    std::cout << "\nTESTING READING CSV FILE 4" << std::endl;
    read_csv("./samples_csv/test_file_4_separate_ex_space.csv", false, ' ');

    //Test 5
    std::cout << "\nTESTING READING CSV FILE 5" << std::endl;
    read_csv("./samples_csv/test_file_5_separate_ex_semicolon.csv", false, ';');

    //Test 6
    std::cout << "\nTESTING READING CSV FILE 6" << std::endl;
    read_csv("./samples_csv/test_file_6_separate_ex_default.csv", false);

    //Test 7
    std::cout << "\nTESTING READING CSV FILE 7" << std::endl;
    read_csv("./samples_csv/test_file_7_comment_*.csv", true,',', '*');

    //Test 8
    std::cout << "\nTESTING READING CSV FILE 8" << std::endl;
    read_csv("./samples_csv/test_file_8_comment_default.csv");

    //Test 9
    std::cout << "\nTESTING READING CSV FILE 9" << std::endl;
    read_csv("./samples_csv/test_file_9_origin_wine.csv", true);
    
}

