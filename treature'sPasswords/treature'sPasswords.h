#include <stdio.h>
#include <stdlib.h>

int code[50] = {};
int max = 0;

int checkSet[50] = {0};

int Find(int x, int y, int n);
int IsRule1Satisfy();
int IsRule2Satisfy();

int IsRule1Satisfy()
{
    // int isAllExist = 0;
    int numberSet[6] = {1, 32, 65, 65, 9, 78};
    
    // int j = 0;
    for (int j = 0; j < 3; j ++)
        if (Find(numberSet[j*2], numberSet[j*2+1], j+1) == 0)
            return 0;
    for (int i = 0; i < max; i++)
    {
        if (checkSet[i] != 0)
            if (checkSet[i+1] - checkSet[i] != 1 && checkSet[i + 1] != 0)
                return 0;
    }
    return 1;
}
int Find(int num1, int num2, int setNum)
{
    for (int i = 0; i < max; i++)
    {
        if (code[i] == num1 || code[i] == num2)
        {
            checkSet[i] = setNum;
            return 1;
        }
    }
    return 0;
}
int IsRule2Satisfy()
{
    return 0;
}