# CliqueLib
# Stanislav Peceny

CC = g++-6
CXX = g++-6
INCLUDES = -I ../../armadillo-7.800.2/include/ -I ../../source/Commons/ -I ../../source  -I ../../source/Preprocessing -I ../../source/AdaBoost -I ../../samples_csv

CXXFLAGS = -g -Wall --std=c++1z -fconcepts -o prog -O2 -DARMA_DONT_USE_WRAPPER -lblas -llapack -larmadillo $(INCLUDES) 
LDFLAGS = -L ../../armadillo-7.800.2/include/armadillo
LDLIBS  =

usecase1: ../../source/Preprocessing/preprocessing_functions.o ../../source/AdaBoost/Stump.o ../../source/AdaBoost/AdaBoost.o 

usecase1.o: 

source/Prepocessing/preprocessing_functions.o: ../../source/Preprocessing/preprocessing_functions.h

source/AdaBoost/Stump.o: ../../source/AdaBoost/Stump.h

source/AdaBoost/AdaBoost.o: ../../source/AdaBoost/AdaBoost.h

.PHONY: clean
clean:
	rm -f *.o *~ ../..source/*.o  ../../source/*~ ../../source/Preprocessing/*.o ../../source/Preprocessing/*~ ../../source/AdaBoost/*.o ../../source/AdaBoost/*~ a.out core usecase1

.PHONY: all
	all: clean usecase1

.PHONY: valgrind
valgrind: main
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main
