CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)
GTEST = -pthread -lgtest
LAPACK = -llapack -llapacke

# Build directories
OBJ_DIR = obj/
BIN_DIR = bin/
BUILD_DIRS = $(OBJ_DIR) $(BIN_DIR)

# All objects
MATH_OBJS = obj/Array.o obj/Integrator.o obj/Differentiator.o

# All development tests
MATH_DEVTEST_OBJS = obj/testArray.o obj/testIntegrator.o obj/testDifferentiator.o

# All unit tests
MATH_UNITTEST_OBJS = obj/Array_ut.o

# All development test exectables
MATH_DEVTEST_BIN = bin/testArray bin/testIntegrator bin/testDifferentiator

# All development test exectables
MATH_UNITTEST_BIN = bin/Array_ut

.PHONY: math-obj math-bin
math-obj: $(BUILD_DIRS) $(MATH_OBJS) $(MATH_DEVTEST_OBJS) $(MATH_UNITTEST_OBJS)
math-bin: $(BUILD_DIRS) $(MATH_DEVTEST_BIN) $(MATH_UNITTEST_BIN)

# Development Testing
bin/test%: obj/test%.o obj/%.o
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK)

# Unit Testing
bin/%_ut: obj/%_ut.o obj/%.o
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST)

obj/%.o: src/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: test/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: unitTest/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

$(BUILD_DIRS): 
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
			rm -rf obj/ bin/
