//============================================================================
// Name        : BaggingClassifier.h
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib BaggingClassifier definition
//============================================================================

#pragma once
#include <armadillo>

template<typename T>
class BaggingClassifier {
	vector<T*> base_estimators;
	u_word n_estimators;
	u_word max_samples;

public:
	BaggingClassifier(uword, uword);
	void fit(const mat&, const colvec&, uword);
};
