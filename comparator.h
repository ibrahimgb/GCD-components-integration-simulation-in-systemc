#include "systemc.h"
SC_MODULE(comparator) {
// Inputs
sc_in<sc_uint<4> > X;
sc_in<sc_uint<4> > Y;
// Outputs
sc_out<sc_uint<4> > Z;
sc_out<bool> Gt;
sc_out<bool> Eq;
sc_out<bool> Lt;
//Process
void do_compare();
SC_CTOR(comparator) {
SC_METHOD(do_compare);
sensitive << X << Y;
}
};