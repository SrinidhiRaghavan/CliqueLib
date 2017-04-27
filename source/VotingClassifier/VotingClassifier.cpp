//============================================================================
// Name        : VotingClassifier.cpp
// Author      : CliqueLib
// Version     :
// Copyright   : 
// Description : CliqueLib VotingClassifier implementation
//============================================================================

#include <iostream>
#include <cmath>
#include "VotingClassifier.h"

using namespace std;
using namespace arma;

void VotingClassifier::train(const mat& X, const colvec& Y, uword iter) 
{
    auto baseIter = base_estimators.begin();
    for (uword i = 0; baseIter != base_estimators.end(); baseIter++, i++) 
    {
        auto clfr = *baseIter;
	clfr->train(X, Y, iter);
    }
}

void VotingClassifier::predict(const mat& testX, colvec& labels) 
{
    uword n_estimators = base_estimators.size();
    uword n = size(testX, 0);
    mat predMat;
    predMat.zeros(n, n_estimators);
    labels.zeros(n, 1);

    auto baseIter = base_estimators.begin();
    for (uword i = 0; baseIter != base_estimators.end(); baseIter++, i++) 
    {
	auto clfr = *baseIter;
	colvec preds;
	preds.zeros(n, 1);
	clfr->predict(testX, preds);
	predMat.col(i) = preds;
    }

    uvec idx = find(mean(predMat, 1) > 0);
    labels.fill(-1);
    labels.elem(idx).fill(1);
}

void VotingClassifier::addClassifier(std::shared_ptr<BaseClassifier> clfr) 
{
    base_estimators.push_back(clfr);
}
