CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# Build directories
OBJ_DIR = obj/
BIN_DIR = bin/
BUILD_DIRS = $(OBJ_DIR) $(BIN_DIR)

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
electronics-obj: $(BUILD_DIRS) $(LOGICGATES_OBJS) $(CIRCUITCOMPONENTS_OBJS)
electronics-bin: $(BUILD_DIRS) $(DIGITALLOGIC_BIN) $(CIRCUITCOMPONENTS_BIN)
		
bin/testDigitalLogic: $(LOGICGATES_OBJS) $(DIGITALLOGIC_TEST)
			$(CC) $(LFLAGS) -Lobj -o $@ $^

bin/testCircuitComponents: $(CIRCUITCOMPONENTS_OBJS) $(CIRCUITCOMPONENTS_TEST)
			$(CC) $(LFLAGS) -Lobj -o $@ $^
			
obj/%.o: */%.cpp
			$(CC) $(CFLAGS) -Iinc -c -o $@ $^

$(BUILD_DIRS): 
	mkdir -p $(OBJ_DIR)
	mkdir -p $(BIN_DIR)

.PHONY: clean
clean: 
			rm -f obj/*.o bin/*
			rm -rf obj/ bin/
