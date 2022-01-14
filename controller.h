#include "systemc.h"
SC_MODULE(controller) {
// Inputs
sc_in<bool> clk;
sc_in<bool> ready;
sc_in<sc_uint<4> > GCD;
// Outputs
sc_out<bool> reset;
sc_out<bool> valid;
sc_out<sc_uint<4> > X;
sc_out<sc_uint<4> > Y;
//Process
void do_controller();
SC_CTOR(controller) {
SC_THREAD(do_controller);
sensitive << ready << clk.pos();
}
};