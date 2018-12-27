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
MATH_OBJS = obj/Array.o obj/Integrator.o obj/Differentiator.o

# All tests
MATH_TEST_OBJS = obj/testArray.o obj/testIntegrator.o obj/testDifferentiator.o

# All exectables
MATH_TEST_BIN = bin/testArray bin/testIntegrator bin/testDifferentiator

.PHONY: math-obj math-bin
math-obj: $(BUILD_DIRS) $(MATH_OBJS) $(MATH_TEST_OBJS)
math-bin: $(BUILD_DIRS) $(MATH_TEST_BIN)

# Development Testing
bin/test%: obj/test%.o obj/%.o
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc

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
