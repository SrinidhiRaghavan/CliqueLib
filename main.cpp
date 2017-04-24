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
    read_csv("samples_csv/admits.csv", X, Y, true, ',', '#');
    cout << "size X:" << arma::size(X) << endl;
    cout << "size Y:" << arma::size(Y) << endl;
    cout << "X:" << X.rows(0, 4) << endl;
    cout << "Y:" << Y.rows(0, 4) << endl;

    AdaBoost clfr;
    clfr.train(X, Y, 5);
    colvec preds;
    clfr.predict(X, preds);
    
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

    auto acc = getAccuracy(Y, preds);
    cout << "acc:" << acc << endl;
    
    //cout << "X:" << X << endl;
    //cout << "Y:" << Y << endl;

    return 0;
}
