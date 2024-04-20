#include "mycontrol.h"
#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    initialize(0, 0, 0);
    counterclock_turn(M_PI / 6);
    forward(5);
    print();
    clock_turn(M_PI / 6);
    forward(4);
    print();
    return 0;
}