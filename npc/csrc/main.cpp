#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vysyx_23060278_top.h"

/*memory*/
static const uint32_t img[] = {
	0b00000000010000000000000010010011,	//addi x1 x0 4
	0b00000000001100000000000100010011,	//addi x2 x0 3
	0b00000000001000000000000100010011,	//addi x2 x0 2
	0b00000000110100001000000100010011,	//addi x2 x1 13
	0b00000000000000000111001100110111	//lui  x6 7
	};

	uint32_t *init_mem(size_t size){
			uint32_t* memory = (uint32_t*)malloc(size * sizeof(uint32_t));
			memcpy(memory, img, sizeof(img));
			if(memory == NULL){exit(0);}
			return memory;
		};
	uint32_t guest_to_host(uint32_t addr){return addr - 0x80000000;}
	uint32_t pmem_read(uint32_t * memory, uint32_t vaddr){
		uint32_t paddr = guest_to_host(vaddr);
		return memory[paddr/4];
		}

VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vysyx_23060278_top* top;

void step_and_dump_wave(){
	contextp->timeInc(1);
	tfp -> dump(contextp->time());
	}
void sim_init(){
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

	sim_init();

	reset(10);

	for(int i = 0; i < 5; i++){
		top->inst = pmem_read(memory,top->pc);
		single_cycle();
		step_and_dump_wave();
		}
	sim_exit();
	}

