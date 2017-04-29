# CliqueLib
# Stanislav Peceny

CC = g++-6
CXX = g++-6
INCLUDES = -I ../../armadillo-7.800.2/include/ -I ../../source/Commons/ -I ../../source  -I ../../source/Preprocessing -I ../../source/LogisticRegression -I ../../source/LogisticRegressionStd

CXXFLAGS = -g -Wall --std=c++1z -fconcepts -o prog -O2 -DARMA_DONT_USE_WRAPPER -lblas -llapack -larmadillo $(INCLUDES) 
LDFLAGS = -L ../../armadillo-7.800.2/include/armadillo
LDLIBS  =

benchmark_logisticregression: ../../source/Preprocessing/preprocessing_functions.o ../../source/LogisticRegression/logistic_regression.o ../../source/LogisticRegressionStd/logistic_regression_std.o

benchmark_logisticregression.o:

../../source/Prepocessing/preprocessing_functions.o: ../../source/Preprocessing/preprocessing_functions.h

../../source/LogisticRegression/logistic_regression.o: ../../source/LogisticRegression/logistic_regression.h

../../source/LogisticRegressionStd/logistic_regression_std.o: ../../source/LogisticRegressionStd/logistic_regression_std.h

.PHONY: clean
clean:
	rm -f *.o *~ ../../source/*.o  ../../source/*~ ../../source/Preprocessing/*.o ../../source/Preprocessing/*~ ../../source/LogisticRegression/*.o ../../source/LogisticRegression/*~ ../../source/LogisticRegressionStd/*.o ../../source/LogisticRegressionStd/*~ a.out core benchmark_logisticregression

.PHONY: all
	all: clean benchmark_logisticregression

.PHONY: valgrind
valgrind: main
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./benchmark_logisticregression
