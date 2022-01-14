#include "comparator.h"
void comparator::do_compare(){
Gt.write(0);
Eq.write(0);
Lt.write(0);
Z.write(X);
if(X > Y) Gt.write(1);
else if (X < Y) Lt.write(1);
else Eq.write(1);
}