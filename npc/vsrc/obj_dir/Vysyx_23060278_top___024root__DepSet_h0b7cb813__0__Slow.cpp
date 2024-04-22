// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vysyx_23060278_top.h for the primary calling header

#include "verilated.h"

#include "Vysyx_23060278_top___024root.h"

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_static(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___eval_static\n"); );
}

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_initial__TOP(Vysyx_23060278_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_initial(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___eval_initial\n"); );
    // Body
    Vysyx_23060278_top___024root___eval_initial__TOP(vlSelf);
    vlSelf->__Vtrigrprev__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_initial__TOP(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___eval_initial__TOP\n"); );
    // Body
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list[0U] = 3U;
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list[1U] = 2U;
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list[2U] = 1U;
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list[3U] = 0U;
}

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_final(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___eval_final\n"); );
}

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_triggers__stl(Vysyx_23060278_top___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060278_top___024root___dump_triggers__stl(Vysyx_23060278_top___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_stl(Vysyx_23060278_top___024root* vlSelf);

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_settle(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___eval_settle\n"); );
    // Init
    CData/*0:0*/ __VstlContinue;
    // Body
    vlSelf->__VstlIterCount = 0U;
    __VstlContinue = 1U;
    while (__VstlContinue) {
        __VstlContinue = 0U;
        Vysyx_23060278_top___024root___eval_triggers__stl(vlSelf);
        if (vlSelf->__VstlTriggered.any()) {
            __VstlContinue = 1U;
            if (VL_UNLIKELY((0x64U < vlSelf->__VstlIterCount))) {
#ifdef VL_DEBUG
                Vysyx_23060278_top___024root___dump_triggers__stl(vlSelf);
#endif
                VL_FATAL_MT("ysyx_23060278_top.v", 1, "", "Settle region did not converge.");
            }
            vlSelf->__VstlIterCount = ((IData)(1U) 
                                       + vlSelf->__VstlIterCount);
            Vysyx_23060278_top___024root___eval_stl(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060278_top___024root___dump_triggers__stl(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VstlTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VstlTriggered.at(0U)) {
        VL_DBG_MSGF("         'stl' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060278_top___024root___stl_sequent__TOP__0(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___stl_sequent__TOP__0\n"); );
    // Init
    IData/*31:0*/ ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out;
    ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out = 0;
    IData/*31:0*/ __VdfgTmp_h04f965f7__0;
    __VdfgTmp_h04f965f7__0 = 0;
    // Body
    vlSelf->dnxt_pc = ((IData)(4U) + vlSelf->pc);
    vlSelf->ysyx_23060278_top__DOT__imm = (((0x67U 
                                             == (0x7fU 
                                                 & vlSelf->inst)) 
                                            | ((3U 
                                                == 
                                                (0x7fU 
                                                 & vlSelf->inst)) 
                                               | ((0x13U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->inst)) 
                                                  | (0x1bU 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->inst)))))
                                            ? (((- (IData)(
                                                           (vlSelf->inst 
                                                            >> 0x1fU))) 
                                                << 0xcU) 
                                               | (vlSelf->inst 
                                                  >> 0x14U))
                                            : (((0x37U 
                                                 == 
                                                 (0x7fU 
                                                  & vlSelf->inst)) 
                                                | (0x17U 
                                                   == 
                                                   (0x7fU 
                                                    & vlSelf->inst)))
                                                ? (0xfffff000U 
                                                   & vlSelf->inst)
                                                : (
                                                   (0x63U 
                                                    == 
                                                    (0x7fU 
                                                     & vlSelf->inst))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->inst 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0x800U 
                                                        & (vlSelf->inst 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlSelf->inst 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelf->inst 
                                                                >> 7U)))))
                                                    : 
                                                   ((0x6fU 
                                                     == 
                                                     (0x7fU 
                                                      & vlSelf->inst))
                                                     ? 
                                                    (((- (IData)(
                                                                 (vlSelf->inst 
                                                                  >> 0x1fU))) 
                                                      << 0x14U) 
                                                     | ((0xff000U 
                                                         & vlSelf->inst) 
                                                        | ((0x800U 
                                                            & (vlSelf->inst 
                                                               >> 9U)) 
                                                           | (0x7feU 
                                                              & (vlSelf->inst 
                                                                 >> 0x14U)))))
                                                     : 
                                                    ((0x23U 
                                                      == 
                                                      (0x7fU 
                                                       & vlSelf->inst))
                                                      ? 
                                                     (((- (IData)(
                                                                  (vlSelf->inst 
                                                                   >> 0x1fU))) 
                                                       << 0xcU) 
                                                      | ((0xfe0U 
                                                          & (vlSelf->inst 
                                                             >> 0x14U)) 
                                                         | (0x1fU 
                                                            & (vlSelf->inst 
                                                               >> 7U))))
                                                      : 0U)))));
    __VdfgTmp_h04f965f7__0 = vlSelf->ysyx_23060278_top__DOT__gpr__DOT__regs
        [(0x1fU & (vlSelf->inst >> 0xfU))];
    vlSelf->snxt_pc = vlSelf->dnxt_pc;
    vlSelf->ysyx_23060278_top__DOT__rd_data1 = ((0U 
                                                 == 
                                                 (0x1fU 
                                                  & (vlSelf->inst 
                                                     >> 0xfU)))
                                                 ? 0U
                                                 : __VdfgTmp_h04f965f7__0);
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list[0U] 
        = (vlSelf->ysyx_23060278_top__DOT__rd_data1 
           | vlSelf->ysyx_23060278_top__DOT__imm);
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list[1U] 
        = (vlSelf->ysyx_23060278_top__DOT__rd_data1 
           & vlSelf->ysyx_23060278_top__DOT__imm);
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list[2U] 
        = (vlSelf->ysyx_23060278_top__DOT__rd_data1 
           + vlSelf->ysyx_23060278_top__DOT__imm);
    vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list[3U] 
        = (vlSelf->ysyx_23060278_top__DOT__rd_data1 
           + vlSelf->ysyx_23060278_top__DOT__imm);
    ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
        = ((- (IData)((0U == vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list
                       [0U]))) & vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list
           [0U]);
    ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
        = (ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list
                          [1U]))) & vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list
              [1U]));
    ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
        = (ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list
                          [2U]))) & vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list
              [2U]));
    ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
        = (ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out 
           | ((- (IData)((0U == vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list
                          [3U]))) & vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list
              [3U]));
    vlSelf->result = ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__lut_out;
}

