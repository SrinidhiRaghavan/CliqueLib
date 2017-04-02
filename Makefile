# Stanislav Peceny

CC = g++-6
CXX = g++-6
INCLUDES = -I./tests -I./source 
CXXFLAGS = -g -Wall --std=c++1z $(INCLUDES)
LDFLAGS = -g
LDLIBS  =

main: tests/test_read_csv.o tests/test_split_test_train_dataset.o tests/test_knn.o source/preprocessing_functions.o source/knn.o

main.o: tests/tests.h

tests/test_read_csv.o: tests/tests.h

tests/test_split_test_train_dataset.o: tests/tests.h

tests/test_knn.o: tests/tests.h

source/preprocessing_functions.o: source/preprocessing_functions.h

source/knn.o: source/knn.h

.PHONY: clean
clean:
	rm -f *.o *~ tests/*.o  tests/*~ source/*.o  source/*~ a.out core main

.PHONY: all
	all: clean main

.PHONY: valgrind
valgrind: main
	valgrind -v --num-callers=20 --leak-check=yes --leak-resolution=high --show-reachable=yes ./main
