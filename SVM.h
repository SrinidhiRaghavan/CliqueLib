//--------------------------------------------------------------------------------------
//Name:					SVM
//Author:				Srinidhi Raghavan
//Project:				CliqueLib
//Description:			Header for the SVM
//Copyright:
//Version
//Last Modified Date:
//--------------------------------------------------------------------------------------


#ifndef __SVM_H__
#define __SVM_H__

#pragma once
#include <iostream>
#include <armadillo>

using namespace std;

class SVM {
	vector<double> w;
	double b;
	

public:
	SVM();
	void train(vector<vector<double>> X, vector<vector<double>> Y, int epoch);
	void predict(vector<vector<double>> X, vector<vector<double>> Y);
};

#endif
