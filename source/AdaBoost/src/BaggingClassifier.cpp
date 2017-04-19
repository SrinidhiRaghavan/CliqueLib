#include "BaggingClassifier.h"

template<typename T>
BaggingClassifier::BaggingClassifier(u_word n_estimators, u_word max_samples) {
	this->n_estimators = n_estimators;
	this->max_samples = max_samples;
}

template<typename T>
void BaggingClassifier::fit(const mat& X, const colvec& Y, uword iter) {

}

template BaggingClassifier<AdaBoost>(u_word, u_word);
template void fit<AdaBoost>(const mat&, const colvec&, uword);