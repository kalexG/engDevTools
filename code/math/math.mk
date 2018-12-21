CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)
GTEST_INC = -I/usr/include/gtest/
GTEST_LINK = -pthread -lgtest

# Build directories
OBJ_DIR = obj/
BIN_DIR = bin/
BUILD_DIRS = $(OBJ_DIR) $(BIN_DIR)

# All objects
VMAOPS_OBJS = obj/vectorOps.o obj/matrixOps.o obj/arrayOps.o
NUMERICALMETHODS_OBJS = obj/integration.o obj/differentiation.o
PRWOPS_OBJS = ../support/obj/printOps.o ../support/obj/readOps.o ../support/obj/writeOps.o

# All tests
VMAOPS_TEST = obj/testVmaOps.o
CHECKMEM_TEST = obj/checkMem.o
NUMERICALMETHODS_TEST = obj/testNumericalMethods.o

VMAOPS_UT = obj/vectorOps_ut.o

# All exectables
MATH_BIN = bin/testVmaOps bin/vmaOps_ut bin/checkMem bin/testNumericalMethods

.PHONY: math-obj math-bin
math-obj: $(BUILD_DIRS) $(VMAOPS_OBJS) $(OPTIMTEST_OBJS) $(NUMERICALMETHODS_OBJS)
math-bin: $(BUILD_DIRS) $(MATH_BIN)

# vmaOps Testing (Will be replaced by unit test)
bin/testVmaOps: $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(VMAOPS_TEST)
			$(CC) $^ $(LFLAGS) -Lobj -o $@

bin/vmaOps_ut:  $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(VMAOPS_UT)
			$(CC) $^ $(LFLAGS) -Lobj $(GTEST_LINK) -o $@

# numericalMethods Testing
bin/testNumericalMethods: $(PRWOPS_OBJS) $(VMAOPS_OBJS) $(NUMERICALMETHODS_OBJS) $(NUMERICALMETHODS_TEST)
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

$(BUILD_DIRS): 
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
			rm -rf obj/ bin/
