# Component Makefile
#
# (Uses default behaviour of compiling all source files in directory, adding 'include' to include path.)
$(call compile_only_if,$(CONFIG_MAGICSEE_R1_CONTROLLER),r1.o)
