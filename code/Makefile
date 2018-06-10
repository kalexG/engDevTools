CC = g++
DEBUG = -g
PROFILE = -pg
CFLAGS = -Wall -c $(DEBUG) $(addprefix -I,$(INCLUDE))
LFLAGS = -Wall $(DEBUG) $(PROFILE)

MODULES = math astrodynamics support electronics
SRC_DIR = $(addsuffix /src,$(MODULES))
OBJ_DIR = $(addsuffix /obj,$(MODULES))
INC_DIR = $(addsuffix /inc,$(MODULES))
MK_FILES = $(addsuffix /*.mk,$(MODULES))

.PHONY: all
all:
			@echo "Preparing to execute the following .mk files:"
			@echo $(MK_FILES)
			@$(foreach modDir,$(MODULES), $(MAKE) --no-print-directory -C $(modDir) $(modDir)-obj -f $(modDir).mk;)
			@$(foreach modDir,$(MODULES), $(MAKE) --no-print-directory -C $(modDir) $(modDir)-bin -f $(modDir).mk;)

.PHONY: clean
clean: 
			rm -f */obj/*.o */bin/*
