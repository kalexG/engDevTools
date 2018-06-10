CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# All objects
ELECTRONICS_OBJS = obj/circuitC.o obj/digitalLogic.o

# All tests
ELECTRONICS_TEST = obj/testElectronics.o

# All executables
ELECTRONICS_BIN = bin/testElectronics

.PHONY: electronics-obj electronics-bin
electronics-obj: $(ELECTRONICS_OBJS)
electronics-bin: $(ELECTRONICS_BIN)
		
bin/testElectronics: $(ELECTRONICS_OBJS) $(ELECTRONICS_TEST)
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*			
