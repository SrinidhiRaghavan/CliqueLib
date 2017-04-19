# Stanislav Peceny

CC = g++-6
CXX = g++-6
INCLUDES = -I./tests -I./source  -I./source/Preprocessing -I./source/KNN -I./source/LogisticRegression
CXXFLAGS = -g -Wall --std=c++1z $(INCLUDES)
LDFLAGS = -g
LDLIBS  =

main: tests/test_read_csv.o tests/test_split_test_train_dataset.o tests/test_knn.o tests/test_logistic_regression.o source/Preprocessing/preprocessing_functions.o source/KNN/knn.o source/LogisticRegression/logistic_regression.o

main.o: tests/tests.h

tests/test_read_csv.o: tests/tests.h

tests/test_split_test_train_dataset.o: tests/tests.h

tests/test_knn.o: tests/tests.h

tests/test_logistic_regression.o: tests/tests.h

source/Prepocessing/preprocessing_functions.o: source/Preprocessing/preprocessing_functions.h

source/KNN/knn.o: source/KNN/knn.h

source/LogisticRegression/logistic_regression.o: source/LogisticRegression/logistic_regression.h

.PHONY: clean
clean:
	rm -f *.o *~ tests/*.o  tests/*~ source/*.o  source/*~ source/Preprocessing/*.o source/Preprocessing/*~ source/KNN/*.o source/KNN/*~ source/LogisticRegression/*.o source/LogisticRegression/*~ a.out core main

.PHONY: all
	all: clean main

.PHONY: valgrind
valgrind: main
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main
