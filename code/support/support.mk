##--------------------------
## Filename: support.mk
## Created: 01/03/2018
## Last Modified: 01/03/2018
## Author: Kevin Gomez
##--------------------------

CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -Wsign-compare -c $(DEBUG)
LFLAGS = -Wall -Wsign-compare $(DEBUG) $(PROFILE)
GTEST = -pthread -lgtest -lgmock
LAPACK = -llapacke -lcblas
GCOV = -fprofile-arcs -ftest-coverage

# Build directories
SUPPORT_DIRS = obj/ bin/

# All objects
SUPPORT_OBJS = obj/PrintOps.o obj/ReadOps.o obj/WriteOps.o

# All development tests
SUPPORT_DEVTEST_OBJS = obj/PrintOps_devTest.o obj/ReadOps_devTest.o obj/WriteOps_devTest.o 

# All unit tests
SUPPORT_UNITTEST_OBJS = obj/SupportUnitTest.o obj/PrintOps_unitTest.o obj/ReadOps_unitTest.o obj/WriteOps_unitTest.o 

# All development test exectables
SUPPORT_DEVTEST_BIN = bin/PrintOps_devTest bin/ReadOps_devTest bin/WriteOps_devTest

# All unit test exectables
SUPPORT_UNITTEST_BIN = bin/SupportUnitTest bin/PrintOps_unitTest bin/ReadOps_unitTest bin/WriteOps_unitTest

.PHONY: obj bin
obj: $(SUPPORT_OBJS) $(SUPPORT_DEVTEST_OBJS) $(SUPPORT_UNITTEST_OBJS)
bin: $(SUPPORT_DEVTEST_BIN) $(SUPPORT_UNITTEST_BIN)

# Development Testing
bin/%_devTest: obj/%_devTest.o ../lib/libedt.a
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK)

# Unit Testing (Support Classes)
bin/%_unitTest: obj/%_unitTest.o obj/SupportUnitTest.o ../lib/libedt.a
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST) $(GCOV)

# Unit Testing (Support Component)
bin/SupportUnitTest: $(SUPPORT_UNITTEST_OBJS) ../lib/libedt.a
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LAPACK) $(GTEST) $(GCOV)

obj/%.o: src/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: devTest/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: unitTest/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^ $(GCOV)

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
			rm -rf obj/ bin/

$(shell mkdir -p $(SUPPORT_DIRS))
