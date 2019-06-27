##--------------------------
## Filename: math.mk
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -Wsign-compare -c $(DEBUG)
LFLAGS = -Wall -Wsign-compare $(DEBUG) $(PROFILE)
GTEST = -pthread -lgtest -lgmock
LAPACK = -llapacke -lblas

# Build directories
MATH_DIRS = obj/ bin/

# All objects
MATH_OBJS = obj/Array.o obj/Matrix.o obj/Vector.o obj/LongVector.o \
			obj/IntegratorTrapz.o obj/IntegratorSimps.o obj/IntegratorMidpoint.o \
			obj/Differentiator.o

# All development tests
MATH_DEVTEST_OBJS = obj/Array_devTest.o obj/Integrator_devTest.o obj/Differentiator_devTest.o

# All unit tests
MATH_UNITTEST_OBJS = obj/MathUnitTest.o obj/Array_unitTest.o obj/Matrix_unitTest.o obj/Vector_unitTest.o

# All development test exectables
MATH_DEVTEST_BIN = bin/Array_devTest bin/Integrator_devTest bin/Differentiator_devTest

# All unit test exectables
MATH_UNITTEST_BIN = bin/MathUnitTest \
					bin/Array_unitTest bin/Matrix_unitTest bin/Vector_unitTest \
					bin/IntegratorTrapz_unitTest 

.PHONY: math-obj math-bin
math-obj: $(MATH_OBJS) $(MATH_DEVTEST_OBJS) $(MATH_UNITTEST_OBJS)
math-bin: $(MATH_DEVTEST_BIN) $(MATH_UNITTEST_BIN)

# Development Testing
bin/%_devTest: obj/%_devTest.o ../lib/libedt.a
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK)

# Unit Testing (Math Classes)
bin/%_unitTest: obj/%_unitTest.o obj/MathUnitTest.o ../lib/libedt.a
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST) 

# Unit Testing (Math Component)
bin/MathUnitTest: $(MATH_UNITTEST_OBJS) ../lib/libedt.a
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST) 

obj/%.o: src/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: devTest/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: unitTest/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

.PHONY: math-clean
math-clean: 
			rm -f obj/*.o bin/*
			rm -rf obj/ bin/

$(shell mkdir -p $(MATH_DIRS))
