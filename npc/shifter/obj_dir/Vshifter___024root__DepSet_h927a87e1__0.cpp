// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vshifter.h for the primary calling header

#include "verilated.h"

#include "Vshifter___024root.h"

void Vshifter___024root___eval_act(Vshifter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vshifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter___024root___eval_act\n"); );
}

VL_INLINE_OPT void Vshifter___024root___nba_sequent__TOP__0(Vshifter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vshifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter___024root___nba_sequent__TOP__0\n"); );
    // Init
    CData/*3:0*/ __Vdly__shifter__DOT__cnt;
    __Vdly__shifter__DOT__cnt = 0;
    CData/*7:0*/ __Vdly__shifter__DOT__dt;
    __Vdly__shifter__DOT__dt = 0;
    // Body
    __Vdly__shifter__DOT__cnt = vlSelf->shifter__DOT__cnt;
    __Vdly__shifter__DOT__dt = vlSelf->shifter__DOT__dt;
    if (vlSelf->rst) {
        __Vdly__shifter__DOT__cnt = 0U;
        vlSelf->done = 1U;
        __Vdly__shifter__DOT__dt = 0U;
    } else if ((7U >= (IData)(vlSelf->shifter__DOT__cnt))) {
        __Vdly__shifter__DOT__dt = (0xffU & ((IData)(vlSelf->shifter__DOT__dt) 
                                             >> 1U));
        __Vdly__shifter__DOT__cnt = 0U;
        vlSelf->done = 1U;
        __Vdly__shifter__DOT__dt = ((0x7fU & (IData)(__Vdly__shifter__DOT__dt)) 
                                    | ((IData)(vlSelf->din) 
                                       << 7U));
    } else {
        __Vdly__shifter__DOT__cnt = (0xfU & ((IData)(1U) 
                                             + (IData)(vlSelf->shifter__DOT__cnt)));
        __Vdly__shifter__DOT__dt = vlSelf->shifter__DOT__dt;
        vlSelf->done = 0U;
    }
    vlSelf->shifter__DOT__cnt = __Vdly__shifter__DOT__cnt;
    vlSelf->shifter__DOT__dt = __Vdly__shifter__DOT__dt;
    vlSelf->dout = vlSelf->shifter__DOT__dt;
}

void Vshifter___024root___eval_nba(Vshifter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vshifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter___024root___eval_nba\n"); );
    // Body
    if (vlSelf->__VnbaTriggered.at(0U)) {
        Vshifter___024root___nba_sequent__TOP__0(vlSelf);
    }
}

void Vshifter___024root___eval_triggers__act(Vshifter___024root* vlSelf);
#ifdef VL_DEBUG
VL_ATTR_COLD void Vshifter___024root___dump_triggers__act(Vshifter___024root* vlSelf);
#endif  // VL_DEBUG
#ifdef VL_DEBUG
VL_ATTR_COLD void Vshifter___024root___dump_triggers__nba(Vshifter___024root* vlSelf);
#endif  // VL_DEBUG

void Vshifter___024root___eval(Vshifter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vshifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter___024root___eval\n"); );
    // Init
    VlTriggerVec<1> __VpreTriggered;
    IData/*31:0*/ __VnbaIterCount;
    CData/*0:0*/ __VnbaContinue;
    // Body
    __VnbaIterCount = 0U;
    __VnbaContinue = 1U;
    while (__VnbaContinue) {
        __VnbaContinue = 0U;
        vlSelf->__VnbaTriggered.clear();
        vlSelf->__VactIterCount = 0U;
        vlSelf->__VactContinue = 1U;
        while (vlSelf->__VactContinue) {
            vlSelf->__VactContinue = 0U;
            Vshifter___024root___eval_triggers__act(vlSelf);
            if (vlSelf->__VactTriggered.any()) {
                vlSelf->__VactContinue = 1U;
                if (VL_UNLIKELY((0x64U < vlSelf->__VactIterCount))) {
#ifdef VL_DEBUG
                    Vshifter___024root___dump_triggers__act(vlSelf);
#endif
                    VL_FATAL_MT("shifter.v", 1, "", "Active region did not converge.");
                }
                vlSelf->__VactIterCount = ((IData)(1U) 
                                           + vlSelf->__VactIterCount);
                __VpreTriggered.andNot(vlSelf->__VactTriggered, vlSelf->__VnbaTriggered);
                vlSelf->__VnbaTriggered.set(vlSelf->__VactTriggered);
                Vshifter___024root___eval_act(vlSelf);
            }
        }
        if (vlSelf->__VnbaTriggered.any()) {
            __VnbaContinue = 1U;
            if (VL_UNLIKELY((0x64U < __VnbaIterCount))) {
#ifdef VL_DEBUG
                Vshifter___024root___dump_triggers__nba(vlSelf);
#endif
                VL_FATAL_MT("shifter.v", 1, "", "NBA region did not converge.");
            }
            __VnbaIterCount = ((IData)(1U) + __VnbaIterCount);
            Vshifter___024root___eval_nba(vlSelf);
        }
    }
}

#ifdef VL_DEBUG
void Vshifter___024root___eval_debug_assertions(Vshifter___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vshifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vshifter___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->din & 0xfeU))) {
        Verilated::overWidthError("din");}
}
#endif  // VL_DEBUG
