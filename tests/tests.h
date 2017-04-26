//============================================================================
// Name        : tests.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Tests definitions
//============================================================================

#ifndef __TESTS_H__
#define __TESTS_H__

#include <armadillo>
#include <iostream>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>
#include "preprocessing_functions.h"
#include "KNN.h"
#include "knnstd.h"
#include "logistic_regression.h"
#include "logistic_regression_std.h"
#include "SVM.h"
#include "naive_bayes.h"
#include "Stump.h"
#include "AdaBoost.h"
#include "BaggingClassifier.h"
#include "VotingClassifier.h"
#include "Perceptron.h"

//TEST IMPLEMENTATIONS
void test_read_csv();
void test_split_test_train_dataset();
void test_knn();
void test_knn_std();
void test_logistic_regression();
void test_logistic_regression_std();
void test_naive_bayes();
void test_adaboost();
void test_svm();
void test_usecase1();
void test_perceptron();

#endif
