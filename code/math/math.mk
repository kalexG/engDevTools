CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# All objects
VMAOPS_OBJS = obj/vectorOps.o obj/matrixOps.o obj/arrayOps.o obj/testVmaOps.o
AOPSOPTIM_OBJ = obj/arrayOpsOptim1.o obj/arrayOpsOptim2.o obj/optimMatMat.o

# All exectables
MATH_BIN = bin/testVmaOps bin/optimMatMat 

.PHONY: math-obj math-bin
math-obj: $(VMAOPS_OBJS) $(AOPSOPTIM_OBJ)
math-bin: $(MATH_BIN)

bin/testVmaOps: ../support/obj/printOps.o $(VMAOPS_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

bin/optimMatMat: ../support/obj/printOps.o $(AOPSOPTIM_OBJ)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
