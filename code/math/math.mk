CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

.PHONY: all
all: bin/testVmaOps bin/optimMatMat

bin/testVmaOps: obj/vectorOps.o ../support/obj/printOps.o obj/matrixOps.o obj/arrayOps.o obj/testVmaOps.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^

bin/optimMatMat: ../support/obj/printOps.o obj/arrayOpsOptim1.o obj/arrayOpsOptim2.o obj/optimMatMat.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
