#include "mux21.h"
void gcd::do_mux21(){
switch(select){
case 0:
Z.write(X);
break;
case 1:
Z.write(Y);
break;
}
}