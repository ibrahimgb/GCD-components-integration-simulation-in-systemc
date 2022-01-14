#include "systemc.h"
SC_MODULE(register) {
// Inputs
sc_in<bool> clk;
sc_in<bool> reset;
sc_in<bool> enable;
sc_in<sc_uint<4> > D;
// Outputs
sc_out<sc_uint<4> > Q;
//Process
void do_register();
SC_CTOR(register) {
SC_METHOD(do_register);
sensitive << clk.pos();
}
};