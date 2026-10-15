#pragma once
#include <iostream>
#include <stdlib.h>
#include <time.h>


/**
 * This class is destined to be a random numbers generator at a rate of 60Hz
 * Data is currently assumed to be int
 */

class Generator{
private:
    int upBound;
    int genRate;
public:
    Generator(int upperBound, int rate);

    int generate();
    int rate();


};
