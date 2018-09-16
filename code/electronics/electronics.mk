CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# All objects
LOGICGATES_OBJS = obj/digitalLogic.o
CIRCUITCOMPONENTS_OBJS = obj/circuitComponents.o

# All tests
DIGITALLOGIC_TEST = obj/testDigitalLogic.o
CIRCUITCOMPONENTS_TEST = obj/testCircuitComponents.o

# All executables
DIGITALLOGIC_BIN = bin/testDigitalLogic
CIRCUITCOMPONENTS_BIN = bin/testCircuitComponents

.PHONY: electronics-obj electronics-bin
electronics-obj: $(LOGICGATES_OBJS) $(CIRCUITCOMPONENTS_OBJS)
electronics-bin: $(DIGITALLOGIC_BIN) $(CIRCUITCOMPONENTS_BIN)
		
bin/testDigitalLogic: $(LOGICGATES_OBJS) $(DIGITALLOGIC_TEST)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

bin/testCircuitComponents: $(CIRCUITCOMPONENTS_OBJS) $(CIRCUITCOMPONENTS_TEST)
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*			
