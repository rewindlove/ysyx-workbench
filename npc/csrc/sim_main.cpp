#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vysyx_23060278_top.h"


VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vysyx_23060278_top* top;

void step_and_dump_wave(){
	contextp->timeInc(1);
	tfp -> dump(contextp->time());
	}
void init_sim(){
	contextp = new VerilatedContext;
	tfp = new VerilatedVcdC;
	top = new Vysyx_23060278_top;
	contextp->traceEverOn(true);
	top->trace(tfp, 0);
	tfp->open("dump.vcd");
	} 
void sim_exit(){
	step_and_dump_wave();
	tfp->close();
	}

void single_cycle(){
	top->clk = 0;top->eval();
	top->clk = 1;top->eval();
	}
static void reset(int n) {
	top->rst = 1;
	while (n -- > 0) single_cycle();
	top->rst = 0;
	}

int main(){
	uint32_t *memory;
	memory = init_mem(3);

	init_sim();

	reset(10);

	for(int i = 0; i < 5; i++){
		top->inst = pmem_read(memory,top->pc);
		single_cycle();
		step_and_dump_wave();
		}
	sim_exit();
	}

