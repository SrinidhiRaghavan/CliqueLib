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

using namespace std;
using namespace arma;

class SVM {
	colvec weight;
	uword C;
	

public:
	SVM(uword);
	void train(const mat&, const colvec&, uword);
	void predict(const mat&, colvec&);
};

#endif
