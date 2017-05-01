# CliqueLib
# Stanislav Peceny

CC = g++
CXX = g++
INCLUDES = -I ../../armadillo-7.800.2/include/ -I ../../source/Commons/ -I ../../source  -I ../../source/Preprocessing -I ../../source/KNN -I ../../source/KNNStd

CXXFLAGS = -g -Wall --std=c++1z -fconcepts -o prog -O2 -DARMA_DONT_USE_WRAPPER -lblas -llapack -larmadillo $(INCLUDES) 
LDFLAGS = -L ../../armadillo-7.800.2/include/armadillo
LDLIBS  =

benchmark_knn: ../../source/Preprocessing/preprocessing_functions.o ../../source/KNN/KNN.o ../../source/KNNStd/knnstd.o 

benchmark_knn.o: 

../../source/Prepocessing/preprocessing_functions.o: ../../source/Preprocessing/preprocessing_functions.h

../../source/KNN/KNN.o: ../../source/KNN/KNN.h

../../source/KNNStd/knnstd.o: ../../source/KNNStd/knnstd.h

.PHONY: clean
clean:
	rm -f *.o *~ source/*.o  source/*~ source/Preprocessing/*.o source/Preprocessing/*~ source/KNN/*.o source/KNN/*~ source/KNNStd/*.o source/KNNStd/*~ a.out core benchmark_knn

.PHONY: all
	all: clean benchmark_knn

.PHONY: valgrind
valgrind: benchmark_knn
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./benchmark_knn
