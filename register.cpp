#include "register.h"
void register::do_register(){
if(reset.read() == 1) Q.write(0);
else
if(enable.read() == 1) Q.write(D.read());
}
//for the register is made to save the data but the is no saving only outputting.