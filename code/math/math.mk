CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bin/testVectorOps bin/testMatrixOps
		
bin/testVectorOps: obj/vectorOps.o obj/testVectorOps.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^

bin/testMatrixOps: obj/matrixOps.o obj/testMatrixOps.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^
clean: 
			rm -f obj/*.o bin/*			
