CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# All objects
ASTRODYNAMICS_OBJS = obj/astrodynamics.o obj/testAstrodynamics.o

# All executables
ASTRODYNAMICS_BIN = bin/testAstrodynamics

.PHONY: astrodynamics-obj astrodynamics-bin
astrodynamics-obj: $(ASTRODYNAMICS_OBJS)
astrodynamics-bin: $(ASTRODYNAMICS_BIN)
		
bin/testAstrodynamics: $(ASTRODYNAMICS_OBJS)
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*			
