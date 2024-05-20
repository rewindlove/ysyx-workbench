include $(AM_HOME)/scripts/isa/riscv32e.mk
include $(AM_HOME)/scripts/platform/npc.mk
CFLAGS += -DISA_H=\"riscv/riscv.h\"

AM_SRCS += riscv/npc/start.S
					 riscv/npc/cte.c
					 riscv/npc/trap.S
					 riscv/npc/vme.c
