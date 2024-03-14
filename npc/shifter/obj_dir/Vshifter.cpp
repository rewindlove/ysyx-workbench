// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vshifter.h"
#include "Vshifter__Syms.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vshifter::Vshifter(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vshifter__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , rst{vlSymsp->TOP.rst}
    , din{vlSymsp->TOP.din}
    , dout{vlSymsp->TOP.dout}
    , done{vlSymsp->TOP.done}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vshifter::Vshifter(const char* _vcname__)
    : Vshifter(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vshifter::~Vshifter() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vshifter___024root___eval_debug_assertions(Vshifter___024root* vlSelf);
#endif  // VL_DEBUG
void Vshifter___024root___eval_static(Vshifter___024root* vlSelf);
void Vshifter___024root___eval_initial(Vshifter___024root* vlSelf);
void Vshifter___024root___eval_settle(Vshifter___024root* vlSelf);
void Vshifter___024root___eval(Vshifter___024root* vlSelf);

void Vshifter::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vshifter::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vshifter___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        vlSymsp->__Vm_didInit = true;
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vshifter___024root___eval_static(&(vlSymsp->TOP));
        Vshifter___024root___eval_initial(&(vlSymsp->TOP));
        Vshifter___024root___eval_settle(&(vlSymsp->TOP));
    }
    // MTask 0 start
    VL_DEBUG_IF(VL_DBG_MSGF("MTask0 starting\n"););
    Verilated::mtaskId(0);
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vshifter___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfThreadMTask(vlSymsp->__Vm_evalMsgQp);
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vshifter::eventsPending() { return false; }

uint64_t Vshifter::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "%Error: No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vshifter::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vshifter___024root___eval_final(Vshifter___024root* vlSelf);

VL_ATTR_COLD void Vshifter::final() {
    Vshifter___024root___eval_final(&(vlSymsp->TOP));
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vshifter::hierName() const { return vlSymsp->name(); }
const char* Vshifter::modelName() const { return "Vshifter"; }
unsigned Vshifter::threads() const { return 1; }
std::unique_ptr<VerilatedTraceConfig> Vshifter::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false, false, false}};
};

//============================================================
// Trace configuration

void Vshifter___024root__trace_init_top(Vshifter___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vshifter___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vshifter___024root*>(voidSelf);
    Vshifter__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->scopeEscape(' ');
    tracep->pushNamePrefix(std::string{vlSymsp->name()} + ' ');
    Vshifter___024root__trace_init_top(vlSelf, tracep);
    tracep->popNamePrefix();
    tracep->scopeEscape('.');
}

VL_ATTR_COLD void Vshifter___024root__trace_register(Vshifter___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vshifter::trace(VerilatedVcdC* tfp, int levels, int options) {
    if (tfp->isOpen()) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vshifter::trace()' shall not be called after 'VerilatedVcdC::open()'.");
    }
    if (false && levels && options) {}  // Prevent unused
    tfp->spTrace()->addModel(this);
    tfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP));
    Vshifter___024root__trace_register(&(vlSymsp->TOP), tfp->spTrace());
}
