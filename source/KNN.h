//--------------------------------------------------------------------------------------
//Name			:		SVM
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description	:		Header for the KNN
//Copyright		:
//Version		:
//Modified Date	:
//--------------------------------------------------------------------------------------


#ifndef __SVM_H__
#define __SVM_H__

#pragma once
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class KNN {
	uword K;
	mat Xtrain;
	colvec Ytrain;

public:
	KNN(uword);
	void train(const mat&, const colvec&, uword);
	void predict(const mat&, colvec&);
};

#endif
