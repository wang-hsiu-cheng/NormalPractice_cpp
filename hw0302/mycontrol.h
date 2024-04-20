#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void initialize(double x, double y, double a);
int forward(double length);
int clock_turn(double x);
int counterclock_turn(double x);
int print();

double xCoordinate, yCoordinate, angle, moveLength;
char initialized = '0';

void initialize(double x, double y, double a)
{
    xCoordinate = x;
    yCoordinate = y;
    angle = a;
    initialized = '1';
    return;
}
int forward(double length)
{
    if (initialized == '0')
        return -1;
    moveLength = length;
    xCoordinate += moveLength * cos(angle);
    yCoordinate += moveLength * sin(angle);
    return 0;
}
int clock_turn(double x)
{
    if (initialized == '0')
        return -1;
    angle -= x;
    return 0;
}
int counterclock_turn(double x)
{
    if (initialized == '0')
        return -1;
    angle += x;
    return 0;
}
int print()
{
    if (initialized == '0')
        return -1;
    if (abs(xCoordinate) <= 0.0001)
        printf("position: (%.2f,%.2g), angle: %.2g\n", xCoordinate, yCoordinate, angle);
    else if (abs(yCoordinate) <= 0.0001)
        printf("position: (%.2g,%.2f), angle: %.2g\n", xCoordinate, yCoordinate, angle);
    else
        printf("position: (%.2g,%.2g), angle: %.2g\n", xCoordinate, yCoordinate, angle);
    return 0;
}