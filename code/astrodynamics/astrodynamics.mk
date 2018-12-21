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
ASTRODYNAMICS_OBJS = obj/astrodynamics.o obj/testAstrodynamics.o

# All executables
ASTRODYNAMICS_BIN = bin/testAstrodynamics

.PHONY: astrodynamics-obj astrodynamics-bin
astrodynamics-obj: $(BUILD_DIRS) $(ASTRODYNAMICS_OBJS)
astrodynamics-bin: $(BUILD_DIRS) $(ASTRODYNAMICS_BIN)
		
bin/testAstrodynamics: $(ASTRODYNAMICS_OBJS)
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
