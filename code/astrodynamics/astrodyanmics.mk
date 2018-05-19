CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: bin/testAstrodynamics
		
bin/testAstrodynamics: obj/astrodynamics.o obj/testAstrodynamics.o
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^
clean: 
			rm -f obj/*.o bin/*			
