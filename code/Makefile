##--------------------------
## Filename: Makefile
## Created: 01/02/2018
## Last Modified: 01/02/2018
## Author: Kevin Gomez
##--------------------------

MODULES = math support

EDT_MATH_OBJS = math/obj/Array.o math/obj/Matrix.o math/obj/Vector.o math/obj/LongVector.o \
				math/obj/IntegratorTrapz.o math/obj/IntegratorSimps.o math/obj/IntegratorMidpoint.o\
				math/obj/Differentiator.o math/obj/NumericalMethods.o 
EDT_SUPPORT_OBJS = support/obj/PrintOps.o support/obj/ReadOps.o support/obj/WriteOps.o

.PHONY: all
all: edt-obj edt-bin

lib/libedt.a: $(EDT_MATH_OBJS) $(EDT_SUPPORT_OBJS)
	ar rcs $@ $(EDT_MATH_OBJS) $(EDT_SUPPORT_OBJS)	

.PHONY: edt-obj edt-bin
edt-obj:
	@$(foreach modDir,$(MODULES), $(MAKE) --no-print-directory -C $(modDir) obj -f $(modDir).mk;)
edt-bin: lib/libedt.a
	@$(foreach modDir,$(MODULES), $(MAKE) --no-print-directory -C $(modDir) bin -f $(modDir).mk;)

.PHONY: clean
clean: 
	rm -f */obj/*.o */bin/* lib/*
	rm -rf */obj */bin lib/

$(shell mkdir -p lib)
