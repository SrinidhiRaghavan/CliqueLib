//--------------------------------------------------------------------------------------
//Name			:		Logistic Regression
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description		:		Header for the Logistic
//Copyright		:
//Version		:
//Modified Date		:		04/22/2017
//--------------------------------------------------------------------------------------


#ifndef __Logistic_H__
#define __Logistic_H__

#pragma once
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class Logistic {
	colvec weight;
	double C;

public:
	Logistic(double);
	void train(const mat&, const colvec&, uword);
	void predict(const mat&, colvec&);
};

#endif
