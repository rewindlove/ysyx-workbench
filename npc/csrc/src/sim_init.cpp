#include <common.h>
#include <memory/paddr.h>
#include <cpu/cpu.h>
#include <cpu/decode.h>
#include <cpu/ifetch.h>

#include "verilated.h"
#include "verilated_vcd_c.h"
#include "Vysyx_23060278_top.h"


VerilatedContext* contextp = NULL;
VerilatedVcdC* tfp = NULL;

static Vysyx_23060278_top* top;

void step_and_dump_wave(){
  top->eval();
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
  top->clk = 0;
	} 
void sim_exit(){
	step_and_dump_wave();
	tfp->close();
	}

void single_cycle(){
	top->clk = 0;top->eval();contextp->timeInc(10);
	top->clk = 1;top->eval();contextp->timeInc(10);
	}
static void reset(int n) {
	top->rst = 0;
	while (n -- > 0) single_cycle();
	top->rst = 1;
	}

extern "C" void npc_run_once(Decode *s){
    top->clk = !top->clk;   //产生上升沿
    top->inst = inst_fetch(&top->pc, 4);

    top->eval();
    contextp->timeInc(10);

    top->clk = !top->clk;  //产生下降沿
    top->eval();
    contextp->timeInc(10);

    s->snpc = top->snxt_pc;
    s->dnpc = top->dnxt_pc;
    s->pc   = top->pc;
}
