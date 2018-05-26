CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bin/testSupportOps

bin/testSupportOps: obj/printOps.o obj/testSupportOps.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^

obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^
clean: 
			rm -f obj/*.o bin/*			
