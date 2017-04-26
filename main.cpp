/**
main.cpp
Stan Peceny
skp2140
4/1/2017
*/

#include <armadillo>
#include "tests.h"
using namespace arma;

double getAccuracy(colvec& a, colvec& b) {
    return double(accu(a==b))/size(a, 0);
}

int main()
{
    mat X;
    colvec Y;
    //read_csv("samples_csv/toy_sample.csv", X, Y, true, ',', '#');
    //read_csv("samples_csv/admits.csv", X, Y, false, ',', '#');
    read_csv("samples_csv/admits.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;

    mat Xtrain = X.rows(0, 79);
    colvec Ytrain = Y.rows(0, 79);
    mat Xtest = X.rows(60, 99);
    colvec Ytest = Y.rows(60, 99);

    AdaBoost clfr;
    clfr.train(Xtrain, Ytrain, 100);
    colvec preds;
    clfr.predict(Xtest, preds);

    auto acc = getAccuracy(Ytest, preds);
    cout << "AdaBoost acc:" << acc << endl;
    
    KNN knn_clfr(3);
    knn_clfr.train(Xtrain, Ytrain, 5);
    colvec preds_knn;
    knn_clfr.predict(Xtest, preds_knn);

    auto acc_knn = getAccuracy(Ytest, preds_knn);
    cout << "KNN acc:" << acc_knn << endl;
   
    
    SVM svm_clfr(0.1);
    svm_clfr.train(Xtrain, Ytrain, 1000);
    colvec preds_svm;
    svm_clfr.predict(Xtest, preds_svm);

    auto acc_svm = getAccuracy(Ytest, preds_svm);
    cout << "SVM acc:" << acc_svm << endl;
   

    BaggingClassifier<AdaBoost> bgClfr(5, 70);
    bgClfr.train(Xtrain, Ytrain, 100);
    colvec preds_bg;
    bgClfr.predict(Xtest, preds_bg);

    auto acc_bg = getAccuracy(Ytest, preds_bg);
    cout << "Bg acc:" << acc_bg << endl;

    VotingClassifier vcClfr;
    BaseClassifier* clfr_b = (BaseClassifier*)&clfr;
    BaseClassifier* knn_clfr_b = (BaseClassifier*)&knn_clfr;
    vcClfr.addClassifier(clfr_b);
    vcClfr.addClassifier(knn_clfr_b);
    vcClfr.addClassifier(knn_clfr_b);
    vcClfr.addClassifier(clfr_b);
    vcClfr.addClassifier(clfr_b);
    vcClfr.train(Xtrain, Ytrain, 100);
    colvec preds_vc;
    vcClfr.predict(Xtest, preds_vc);

    auto acc_vc = getAccuracy(Ytest, preds_vc);
    cout << "Vc acc:" << acc_vc << endl;
    
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
    logistic_clfr.train(X, Y, 1250);
    colvec preds_log;
    logistic_clfr.predict(X, preds_log);
    auto acc_log = getAccuracy(Y, preds_log);
    cout << "Logistic acc: " << acc_log << endl;	
    return 0;
}
