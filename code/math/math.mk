CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# All objects
VMAOPS_OBJS = obj/vectorOps.o obj/matrixOps.o obj/arrayOps.o obj/testVmaOps.o
OPTIMTEST_OBJS = obj/arrayOpsOptim1.o obj/arrayOpsOptim2.o obj/optimMatMat.o
MEMTEST_OBJS = obj/vectorOps.o obj/matrixOps.o obj/arrayOps.o obj/checkMem.o

# All exectables
MATH_BIN = bin/testVmaOps bin/optimMatMat bin/checkMem

.PHONY: math-obj math-bin
math-obj: $(VMAOPS_OBJS) $(OPTIMTEST_OBJS)
math-bin: $(MATH_BIN)

# vmaOps Testing
bin/testVmaOps: ../support/obj/printOps.o $(VMAOPS_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

# Optimization Testing
bin/optimMatMat: ../support/obj/printOps.o $(OPTIMTEST_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

# Memory Testing
bin/checkMem: ../support/obj/printOps.o $(MEMTEST_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
