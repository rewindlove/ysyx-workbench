CC = gcc

# 目录以及文件
WORK_DIR = $(shell pwd)
BUILD_DIR = $(WORK_DIR)/build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default:$(BIN)

$(shell mkdir -p $(BUILD_DIR))

INC_PATH := $(WORK_DIR)/csrc/include $(WORK_DIR)/csrc/src/isa/include $(INC_PATH)
INCLuDES  = $(addprefix -I, $(INC_PATH))
CFLAGS   := -O2 -MMD -Wall -Og $(INCLuDES) $(CFLAGS)
CFLAGS   += -ggdb3 -g
LDFLAGS  += $(shell sdl2-config --libs) -lSDL2_image
LDFLAGS  += -O2 -Og -ggdb3 -ldl -pie -lreadline

VSRCS = $(shell find $(abspath ./vsrc) -name "*.v" -or -name "*.sv")
CSRCS = $(shell find $(abspath ./csrc) -name *.cpp -or -name "*.cc" -or -name "*.c")

TOPNAME = ysyx_23060278_top

VERILATOR_FLAGS += $(addprefix -LDFLAGS , $(LDFLAGS))
VERILATOR_FLAGS += $(addprefix -CFLAGS , $(CFLAGS))
VERILATOR = verilator
VERILATOR_FLAGS +=-Wall --cc --trace
VERILATOR_FLAGS += -Wno-UNDRIVEN
VERILATOR_FLAGS += -O3 --x-assign fast --x-initial fast --noassert
VERILATOR_FLAGS += -MMD --build 
#VERILATOR_FLAGS += -j$(shell nproc)	#多核心编译

IMG ?= 

ARGS_DIFF ?= --diff=$(NEMU_HOME)/build/riscv32-nemu-interpreter
ARGS_LOG ?= --log=$(BUILD_DIR)/npc-log.txt
NPC_ARGS += $(ARGS_LOG) $(ARGS_DIFF)
NPC_ARGS += $(IMG)

$(BIN):$(VSRCS) $(CPPSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_FLAGS) \
		--top-module $(TOPNAME) $^ \
		--Mdir $(OBJ_DIR) --exe -o $(abspath $(BIN))


all:default

sim:$(BIN)
	$(call git_commit, "sim RTL") #DO NOT REMOVE THIS LINE!!!
	@$^ $(NPC_ARGS)

run:sim
	$(call git_commit, "run NPC") #DO NOT REMOVE THIS LINE!!!

wave:sim
	gtkwave $(BUILD_DIR)/dump.vcd

gdb:$(BIN)
	@gdb -args $(BIN) $(NPC_ARGS)


clean:
	rm -rf $(BUILD_DIR)

.PHONY: default all sim wave run clean

include 
