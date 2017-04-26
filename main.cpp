//============================================================================
// Name        : main.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Main function
//============================================================================

#include "tests.h"

using namespace arma;

double getAccuracy(colvec& a, colvec& b) {
    return double(accu(a==b))/size(a, 0);
}

int main()
{
    test_usecase1();
    /*
    mat X;
    colvec Y;
    //read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    //read_csv("samples_csv/admits.csv", X, Y, false, ',', '#');
    read_csv("samples_csv/face_detection.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    //cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;
    mat Xtrain = X.rows(0, 1599);
    colvec Ytrain = Y.rows(0, 1599);
    mat Xtest = X.rows(1600, 1998);
    colvec Ytest = Y.rows(1600, 1998);
    BaggingClassifier<SVM> bgClfr_svm(10, 1200);
    bgClfr_svm.train(Xtrain, Ytrain, 100);
    colvec preds_bg_svm;
    bgClfr_svm.predict(Xtest, preds_bg_svm);
    auto acc_bg_svm = getAccuracy(Ytest, preds_bg_svm);
    cout << "Bg svm acc:" << acc_bg_svm << endl;
    AdaBoost clfr;
    clfr.train(Xtrain, Ytrain, 100);
    colvec preds;
    clfr.predict(Xtest, preds);
    auto acc = getAccuracy(Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl;
    return 0;
    */

    mat X;
    colvec Y;
    //read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    //read_csv("samples_csv/admits.csv", X, Y, false, ',', '#');
    read_csv("samples_csv/Cancer.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    //cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;

    mat Xtrain = X.rows(0, 499);
    colvec Ytrain = Y.rows(0, 499);
    mat Xtest = X.rows(500, 567);
    colvec Ytest = Y.rows(500, 567);

    AdaBoost clfr;
    clfr.train(Xtrain, Ytrain, 100);
    colvec preds;
    clfr.predict(Xtest, preds);

    auto acc = getAccuracy(Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl;

    KNN knn_clfr;
    knn_clfr.train(Xtrain, Ytrain, 100);
    colvec preds_knn;
    knn_clfr.predict(Xtest, preds_knn);

    auto acc_knn = getAccuracy(Ytest, preds_knn);
    cout << "KNN acc:" << acc_knn << endl;
   
    
    SVM svm_clfr;
    svm_clfr.train(Xtrain, Ytrain, 100);
    colvec preds_svm;
    svm_clfr.predict(Xtest, preds_svm);

    auto acc_svm = getAccuracy(Ytest, preds_svm);
    cout << "SVM acc:" << acc_svm << endl;
   
    
    BaggingClassifier<AdaBoost> bgClfr(5, 400);
    bgClfr.train(Xtrain, Ytrain, 100);
    colvec preds_bg;
    bgClfr.predict(Xtest, preds_bg);

    auto acc_bg = getAccuracy(Ytest, preds_bg);
    cout << "Bg adB acc:" << acc_bg << endl;
    
    /*
    BaggingClassifier<KNN> bgClfr(5, 400);
    bgClfr.train(Xtrain, Ytrain, 100);
    colvec preds_bg;
    bgClfr.predict(Xtest, preds_bg);
    auto acc_bg = getAccuracy(Ytest, preds_bg);
    cout << "Bg knn acc:" << acc_bg << endl;
    */

    BaggingClassifier<SVM> bgClfr_svm(5, 400);
    bgClfr_svm.train(Xtrain, Ytrain, 100);
    colvec preds_bg_svm;
    bgClfr_svm.predict(Xtest, preds_bg_svm);

    auto acc_bg_svm = getAccuracy(Ytest, preds_bg_svm);
    cout << "Bg svm acc:" << acc_bg_svm << endl;
    
    /*
    colvec a,b;
    a << 1.0 << endr
		<< -1.0 << endr
		<< 1.0 << endr
		<< -1.0 << endr
		<< -1.0 << endr;
    b << -1.0 << endr
		<< 1.0 << endr
		<< 1.0 << endr
		<< -1.0 << endr
		<< -1.0 << endr;
    */
    
    //cout << "X:" << X << endl;
    //cout << "Y:" << Y << endl;

    //test svm
    //test_svm();
	
    Logistic logistic_clfr(0.01);
    logistic_clfr.train(Xtrain, Ytrain, 100);
    colvec preds_log;
    logistic_clfr.predict(Xtest, preds_log);
    auto acc_log = getAccuracy(Ytest, preds_log);
    cout << "Logistic acc: " << acc_log << endl;	

    VotingClassifier vcClfr;
    BaseClassifier* svm_clfr_b = (BaseClassifier*)&svm_clfr;
    BaseClassifier* knn_clfr_b = (BaseClassifier*)&knn_clfr;
    BaseClassifier* logistic_clfr_b = (BaseClassifier*)&logistic_clfr;
    vcClfr.addClassifier(svm_clfr_b);
    vcClfr.addClassifier(knn_clfr_b);
    vcClfr.addClassifier(logistic_clfr_b);
    vcClfr.train(Xtrain, Ytrain, 100);
    colvec preds_vc;
    vcClfr.predict(Xtest, preds_vc);

    auto acc_vc = getAccuracy(Ytest, preds_vc);
    cout << "Vc acc:" << acc_vc << endl;

    return 0;
}
