/**
tests.h
Stan Peceny
skp2140
4/1/2017
*/

#ifndef __TESTS_H__
#define __TESTS_H__

#include <armadillo>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include "preprocessing_functions.h"
#include "knn.h"
#include "logistic_regression.h"
#include "naive_bayes.h"
#include "Stump.h"
#include "AdaBoost.h"
#include "BaggingClassifier.h"

//TEST IMPLEMENTATIONS
void test_read_csv();
void test_split_test_train_dataset();
void test_knn();
void test_logistic_regression();
void test_naive_bayes();
void test_adaboost();

#endif
