//--------------------------------------------------------------------------------------
//Name			:		Perceptron
//Author		:		Srinidhi Raghavan
//Project		:		CliqueLib
//Description		:		Header for the Perceptron
//Copyright		:
//Version		:
//Modified Date		:		04/26/2017
//--------------------------------------------------------------------------------------


#ifndef __Perceptron_H__
#define __Perceptron_H__

#pragma once
#include <iostream>
#include <armadillo>

using namespace std;
using namespace arma;

class Perceptron {
	colvec weight;

public:
	Perceptron(){};
	void train(const mat&, const colvec&, uword);
	void predict(const mat&, colvec&);
};

#endif
