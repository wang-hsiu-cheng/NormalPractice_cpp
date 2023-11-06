#include <stdio.h>
#include <stdlib.h>

void setup_girl_weight(int);
void setup_boy_weight(int);
float afford_weight(int x, int y);
int boyWeight, girlWeight;

void setup_boy_weight(int _weight)
{
    boyWeight = _weight;
}
void setup_girl_weight(int _weight)
{
    girlWeight = _weight;
}
float afford_weight( int x, int y )
{
    if (boyWeight == 0 || girlWeight == 0 || x < 0 || y < 0 || y > x)
        return -1;
    if (x % 2 == 0) // it's girl
    {
        float left_up = 0, right_up = 0;
        if (x - 1 >= 0 && y - 1 >= 0) left_up = (float)(boyWeight + afford_weight(x - 1, y - 1)) / 2;
        if (x - 1 >= 0 && y <= x - 1) right_up = (float)(boyWeight + afford_weight(x - 1, y)) / 2;
        return (left_up + right_up);
    }
    else
    {
        float left_up = 0, right_up = 0;
        if (x - 1 >= 0 && y - 1 >= 0) left_up = (float)(girlWeight + afford_weight(x - 1, y - 1)) /2;
        if (x - 1 >= 0 && y <= x - 1) right_up = (float)(girlWeight + afford_weight(x - 1, y)) / 2;
        return (left_up + right_up);
    }
}
