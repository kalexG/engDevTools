CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# All objects
LOGICGATES_OBJS = obj/digitalLogic.o

# All tests
DIGITALLOGIC_TEST = obj/testDigitalLogic.o

# All executables
DIGITALLOGIC_BIN = bin/testDigitalLogic

.PHONY: electronics-obj electronics-bin
electronics-obj: $(LOGICGATES_OBJS)
electronics-bin: $(DIGITALLOGIC_BIN)
		
bin/testDigitalLogic: $(LOGICGATES_OBJS) $(DIGITALLOGIC_TEST)
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*			
