CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bin/testVmaOps

bin/testVmaOps: obj/vectorOps.o ../support/obj/printOps.o obj/matrixOps.o obj/arrayOps.o obj/testVmaOps.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^
clean: 
			rm -f obj/*.o bin/*			
