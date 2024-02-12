#pragma once

#include <Arduboy2.h>

// Declare a global pointer to the Arduboy2 instance
extern Arduboy2* arduboy;
// Declare a function to initialize the Arduboy2 instance
void initArduboy2();

#define TICKER_SPEED 30