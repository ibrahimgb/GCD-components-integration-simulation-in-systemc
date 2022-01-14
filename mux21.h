#include "systemc.h"
SC_MODULE(mux21) {
// Inputs
sc_in<bool> select;
sc_in<sc_uint<4> > X;
sc_in<sc_uint<4> > Y;
// Outputs
sc_out<sc_uint<4> > Z;
//Process
void do_mux21();
SC_CTOR(mux21) {
SC_METHOD(do_mux21);
sensitive << X << Y <<select;
}
};