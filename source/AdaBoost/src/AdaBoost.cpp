//============================================================================
// Name        : AdaBoost.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : CliqueLib AdaBoost implementation
//============================================================================

#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

void calculateThreshold(const colvec& x, const colvec& y, const colvec& w, const string& sign) {
	uword N = x.size();
	cout << "N: " << N << endl;
	
	colvec err_n, y_predict;
	err_n.zeros(N, 1);
	y_predict.zeros(N, 1);
	uvec idx;

	for (unsigned int i = 0; i < N; i++) {
		if (sign == "greater")
		{
			cout << ">" << endl;
			idx = find(x >= x(i));
			cout << "idx:" << idx << endl;
			y_predict.fill(-1);
			y_predict.elem(idx).ones();
			cout << "y_predict:" << y_predict << endl;
		}
		else
		{
			cout << "<" << endl;
			idx = find(x <= x(i));
			cout << "idx:" << idx << endl;
			y_predict.fill(-1);
			y_predict.elem(idx).ones();
			cout << "y_predict:" << y_predict << endl;
		}
		cout << "y.size():" << y.size() << endl;
		cout << "y_predict.size():" << y_predict.size() << endl;
		umat err_label = (y != y_predict);
		cout << "err_label:" << err_label << endl;
		err_n(i) = accu(err_label);
		cout << "sum:" << accu(err_label) << endl;
	}
	cout << "before err_n:" << err_n << endl;
	err_n = err_n / accu(w);
	cout << "after err_n:" << err_n << endl;
	double error = min(err_n);
	uword min_idx = index_min(err_n);
	double thres = x(min_idx);
	cout << "Min error:" << error << " found at idx:" << min_idx << " for thres:" << thres << endl;
}

int main()
{
	colvec x;
	x << 1.0 << endr
	  << 2.0 << endr
	  << 3.0 << endr;

	uword N = x.size();
	colvec w;
	w.ones(N, 1);
	
	colvec y;
	y << 1.0 << endr 
	  << -1.0 << endr
	  << 1.0 << endr;

	cout << "x:" << x << endl;
	cout << "y:" << y << endl;
	
	calculateThreshold(x, y, w, "lesser");
	
	getchar();
	return 0;
}