VL_ATTR_COLD void Vysyx_23060278_top___024root___eval_stl(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___eval_stl\n"); );
    // Body
    if (vlSelf->__VstlTriggered.at(0U)) {
        Vysyx_23060278_top___024root___stl_sequent__TOP__0(vlSelf);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060278_top___024root___dump_triggers__ico(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VicoTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VicoTriggered.at(0U)) {
        VL_DBG_MSGF("         'ico' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060278_top___024root___dump_triggers__act(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VactTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VactTriggered.at(0U)) {
        VL_DBG_MSGF("         'act' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

#ifdef VL_DEBUG
VL_ATTR_COLD void Vysyx_23060278_top___024root___dump_triggers__nba(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___dump_triggers__nba\n"); );
    // Body
    if ((1U & (~ (IData)(vlSelf->__VnbaTriggered.any())))) {
        VL_DBG_MSGF("         No triggers active\n");
    }
    if (vlSelf->__VnbaTriggered.at(0U)) {
        VL_DBG_MSGF("         'nba' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vysyx_23060278_top___024root___ctor_var_reset(Vysyx_23060278_top___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vysyx_23060278_top__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vysyx_23060278_top___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->inst = VL_RAND_RESET_I(32);
    vlSelf->pc_wen = VL_RAND_RESET_I(1);
    vlSelf->result = VL_RAND_RESET_I(32);
    vlSelf->dnxt_pc = VL_RAND_RESET_I(32);
    vlSelf->snxt_pc = VL_RAND_RESET_I(32);
    vlSelf->pc = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060278_top__DOT__imm = VL_RAND_RESET_I(32);
    vlSelf->ysyx_23060278_top__DOT__rd_data1 = VL_RAND_RESET_I(32);
    for (int __Vi0 = 0; __Vi0 < 32; ++__Vi0) {
        vlSelf->ysyx_23060278_top__DOT__gpr__DOT__regs[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__key_list[__Vi0] = VL_RAND_RESET_I(3);
    }
    for (int __Vi0 = 0; __Vi0 < 4; ++__Vi0) {
        vlSelf->ysyx_23060278_top__DOT__alu__DOT__alumux__DOT__i0__DOT__data_list[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->__Vtrigrprev__TOP__clk = VL_RAND_RESET_I(1);
}
