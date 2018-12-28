CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG) $(PROFILE)

# Build directories
OBJ_DIR = obj/
BIN_DIR = bin/
BUILD_DIRS = $(OBJ_DIR) $(BIN_DIR)

# Objects you need from other modules
MATH_DIR = ../math/
VMAOPS_OBJS = $(MATH_DIR)obj/vectorOps.o $(MATH_DIR)obj/matrixOps.o $(MATH_DIR)obj/arrayOps.o

# All objects
PRWOPS_OBJS = obj/printOps.o obj/writeOps.o obj/readOps.o #obj/testPrwOps.o

# All executables
# Not compiled for now. Removing vmaOps broke this
SUPPORT_BIN = #bin/testPrwOps

.PHONY: support-obj support-bin
support-obj: $(BUILD_DIRS) $(PRWOPS_OBJS)
support-bin: $(BUILD_DIRS) $(SUPPORT_BIN)

bin/testPrwOps: $(PRWOPS_OBJS) $(VMAOPS_OBJS)
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
