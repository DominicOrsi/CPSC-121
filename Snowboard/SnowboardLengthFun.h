#ifndef SnowboardLengthFun_H
#define SnowboardLengthFun_H

#include <iostream>

using namespace std;

const double SNOWBOARD_HEIGHT_PERCENTAGE = 0.88;
const double CM_IN_INCH = 2.54;
const int INCHES_IN_FEET = 12;

int getUserHeight(void);
double convertInchesToCM(int);
int calculateSnowboardLength(int);
void displaySnowboardLength(int, int);

#endif
