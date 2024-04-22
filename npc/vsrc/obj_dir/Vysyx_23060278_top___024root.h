// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vysyx_23060278_top.h for the primary calling header

#ifndef VERILATED_VYSYX_23060278_TOP___024ROOT_H_
#define VERILATED_VYSYX_23060278_TOP___024ROOT_H_  // guard

#include "verilated.h"

class Vysyx_23060278_top__Syms;

class Vysyx_23060278_top___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(pc_wen,0,0);
    CData/*0:0*/ __Vtrigrprev__TOP__clk;
    CData/*0:0*/ __VactContinue;
    VL_IN(inst,31,0);
    VL_OUT(result,31,0);
    VL_OUT(dnxt_pc,31,0);
    VL_OUT(snxt_pc,31,0);
    VL_OUT(pc,31,0);
    IData/*31:0*/ ysyx_23060278_top__DOT__imm;
    IData/*31:0*/ ysyx_23060278_top__DOT__rd_data1;
    IData/*31:0*/ __VstlIterCount;
    IData/*31:0*/ __VicoIterCount;
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<IData/*31:0*/, 32> ysyx_23060278_top__DOT__gpr__DOT__regs;
    VlUnpacked<CData/*2:0*/, 4> ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list;
    VlUnpacked<IData/*31:0*/, 4> ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<1> __VicoTriggered;
    VlTriggerVec<1> __VactTriggered;
    VlTriggerVec<1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vysyx_23060278_top__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vysyx_23060278_top___024root(Vysyx_23060278_top__Syms* symsp, const char* v__name);
    ~Vysyx_23060278_top___024root();
    VL_UNCOPYABLE(Vysyx_23060278_top___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
