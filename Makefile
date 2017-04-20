# Stanislav Peceny

CC = g++-6
CXX = g++-6
INCLUDES = -I./tests -I./source  -I./source/Preprocessing -I./source/KNN -I./source/LogisticRegression -I./source/AdaBoost -I ./armadillo-7.800.2/include/
CXXFLAGS = -g -Wall --std=c++1z -o prog -O2 -larmadillo $(INCLUDES) 
LDFLAGS = -L ./armadillo-7.800.2/include/armadillo
LDLIBS  =

main: tests/test_read_csv.o tests/test_split_test_train_dataset.o tests/test_knn.o tests/test_logistic_regression.o tests/test_adaboost.o source/Preprocessing/preprocessing_functions.o source/KNN/knn.o source/LogisticRegression/logistic_regression.o source/AdaBoost/Stump.o source/AdaBoost/AdaBoost.o source/AdaBoost/BaggingClassifier.o

#main: tests/test_read_csv.o tests/test_split_test_train_dataset.o tests/test_knn.o tests/test_logistic_regression.o  source/Preprocessing/preprocessing_functions.o source/KNN/knn.o source/LogisticRegression/logistic_regression.o 

main.o: tests/tests.h

tests/test_read_csv.o: tests/tests.h

tests/test_split_test_train_dataset.o: tests/tests.h

tests/test_knn.o: tests/tests.h

tests/test_logistic_regression.o: tests/tests.h

tests/test_adaboost.o: tests/tests.h

source/Prepocessing/preprocessing_functions.o: source/Preprocessing/preprocessing_functions.h

source/KNN/knn.o: source/KNN/knn.h

source/LogisticRegression/logistic_regression.o: source/LogisticRegression/logistic_regression.h

source/AdaBoost/Stump.o: source/AdaBoost/Stump.h

source/AdaBoost/AdaBoost.o: source/AdaBoost/AdaBoost.h

source/AdaBoost/BaggingClassifier.o: source/AdaBoost/BaggingClassifier.h
 

.PHONY: clean
clean:
	rm -f *.o *~ tests/*.o  tests/*~ source/*.o  source/*~ source/Preprocessing/*.o source/Preprocessing/*~ source/KNN/*.o source/KNN/*~ source/LogisticRegression/*.o source/LogisticRegression/*~ source/AdaBoost/*.o source/AdaBoost/*~ a.out core main

.PHONY: all
	all: clean main

.PHONY: valgrind
valgrind: main
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main
