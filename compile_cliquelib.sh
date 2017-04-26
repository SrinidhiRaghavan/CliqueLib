#!/bin/bash
#compile_cliquelib.sh
#Script to compile the library and the use cases
set -e
make -f ./Makefile
cd UseCases/UseCase1/
make -f ./Makefile
cd ../UseCase2
make -f ./Makefile
cd ../..
