all:
	@echo "Write this Makefile by your self."
#MKFILE=obj_dir/Vtop.mk
#NAME=Vtop
VERILATOR=verilator 
#VSRCS = $(shell find $(abspath ./vsrc) -name "*.v")
#CSRCS = $(shell find $(abspath ./csrc) -name "*.c" -or -name "*.cc" -or -name "*.cpp")
  
sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) --trace -cc --exe --build -j vsrc/top.v csrc/main.cpp
wave: sim
	./obj_dir/Vtop
	gtkwave dump.vcd
 
clean:
	rm -rf obj_dir
	rm dump.vcd
 
 
 
include ../Makefile
