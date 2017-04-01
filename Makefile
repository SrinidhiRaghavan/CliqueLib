# Stanislav Peceny

CC = g++
CXX = g++
INCLUDES = -I./tests -I./source 
CXXFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS  =

main: tests/test_read_csv.o

main.o: tests/tests.h

tests/test_read_csv.o: tests/tests.h

.PHONY: clean
clean:
	rm -f *.o *~ tests/*.o  tests/*~ source/*.o  source/*~ a.out core main

.PHONY: all
	all: clean main

.PHONY: valgrind
valgrind: main
	valgrind --leak-check=full ./main
