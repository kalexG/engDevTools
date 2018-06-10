CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# Objects you need from other modules
MATH_DIR = ../math/
VMAOPS_OBJS = $(MATH_DIR)obj/vectorOps.o $(MATH_DIR)obj/matrixOps.o $(MATH_DIR)obj/arrayOps.o

# All objects
PRWOPS_OBJS = obj/printOps.o obj/writeOps.o obj/readOps.o obj/testPrwOps.o

# All executables
SUPPORT_BIN = bin/testPrwOps

.PHONY: support-obj support-bin
support-obj: $(PRWOPS_OBJS)
support-bin: $(SUPPORT_BIN)

bin/testPrwOps: $(PRWOPS_OBJS) $(VMAOPS_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
