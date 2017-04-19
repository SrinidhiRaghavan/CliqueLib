#pragma once
#include <armadillo>

template<typename T>
class BaggingClassifier {
	vector<T*> base_estimators;
	u_word n_estimators;
	u_word max_samples;

public:
	BaggingClassifier(u_word, u_word);
	void fit(const mat&, const colvec&, uword);
};
