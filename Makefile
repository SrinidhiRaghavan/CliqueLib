# Stanislav Peceny

CC = g++
CXX = g++
INCLUDES = 
CXXFLAGS = -g -Wall $(INCLUDES)
LDFLAGS = -g
LDLIBS  =

main: test_read_csv.o

main.o: tests.h

test_read_csv.o: tests.h

.PHONY: clean
clean:
	rm -f *.o *~ a.out core main

.PHONY: all
	all: clean main

.PHONY: valgrind
valgrind: main
	valgrind --leak-check=full ./main
