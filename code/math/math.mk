CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)
GTEST_INC = -I/usr/include/gtest/
GTEST_LINK = -pthread -lgtest

# All objects
VMAOPS_OBJS = obj/vectorOps.o obj/matrixOps.o obj/arrayOps.o
NUMERICALMETHODS_OBJS = obj/integration.o obj/differentiation.o
PRWOPS_OBJS = ../support/obj/printOps.o ../support/obj/readOps.o ../support/obj/writeOps.o

# All tests
VMAOPS_TEST = obj/testVmaOps.o
OPTIM_TEST = obj/arrayOpsOptim1.o obj/arrayOpsOptim2.o obj/optimMatMat.o
CHECKMEM_TEST = obj/checkMem.o
NUMERICALMETHODS_TEST = obj/testNumericalMethods.o

VMAOPS_UT = obj/vmaOps_ut.o

# All exectables
MATH_BIN = bin/testVmaOps bin/vmaOps_ut bin/optimMatMat bin/checkMem bin/testNumericalMethods

.PHONY: math-obj math-bin
math-obj: $(VMAOPS_OBJS) $(OPTIMTEST_OBJS) $(NUMERICALMETHODS_OBJS)
math-bin: $(MATH_BIN)

# vmaOps Testing (Will be replaced by unit test)
bin/testVmaOps: $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(VMAOPS_TEST)
			$(CC) $^ $(LFLAGS) -Lobj -o $@

bin/vmaOps_ut:  $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(VMAOPS_UT)
			$(CC) $^ $(LFLAGS) -Lobj $(GTEST_LINK) -o $@

# numericalMethods Testing
bin/testNumericalMethods: $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(NUMERICALMETHODS_OBJS) $(NUMERICALMETHODS_TEST)
			$(CC) $^ $(LFLAGS) -Lobj -o $@

# Optimization Testing
bin/optimMatMat: $(PRWOPS_OBJS) $(OPTIM_TEST)
			$(CC) $^ $(LFLAGS) -Lobj -o $@

# Memory Testing
bin/checkMem: $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(CHECKMEM_TEST)
			$(CC) $^ $(LFLAGS) -Lobj -o $@

obj/%.o: src/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: test/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: unitTest/%.cpp
			$(CC) $(CFLAGS) -Iinc $(GTEST_INC) -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
