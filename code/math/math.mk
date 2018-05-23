CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bin/testMvOps

bin/testMvOps: obj/vectorOps.o obj/matrixOps.o obj/arrayOps.o obj/testMvOps.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^
clean: 
			rm -f obj/*.o bin/*			
