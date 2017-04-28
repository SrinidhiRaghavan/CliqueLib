#!/bin/bash
#compile_cliquelib.sh
#Script to compile the library and the use cases
set -e
#compile all library's algorithms and run tests
make clean
#compile benchmarking for KNN
cd Benchmarking/KNN/
make clean
#compile benchmarking for Logistic Regression
cd ../LogisticRegression/
make clean
#compile use case 1
cd ../..
cd UseCases/UseCase1/
make clean
#compile use case 2
cd ../UseCase2
make clean
cd ../..
