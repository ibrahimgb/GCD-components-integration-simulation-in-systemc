#include "systemc.h"
SC_MODULE(substractor) {
// Inputs
sc_in<sc_uint<4> > X;
sc_in<sc_uint<4> > Y;
sc_in<bool> enable;
// Outputs
sc_out<sc_uint<4> > Z;
//Process
void do_compare();
SC_CTOR(substractor) {
SC_METHOD(do_substract);
sensitive << X << Y << enable;
}
};