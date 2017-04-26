//============================================================================
// Name        : Stump.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib Stump definition
//============================================================================

#ifndef __STUMP_H__
#define __STUMP_H__

#pragma once
#include <iostream>
#include <armadillo>

class Stump 
{
    private:
	unsigned int dim;
	double error;
	double threshold;
	int less;
	int more;

    public:
	Stump(unsigned int);
	double getError();
	unsigned int getDimension();
	void buildOneDStump(const arma::colvec&, const arma::colvec&, const arma::colvec&);
	void calculateThreshold(const arma::colvec&, const arma::colvec&, const arma::colvec&, const std::string&, double&, double&);
	void predictStump(const arma::mat&, arma::colvec&);
	friend std::ostream& operator<<(std::ostream& os, const Stump* s);
};

#endif
