//============================================================================
// Name        : test_usecase2.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Use Case 2 function
//============================================================================

#include <iostream>
#include <memory>
#include <armadillo>
#include <vector>
#include <cassert>
#include <cmath>
#include <utility>
#include "preprocessing_functions.h"
#include "Dataset.h"
#include "KNN.h"
#include "logistic_regression.h"
#include "SVM.h"
#include "Stump.h"
#include "AdaBoost.h"
#include "BaggingClassifier.h"
#include "VotingClassifier.h"
#include "Perceptron.h"

using namespace arma;

double getAccuracy(colvec& a, colvec& b) {
    return double(accu(a==b))/size(a, 0);
}

int main()
{
    //use case 2
    mat X;
    colvec Y;
    //read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    //read_csv("samples_csv/admits.csv", X, Y, false, ',', '#');
    read_csv("../../samples_csv/linear.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    //cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;
   
    Dataset data;
    split_train_test(X, Y, data, 0.8);
    cout << "size Xtrain:" << arma::size(data.Xtrain) << endl;
    cout << "size Ytrain:" << arma::size(data.Ytrain) << endl;
    cout << "size Xtest:" << arma::size(data.Xtest) << endl;
    cout << "size Ytest:" << arma::size(data.Ytest) << endl;
    
    /*
    AdaBoost clfr;
    clfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds;
    clfr.predict(data.Xtest, preds);

    auto acc = getAccuracy(data.Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl;
    */


    KNN knn_clfr;
    knn_clfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_knn;
    knn_clfr.predict(data.Xtest, preds_knn);

    auto acc_knn = getAccuracy(data.Ytest, preds_knn);
    cout << "KNN acc:" << acc_knn << endl;
   
    
    cout << "### Running SVM ###" << endl;
    SVM svm_clfr(0.1);
    svm_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_svm;
    svm_clfr.predict(data.Xtest, preds_svm);

    auto acc_svm = getAccuracy(data.Ytest, preds_svm);
    cout << "SVM acc:" << acc_svm << endl;

    cout << "### Running Perceptron ###" << endl;
    Perceptron pcptr_clfr;
    pcptr_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_pcptr;
    pcptr_clfr.predict(data.Xtest, preds_pcptr);

    auto acc_pcptr = getAccuracy(data.Ytest, preds_pcptr);
    cout << "Perceptron acc:" << acc_pcptr << endl;
    
    /*
    BaggingClassifier<AdaBoost> bgClfr(5, 400);
    bgClfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_bg;
    bgClfr.predict(data.Xtest, preds_bg);

    auto acc_bg = getAccuracy(data.Ytest, preds_bg);
    cout << "Bg adB acc:" << acc_bg << endl;

    BaggingClassifier<KNN> bgClfr(5, 400);
    bgClfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_bg;
    bgClfr.predict(data.Xtest, preds_bg);
    auto acc_bg = getAccuracy(data.Ytest, preds_bg);
    cout << "Bg knn acc:" << acc_bg << endl;

    BaggingClassifier<SVM> bgClfr_svm(5, 400);
    bgClfr_svm.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_bg_svm;
    bgClfr_svm.predict(data.Xtest, preds_bg_svm);

    auto acc_bg_svm = getAccuracy(data.Ytest, preds_bg_svm);
    cout << "Bg svm acc:" << acc_bg_svm << endl;
    

    Logistic logistic_clfr(0.01);
    logistic_clfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_log;
    logistic_clfr.predict(data.Xtest, preds_log);
    auto acc_log = getAccuracy(data.Ytest, preds_log);
    cout << "Logistic acc: " << acc_log << endl;	

    VotingClassifier vcClfr;
    auto svm_clfr_b = make_shared<SVM>(svm_clfr);
    auto pcptr_clfr_b = make_shared<Perceptron>(pcptr_clfr);
    auto logistic_clfr_b = make_shared<Logistic>(logistic_clfr);
    
    vcClfr.addClassifier(svm_clfr_b);
    vcClfr.addClassifier(pcptr_clfr_b);
    vcClfr.addClassifier(logistic_clfr_b);
    
    vcClfr.train(data.Xtrain, data.Ytrain, 100);
    colvec preds_vc;
    vcClfr.predict(data.Xtest, preds_vc);

    auto acc_vc = getAccuracy(data.Ytest, preds_vc);
    cout << "Vc acc:" << acc_vc << endl;
    */

    return 0;
}
