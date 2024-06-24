-include $(NPC_HOME)/../Makefile
include $(NPC_HOME)/scripts/build.mk

#include $(NPC_HOME)/tools/difftest.mk

compile_git:
	$(call git_commit, "compile NEMU in NPC")
$(BINARY): compile_git

# Some convenient rules

override ARGS ?= --log=$(BUILD_DIR)/npc-log.txt
override ARGS += $(ARGS_DIFF)

# Command to execute NPC
IMG ?=
NPC_EXEC := $(BINARY) $(ARGS) $(IMG)

run-env: $(BINARY) $(DIFF_REF_SO)
	$(call git_commit, "run NEMU in NPC")
	$(NPC_EXEC)

gdb: run-env
	$(call git_commit, "gdb NEMU in NPC")
	gdb -s $(BINARY) --args $(NPC_EXEC)

clean-tools = $(dir $(shell find ./tools -maxdepth 2 -mindepth 2 -name "Makefile"))
$(clean-tools):
	-@$(MAKE) -s -C $@ clean
clean-tools: $(clean-tools)
clean-all: clean distclean clean-tools

.PHONY: run gdb run-env clean-tools clean-all $(clean-tools)
