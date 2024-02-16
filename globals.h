#pragma once

#include <Arduboy2.h>
#include <Tinyfont.h>


// Declare a global pointer to Arduboy2 and Tinyfont instances.
extern Arduboy2* arduboy;
extern Tinyfont* tinyfont;

// Declare a function to initialize the Arduboy2 instance
void initArduboy2();

#define TICKER_SPEED 30