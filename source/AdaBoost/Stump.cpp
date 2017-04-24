#include <armadillo>
#include <iostream>
#include "Stump.h"

using namespace std;
using namespace arma;

Stump::Stump(unsigned int dim) {
	this->dim = dim;
	error = 0;
	threshold = 0;
	less = 1;
	more = -1;
}

double Stump::getError() {
	return error;
}

unsigned int Stump::getDimension() {
	return dim;
}

void Stump::buildOneDStump(const colvec& x, const colvec& y, const colvec& w) {
	double err1, err2, thres1, thres2;
	calculateThreshold(x, y, w, "greater", err1, thres1);
	calculateThreshold(x, y, w, "lesser", err2, thres2);

	if (err1 <= err2)
	{
		threshold = thres1;
		error = err1;
		less = -1;
		more = 1;
	}
	else
	{
		threshold = thres2;
		error = err2;
		less = 1;
		more = -1;
	}
}

void Stump::calculateThreshold(const colvec& x, const colvec& y, const colvec& w, const string& sign, double& error, double& thres) {
	uword N = x.size();
	//cout << "N: " << N << endl;

	colvec err_n, y_predict;
	err_n.zeros(N, 1);
	y_predict.zeros(N, 1);
	uvec idx;

	for (unsigned int i = 0; i < N; i++) {
		if (sign == "greater")
		{
			//cout << ">" << endl;
			idx = find(x >= x(i));
			//cout << "idx:" << idx << endl;
			y_predict.fill(-1);
			y_predict.elem(idx).ones();
			//cout << "y_predict:" << y_predict << endl;
		}
		else
		{
			//cout << "<" << endl;
			idx = find(x < x(i));
			//cout << "idx:" << idx << endl;
			y_predict.fill(-1);
			y_predict.elem(idx).ones();
			//cout << "y_predict:" << y_predict << endl;
		}
		//cout << "y.size():" << y.size() << endl;
		//cout << "y_predict.size():" << y_predict.size() << endl;
		umat err_label = (y != y_predict);
		//cout << "err_label:" << err_label << endl;
		err_n(i) = accu(err_label % w) / accu(w);
		//cout << "sum:" << accu(err_label) << endl;
	}
	//cout << "before err_n:" << err_n << endl;
	//err_n = err_n / accu(w);
	//cout << "after err_n:" << err_n << endl;
	error = min(err_n);
	uword min_idx = index_min(err_n);
	thres = x(min_idx);
	//cout << "Min error:" << error << " found at idx:" << min_idx << " for thres:" << thres << endl;
}

void Stump::predictStump(const mat& X, colvec& labels) {
	uword n = size(X, 0); //no. of samples
	labels.zeros(n, 1);

	colvec x = X.col(dim);
	//cout << "predictStump: x:" << x;
	uvec idx = find(x >= threshold);
	//cout << "predictStump: idx:" << idx << endl;
	labels.fill(less);
	labels.elem(idx).fill(more);
}

ostream& operator<<(ostream& os, const Stump* s)
{
	os << "dim:" << s->dim << endl;
	os << "error:" << s->error << endl;
	os << "threshold:" << s->threshold << endl;
	os << "less:" << s->less << endl;
	os << "more:" << s->more << endl;
	return os;
}
