//============================================================================
// Name        : Perceptron.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Perceptron definition
//============================================================================

#ifndef __Perceptron_H__
#define __Perceptron_H__

#pragma once
#include <iostream>
#include <armadillo>
#include <cmath>
#include "BaseClassifier.h"

using namespace std;
using namespace arma;

class Perceptron : public BaseClassifier
{
    private:
	colvec weight;
	double neta;

    public:
	Perceptron(double);
	void train(const mat&, const colvec&, uword);
	void predict(const mat&, colvec&);
};

#endif
