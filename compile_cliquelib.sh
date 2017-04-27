#!/bin/bash
#compile_cliquelib.sh
#Script to compile the library and the use cases
set -e
#compile all library's algorithms and run tests
make -f ./Makefile
#compile benchmarking for KNN
cd Benchmarking/KNN/
make -f ./Makefile
#compile benchmarking for Logistic Regression
cd ../LogisticRegression/
make -f ./Makefile
#compile use case 1
cd ../..
cd UseCases/UseCase1/
make -f ./Makefile
#compile use case 2
cd ../UseCase2
make -f ./Makefile
cd ../..
