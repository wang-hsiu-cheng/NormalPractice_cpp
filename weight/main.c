#include "weight.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    setup_boy_weight(2);
    setup_girl_weight(1);
    int result = afford_weight(2, 3);
    printf ("%d\n", result);

    return 0;
}