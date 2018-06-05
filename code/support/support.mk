CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

MATH_DIR = ../math/
VMAOPS_OBJS = $(MATH_DIR)obj/vectorOps.o $(MATH_DIR)obj/matrixOps.o $(MATH_DIR)obj/arrayOps.o

.PHONY: all
all: bin/testSupportOps

bin/testSupportOps: obj/printOps.o obj/writeOps.o obj/testSupportOps.o $(VMAOPS_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*			
