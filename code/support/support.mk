CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# Objects you need from other modules
MATH_DIR = ../math/
VMAOPS_OBJS = $(MATH_DIR)obj/vectorOps.o $(MATH_DIR)obj/matrixOps.o $(MATH_DIR)obj/arrayOps.o

# All objects
SUPPORTOPS_OBJS = obj/printOps.o obj/writeOps.o obj/testSupportOps.o

# All executables
SUPPORT_BIN = bin/testSupportOps

.PHONY: support-obj support-bin
support-obj: $(SUPPORTOPS_OBJS)
support-bin: $(SUPPORT_BIN)

bin/testSupportOps: $(SUPPORTOPS_OBJS) $(VMAOPS_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
