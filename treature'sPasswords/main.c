#include "treature'sPasswords.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int check[3] = {};
    int i = 0;
    do
    {
        printf("Please input the digit: ");
        scanf("%d", &code[i]);
        i++;
    } while (code[i - 1] != -1);
    max = i - 1;

    check[0] = IsRule1Satisfy();
    check[1] = IsRule2Satisfy();
    // int check[2] = isRule1Satisfy(i);

    for (int i = 0; i < 3; i++)
    {
        if (check[0] != 1)
        {
            printf("Rule%d not follow!", i + 1);
            break;
        }
        if (i == 2) printf("SUCCESS!");
    }
    return 0;
}