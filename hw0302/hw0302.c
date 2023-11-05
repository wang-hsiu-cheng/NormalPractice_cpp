#include "mycontrol.h"
#define _USE_MATH_DEFINES // for C
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
    initialize(0, 0, M_PI / 2);
    forward(5.1);
    clock_turn(M_PI / 3);
    forward(4);
    counterclock_turn(M_PI / 3 * 2);
    forward(4);
    print();
    return 0;
}