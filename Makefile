CC = g++
CFLAGS = -c -Wall -O2 -fPIC
LFLAGS = -Wall 
DEBUG = -O0 -D _DEBUG -g
PROFILE = -pg
GCOV = -fprofile-arcs -ftest-coverage
OPTIM = -O3 -DNDEBUG -DBOOST_UBLAS_NDEBUG
# GTEST/GMOCK
LFLAGS_GTEST = -pthread -lgtest -lgmock
INC_GTEST = -isystem /usr/local/include/gtest/ -isystem /usr/local/include/gmock/
# LAPACKE/CBLAS
LFLAGS_LAPACK = -llapacke -lcblas
# QT
CFLAGS_QT = -c -pipe -O2 -Wall -W -D_REENTRANT -fPIC -DQT_DEPRECATED_WARNINGS -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
LFLAGS_QT = -lQt5Gui -lQt5Core -lGL -lQt5Widgets -lpthread
INC_QT = -isystem /usr/include/x86_64-linux-gnu/qt5/ -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets/

# Build directories
DIRS = obj/ bin/ lib/

# All libraries
EDT_LIBS = lib/libedt.so

# All objects
EDT_OBJS =  obj/NumericalMethodsUtilities.o \
			obj/ArrayUtilities.o

# All UI objects
EDT_UI_OBJS =  obj/EDT_UI.o \

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

# All UI exectables
EDT_UI_BIN = bin/edt_ui \

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
obj: $(EDT_OBJS) $(EDT_UI_OBJS) $(EDT_DEVTEST_OBJS) $(EDT_UNITTEST_OBJS)
lib: $(EDT_LIBS)
bin: $(EDT_UI_BIN) $(EDT_DEVTEST_BIN) $(EDT_UNITTEST_BIN)

lib/libedt.so: $(EDT_OBJS)
    # Build library 
	$(CC) -shared -o $@ $(EDT_OBJS) 

# EDT UI
bin/edt_ui: $(EDT_UI_OBJS)
			$(CC) $^ $(LFLAGS_QT) -Lobj -o $@ -Iinc

# Development Testing
bin/%_devTest: obj/%_devTest.o $(EDT_LIBS)
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LFLAGS_LAPACK)

# Unit Testing (Individual)
bin/%_unitTest: obj/%_unitTest.o obj/EDTUnitTest.o $(EDT_LIBS)
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LFLAGS_LAPACK) $(LFLAGS_GTEST)

# Unit Testing (All)
bin/EDTUnitTest: $(EDT_UNITTEST_OBJS) $(EDT_LIBS)
			$(CC) $^ $(LFLAGS) -Lobj -o $@ -Iinc $(LFLAGS_LAPACK) $(LFLAGS_GTEST)

obj/%.o: src/%.cpp
			$(CC) $(CFLAGS) -Iinc -o $@ $^

obj/%.o: devTest/%.cpp
			$(CC) $(CFLAGS) $(OPTIM) -Iinc -o $@ $^

obj/%.o: unitTest/%.cpp
			$(CC) $(CFLAGS) -Iinc $(INC_GTEST) -o $@ $^

obj/%.o: ui/%.cpp
			$(CC) $(CFLAGS_QT) -Iinc $(INC_QT) -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/* lib/*
			rm -rf obj/ bin/ lib/

$(shell mkdir -p $(DIRS))