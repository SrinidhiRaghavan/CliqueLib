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
	unsigned int dim; /*!< Dimension of the data set that this stump is built on
                       */
	double error; /*!< Error when classifying using this stump
                    */
	double threshold; /*!< Threshold dividing the two label classes
                       */
	int less; /*!< Value to assign to labels with dimension data values less than the threshold
                 */
	int more; /*!< Value to assign to labels with dimension data values more than the threshold
                       */

    public:
	Stump(unsigned int); /**< Stump constructor, accepting dimension value to build the stump over
                       */
	double getError(); /**< Function to fetch stump error
                       */
	unsigned int getDimension(); /**< Function to fetch stump dimension
                                    */
	void buildOneDStump(const arma::colvec&, const arma::colvec&, const arma::colvec&); /**< Builds the stump over the given dimension
                                                                                             Sets optimal threshold, less, more values
                                                                                            */
	void calculateThreshold(const arma::colvec&, const arma::colvec&, const arma::colvec&, const std::string&, double&, double&);
    /**< Calculate the optimal threshold to minimize stump error
       */
	void predictStump(const arma::mat&, arma::colvec&); /**< predict the labels based on the threshold for the dimension the stump is built on
                                                           */
	friend std::ostream& operator<<(std::ostream& os, const Stump* s); /**< Friend function displaying the Stump
                                                                          */
};

#endif
