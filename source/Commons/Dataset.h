//============================================================================
// Name        : Dataset.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : Dataset structure
//============================================================================

#pragma once
#include <armadillo>

/**
 * The Dataset structure is a convenient implementation
 * constituting the basic components of a Dataset.
 * Each dataset contains a matrix of features that is used
 * for training and a vector column that is used for training.
 * Similarly, the dataset further has a testing component 
 * that represents a matrix of features and a vector column
 * of labels that needs to be predicted by a selected algorithm
 * and tested.
*/
struct Dataset
{
    arma::mat Xtrain; /*!< Xtrain is a matrix of attributes used for training */
    arma::colvec Ytrain; /*!< Ytrain is a vector column of labels used for training */
    arma::mat Xtest; /*!< Xtest is a matrix of attributes used for testing */
    arma::colvec Ytest; /*!< Ytest is a vector column of labels to be tested with */
};
