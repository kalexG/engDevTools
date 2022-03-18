##--------------------------
## Filename: Makefile
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

MODULES = math

EDT_MATH_OBJS = math/obj/Array.o \
				math/obj/Matrix.o \
				math/obj/Vector.o \
				math/obj/LongVector.o \
				math/obj/IntegratorTrapz.o \
				math/obj/IntegratorSimps.o \
				math/obj/IntegratorMidpoint.o\
				math/obj/Differentiator.o

.PHONY: all
all: edt-bin

lib/libedt.a:
    # Build all required objects
	@$(foreach modDir,$(MODULES), $(MAKE) --no-print-directory -C $(modDir) obj -f $(modDir).mk;)
    # Build library 
	ar rcs $@ $(EDT_MATH_OBJS) $(EDT_SUPPORT_OBJS)	

.PHONY: edt-bin
edt-bin: lib/libedt.a
	@$(foreach modDir,$(MODULES), $(MAKE) --no-print-directory -C $(modDir) bin -f $(modDir).mk;)

.PHONY: clean
clean: 
	rm -f */obj/*.o */bin/* lib/*
	rm -rf */obj */bin lib/

$(shell mkdir -p lib)
