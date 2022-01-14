#include "register.h"
#include "substractor.h"
#include "mux21.h"
#include "comparator.h"
#include "controller.h"

int sc_main(int argc, char *argv[]) {
mux21 muxForX("mux21");
mux21 muxForY("mux21");
register register1("register");
register register2("register");
register registerOut("register");
comparator comparator("comparator");
substractor substractor1("substractor");
substractor substractor2("substractor");
controller controller("controller");

sc_clock clk("Clock", 10, SC_NS);//
sc_signal<bool> reset; //
sc_signal<bool> enable; //
sc_signal<sc_uint<4> > muxXtoRegister;//
sc_signal<sc_uint<4> > muxYtoRegister;//
sc_signal<sc_uint<4> > subToMutX;//
sc_signal<sc_uint<4> > subToMutY;//
sc_signal<sc_uint<4> > x_i;//put hier the valu of X
sc_signal<sc_uint<4> > y_i;// same for y
sc_signal<bool> Gt;//
sc_signal<bool> Eq;//
sc_signal<bool> Lt;//
sc_signal<sc_uint<4> > outputRegister1;//
sc_signal<sc_uint<4> > outputRegister2;//
sc_signal<sc_uint<4> > data_O;//
sc_signal<sc_uint<4> > comparaterToOutputRegister;//


muxForX.Y(subToMutX);
muxForX.select(Gt);
mutForX.Z(muxXtoRegister);
mutForX.X(x_i);

muxForY.Y(subToMutY);
muxForY.select(Lt);
mutForY.Z(muxYtoRegister);
mutForY.X(y_i);

register1.reset(reset);
register1.enable(enable);
register1.clk(clk);
register1.D(muxXtoRegister);
register1.Q(outputRegister1);

register1.reset(reset);
register1.enable(enable);
register1.clk(clk);
register1.D(muxYtoRegister);
register1.Q(outputRegister2);

comparator.X(outputRegister1);
comparator.Y(outputRegister2);
comparator.Z(comparaterToOutputRegister);
comparator.Gt(Gt);
comparator.Eq(Eq);
comparator.Lt(Lt);

substractor1.X(outputRegister1);
substractor1.Y(outputRegister2);
substractor1.Z(subToMutX);
substractor1.enable(Gt);

substractor1.X(outputRegister1);
substractor1.Y(outputRegister2);
substractor1.Z(subToMutY);
substractor1.enable(Lt);

registerOut.enable(Eq);
registerOut.reset(reset);
registerOut.clk(clk);
registerOut.D(comparaterToOutputRegister);
registerOut.Q(data_O);


controller.clk(clk);
controller.reset(reset);
controller.valid(valid); 
controller.A(x_i); 
controller.B(y_i); 
controller.ready(ready); 
controller.GCD(data_O);


sc_start();
return 0;
}

