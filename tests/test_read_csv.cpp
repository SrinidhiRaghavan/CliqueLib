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
    read_csv("origin_wine.csv");
    
    //Test 2
    std::cout << "\nTESTING READING CSV FILE 2" << std::endl;
    read_csv("test_file_2.csv");

    //Test 3
    std::cout << "\nTESTING READING CSV FILE 3" << std::endl;
    read_csv("test_file_3.csv");

    //Test 4
    std::cout << "\nTESTING READING CSV FILE 4" << std::endl;
    read_csv("test_file_4.csv");

    //Test 5
    std::cout << "\nTESTING READING CSV FILE 5" << std::endl;
    read_csv("test_file_5.csv");
    
}

