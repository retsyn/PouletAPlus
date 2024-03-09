#pragma once

#define LEFT_BOUND 0
#define RIGHT_BOUND 1024

#define KILL_BOUNCE 1.25

#define COIN_PTS 5

#define FOE_MAX 5

#include <Arduboy2.h>


// Declare a global pointer to Arduboy2 and Tinyfont instances.
extern Arduboy2* arduboy;

// Declare a function to initialize the Arduboy2 instance
void initArduboy2();

#define TICKER_SPEED 30