//============================================================================
// Name        : AdaBoost.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : CliqueLib AdaBoost implementation
//============================================================================

#include <iostream>
#include <armadillo>
#include <math.h>

using namespace std;
using namespace arma;

class Stump {
	unsigned int dim;
	double error;
	double threshold;
	int less;
	int more;

public:
	Stump(unsigned int dim) {
		this->dim = dim;
		error = 0;
		threshold = 0;
		less = 1;
		more = -1;
	}

	double getError() {
		return error;
	}

	unsigned int getDimension() {
		return dim;
	}

	void buildOneDStump(const colvec& x, const colvec& y, const colvec& w) {
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

	void calculateThreshold(const colvec& x, const colvec& y, const colvec& w, const string& sign, double& error, double& thres) {
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
				idx = find(x < x(i));
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
		error = min(err_n);
		uword min_idx = index_min(err_n);
		thres = x(min_idx);
		cout << "Min error:" << error << " found at idx:" << min_idx << " for thres:" << thres << endl;
	}

	void predictStump(const mat& X, colvec& labels) {;
		colvec x = X.col(dim);
		uvec idx = find(x >= threshold);
		cout << "idx:" << idx << endl;
		labels.fill(less);
		labels.elem(idx).fill(more);
	}
	friend ostream& operator<<(ostream& os, const Stump& s);
};

ostream& operator<<(ostream& os, const Stump& s)
{
	os << "dim:" << s.dim << endl;
	os << "error:" << s.error << endl;
	os << "threshold:" << s.threshold << endl;
	os << "less:" << s.less << endl;
	os << "more:" << s.more << endl;
	return os;
}

Stump* buildStump(const mat& X, const colvec& y, const colvec& weight) {
	uword d = size(X, 1);
	vector<Stump*> stumps;
	rowvec errors;
	errors.zeros(1, d);
	for (unsigned int i = 0; i < d; i++) {
		stumps[i] = new Stump(i);
		stumps[i]->buildOneDStump(X.col(i), y, weight);
		errors(1, i) = stumps[i]->getError();
	}
	uword min_idx = index_min(errors);
	return stumps[min_idx];
}

class AdaBoost {
	vector<Stump*> weakClassifiers;
	vector<double> weights;
public:
	AdaBoost() {
	}

	void fit(const mat& X, const colvec& Y, uword iter) {
		uword n = size(X, 0); //no. of samples
		colvec sampleWts(n);
		sampleWts.fill(1/n);

		for (uword i = 0; i < iter; i++) {
			Stump* clfr = buildStump(X, Y, sampleWts);
			double err = clfr->getError();
			double alpha = 0.5*log((1 - err) / err);

			colvec preds(n);
			preds.zeros();
			clfr->predictStump(X, preds);

			sampleWts *= exp(-alpha * Y % preds);
			sampleWts /= accu(sampleWts);

			weakClassifiers[i] = clfr;
			weights[i] = alpha;
		}
	}

	void predict(const mat& testX, colvec& preds) {
		uword n = size(testX, 0); //no. of samples
		colvec labels;
		colvec sum;
		sum.zeros(n, 1);
		labels.zeros(n, 1);
		preds.zeros(n, 1);

		auto weakIter = weakClassifiers.begin();
		auto wtIter = weights.begin();
		for (; weakIter != weakClassifiers.end(); weakIter++, wtIter++) {
			Stump* clfr = *weakIter;
			double wt = *wtIter;

			clfr->predictStump(testX, labels);
			sum += wt*labels;
		}
		preds.fill(-1);
		uvec idx = find(sum > 0);
		preds.elem(idx).fill(1);
	}
};

int main()
{
	colvec x;
	x << 1.0 << endr
		<< 2.0 << endr
		<< 3.0 << endr
		<< 1.0 << endr;

	cout << "size(x)" << arma::size(x) << " x.size()" << x.size() << endl;
	uword N = x.size();
	colvec w;
	w.ones(N, 1);
	
	colvec y;
	y << 1.0 << endr
		<< 1.0 << endr
		<< 1.0 << endr
		<< -1.0 << endr;

	//cout << "x:" << x << endl;
	//cout << "y:" << y << endl;

	vector<double> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);

	mat a(v);
	a.reshape(3, 2);
	a = a.t();

	//cout << "a:" << a << endl;
	//cout << "size(a)" << arma::size(a) << " size(a, 0):" << size(a, 0) << " size(a, 1):" << size(a, 1) << endl;
	
	Stump s(1);
	double error, thres;
	//s.calculateThreshold(x, y, w, "greater", error, thres);
	s.buildOneDStump(x, y, w);
	cout << s;
	
	getchar();
	return 0;
}