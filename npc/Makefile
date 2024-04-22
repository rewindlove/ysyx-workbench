VSRCS = $(wildcard ./vsrc/*.v)
CSRCS = $(wildcard ./csrc/*.cpp)

TOPNAME = ysyx_23060278_top

VERILATOR = verilator
VERILATOR_FLAGS += --cc --exe --trace --build
VERILATOR_FLAGS += --top-module $(TOPNAME)

all:
	@echo "Write this Makefile by your self."


sim:
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	$(VERILATOR) $(VERILATOR_FLAGS) $(CSRCS) $(VSRCS)

wave:sim
	./obj_dir/Vysyx_23060278_top
	gtkwave dump.vcd

clean:
	rm -rf obj_dir/
	rm -rf dump.vcd
