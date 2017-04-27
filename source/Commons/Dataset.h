//============================================================================
// Name        : Dataset.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Dataset structure
//============================================================================

#pragma once
#include <armadillo>

struct Dataset
{
    arma::mat Xtrain;
    arma::colvec Ytrain;
    arma::mat Xtest;
    arma::colvec Ytest;
};
