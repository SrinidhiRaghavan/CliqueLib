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

double getAccuracy(colvec& a, colvec& b) 
{
    return (100 * (double(accu(a==b))/size(a, 0)));
}

int main()
{
    cout << "" << endl;
    cout << "Initiating Cancer Tumor classification..." << endl;
    cout << "" << endl;
    cout << "We draw 569 samples from Cancer.csv which has" << endl;
    cout << "31 cancer tumor features like parameter, texture, compactness..." << endl;
    cout << "We aim to classify the tumor as Malignant(-1) or Benign(1)" << endl;
    cout << "" << endl;
    
    mat X;
    colvec Y;
    cout << "Loading data set from csv..." << endl;
    read_csv("../../samples_csv/Cancer.csv", X, Y, true, ',', '#');
   
    cout << "Splitting data set into training and testing sets with ratio 80%-20%..." << endl;
    cout << "" << endl;
    Dataset data;
    split_train_test(X, Y, data, 0.8);
    
    cout << "Training AdaBoost with 5 decision Stumps..." << endl;
    AdaBoost clfr;
    clfr.train(data.Xtrain, data.Ytrain, 5);
    colvec preds;
    clfr.predict(data.Xtest, preds);

    auto acc = getAccuracy(data.Ytest, preds);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    cout << "Training K-means with K=23 ..." << endl;
    KNN knn_clfr(23);
    knn_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_knn;
    knn_clfr.predict(data.Xtest, preds_knn);

    acc = getAccuracy(data.Ytest, preds_knn);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;
   
    
    cout << "Training SVM with regularization parameter=0.1 and 1000 epochs..." << endl;
    SVM svm_clfr(0.1);
    svm_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_svm;
    svm_clfr.predict(data.Xtest, preds_svm);

    acc = getAccuracy(data.Ytest, preds_svm);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    cout << "Training Perceptron with learning rate 0.01 and 1000 epochs..." << endl;
    Perceptron pcptr_clfr(0.01);
    pcptr_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_pcptr;
    pcptr_clfr.predict(data.Xtest, preds_pcptr);

    acc = getAccuracy(data.Ytest, preds_pcptr);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    cout << "Training Logistic regression with learning rate 0.01 and 1000 epochs..." << endl;
    Logistic logistic_clfr(0.01);
    logistic_clfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_log;
    
    logistic_clfr.predict(data.Xtest, preds_log);
    acc = getAccuracy(data.Ytest, preds_log);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;
    
    cout << "Training Bagging Classifier over 5 KNN models and 1000 epochs..." << endl;
    BaggingClassifier<KNN> bgClfr(5, 350);
    bgClfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_bg;
    bgClfr.predict(data.Xtest, preds_bg);
    
    acc = getAccuracy(data.Ytest, preds_bg);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    cout << "Training Bagging Classifier over 5 SVM models and 1000 epochs..." << endl;
    BaggingClassifier<SVM> bgClfr_svm(5, 280);
    bgClfr_svm.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_bg_svm;
    bgClfr_svm.predict(data.Xtest, preds_bg_svm);

    acc = getAccuracy(data.Ytest, preds_bg_svm);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    cout << "Training Voting Classifier over KNN, Perceptron and Logistic..." << endl;
    VotingClassifier vcClfr;
    auto knn_clfr_b = make_shared<KNN>(knn_clfr);
    auto pcptr_clfr_b = make_shared<Perceptron>(pcptr_clfr);
    auto logistic_clfr_b = make_shared<Logistic>(logistic_clfr);
    
    vcClfr.addClassifier(knn_clfr_b);
    vcClfr.addClassifier(pcptr_clfr_b);
    vcClfr.addClassifier(logistic_clfr_b);
    
    vcClfr.train(data.Xtrain, data.Ytrain, 1000);
    colvec preds_vc;
    vcClfr.predict(data.Xtest, preds_vc);

    acc = getAccuracy(data.Ytest, preds_vc);
    cout << "Testing accuracy: " << acc << "%" << endl;
    cout << "" << endl;

    return 0;
}
