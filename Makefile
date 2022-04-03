CC = g++
CFLAGS = -Wall -Wsign-compare -c
LFLAGS = -Wall -Wsign-compare
DEBUG = -O0 -D _DEBUG -g
PROFILE = -pg
GTEST = -pthread -lgtest -lgmock
LAPACK = -llapacke -lcblas
GCOV = -fprofile-arcs -ftest-coverage
OPTIM = -O3 -DNDEBUG -DBOOST_UBLAS_NDEBUG

# Build directories
DIRS = obj/ bin/ lib/

# All libraries
EDT_LIBS = #lib/libedt.so

# All objects
EDT_OBJS =

# All development tests
EDT_DEVTEST_OBJS = obj/Array_devTest.o \
				   obj/Array_Setters_devTest.o \
				   obj/BoostCompare_devTest.o \
				   obj/NumericalMethods_devTest.o \

# All unit tests
EDT_UNITTEST_OBJS = obj/EDTUnitTest.o \
					obj/Array_unitTest.o \
					obj/Matrix_unitTest.o \
					obj/Vector_unitTest.o \
					obj/NumericalMethods_unitTest.o \

# All development test exectables
EDT_DEVTEST_BIN = bin/Array_devTest \
				  bin/Array_Setters_devTest \
				  bin/BoostCompare_devTest \
				  bin/NumericalMethods_devTest \

# All unit test exectables
EDT_UNITTEST_BIN = bin/EDTUnitTest \
				   bin/Array_unitTest \
				   bin/Matrix_unitTest \
				   bin/Vector_unitTest \
				   bin/NumericalMethods_unitTest \

.PHONY: all
all: obj lib bin

.PHONY: obj lib bin
obj: $(EDT_OBJS) $(EDT_DEVTEST_OBJS) $(EDT_UNITTEST_OBJS)
lib: $(EDT_LIBS)
bin: $(EDT_DEVTEST_BIN) $(EDT_UNITTEST_BIN)

lib/libedt.so: $(EDT_OBJS)
    # Build library 
	$(CC) -shared -o $@ $(EDT_OBJS) 

# Development Testing
bin/%_devTest: obj/%_devTest.o $(EDT_LIBS)
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK)

# Unit Testing (Individual)
bin/%_unitTest: obj/%_unitTest.o obj/EDTUnitTest.o $(EDT_LIBS)
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST)

# Unit Testing (All)
bin/EDTUnitTest: $(EDT_UNITTEST_OBJS) $(EDT_LIBS)
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST)

obj/%.o: src/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: devTest/%.cpp
			$(CC) $(CFLAGS) $(OPTIM) -Iinc -o $@ $^

obj/%.o: unitTest/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/* lib/*
			rm -rf obj/ bin/ lib/

$(shell mkdir -p $(DIRS))