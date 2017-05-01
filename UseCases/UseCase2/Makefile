# CliqueLib
# Stanislav Peceny

CC = g++
CXX = g++
INCLUDES = -I ../../armadillo-7.800.2/include/ -I ../../source/Commons/ -I ../../source  -I ../../source/Preprocessing -I ../../source/KNN -I ../../source/LogisticRegression -I ../../source/AdaBoost -I ../../source/SVM -I ../../source/BaggingClassifier -I ../../source/VotingClassifier -I ../../source/Perceptron

CXXFLAGS = -g -Wall --std=c++1z -fconcepts -o prog -O2 -DARMA_DONT_USE_WRAPPER -lblas -llapack -larmadillo $(INCLUDES) 
LDFLAGS = -L ../../armadillo-7.800.2/include/armadillo
LDLIBS  =

usecase2: ../../source/Preprocessing/preprocessing_functions.o ../../source/KNN/KNN.o ../../source/LogisticRegression/logistic_regression.o ../../source/AdaBoost/Stump.o ../../source/AdaBoost/AdaBoost.o ../../source/SVM/SVM.o ../../source/BaggingClassifier/BaggingClassifier.o ../../source/VotingClassifier/VotingClassifier.o ../../source/VotingClassifier/VotingClassifier.o ../../source/Perceptron/Perceptron.o 

usecase2.o: 

../../source/Prepocessing/preprocessing_functions.o: ../../source/Preprocessing/preprocessing_functions.h

../../source/KNN/KNN.o: ../../source/KNN/KNN.h

../../source/LogisticRegression/logistic_regression.o: ../../source/LogisticRegression/logistic_regression.h

../../source/NaiveBayes/naive_bayes.o: ../../source/NaiveBayes/naive_bayes.h

../../source/AdaBoost/Stump.o: ../../source/AdaBoost/Stump.h

../../source/SVM/SVM.o: ../../source/SVM/SVM.h

../../source/AdaBoost/AdaBoost.o: ../../source/AdaBoost/AdaBoost.h

../../source/BaggingClassifier/BaggingClassifier.o: ../../source/BaggingClassifier/BaggingClassifier.h

../../source/VotingClassifier/VotingClassifier.o: ../../source/VotingClassifier/VotingClassifier.h

../../source/Perceptron/Perceptron.o : ../../source/Perceptron/Perceptron.h

.PHONY: clean
clean:
	rm -f *.o *~ ../../source/*.o  ../../source/*~ ../../source/Preprocessing/*.o ../../source/Preprocessing/*~ ../../source/KNN/*.o ../../source/KNN/*~ ../../source/LogisticRegression/*.o ../../source/LogisticRegression/*~ ../../source/AdaBoost/*.o ../../source/AdaBoost/*~ ../../source/BaggingClassifier/*.o ../../source/BaggingClassifier/*~ ../../source/VotingClassifier/*~ ../../source/VotingClassifier/*.o ../../source/SVM/*.o ../../source/SVM/*~ ../../source/Perceptron/*.o ../../source/Perceptron/*~ a.out core usecase2

.PHONY: all
	all: clean usecase2

.PHONY: valgrind
valgrind: usecase2
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./usecase2
