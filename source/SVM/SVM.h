//--------------------------------------------------------------------------------------
//Name			:		SVM
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description		:		Header for the SVM
//Copyright		:
//Version		:
//Last Modified Date	:
//--------------------------------------------------------------------------------------


#ifndef __SVM_H__
#define __SVM_H__

#pragma once
#include <iostream>
#include <armadillo>
#include "BaseClassifier.h"

using namespace std;
using namespace arma;

class SVM : public BaseClassifier {
	colvec weight;
	double C;
	

public:
	SVM() : SVM(0.1) {}
	SVM(double);
	void train(const mat&, const colvec&, uword);
	void predict(const mat&, colvec&);
        
        //get Regularization Parameter C
        double getRegularizationParameter() { return C; };
        
        //set Regularization Parameter C
        void setRegularizationParameter(double C) { this->C = C; }
};

#endif
