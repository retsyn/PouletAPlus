#pragma once

#define LEFT_BOUND 0
#define RIGHT_BOUND 1024

#define DEATHTIME_MAX 255

#define KILL_BOUNCE 1.25

#define COIN_PTS 2

#define FOE_MAX 4
#define BALLOON_MAX 5
#define ITEM_MAX 2

#define EPHEM_ANIM_SPEED 3
#define EPHEM_MAX 3
#define EPHEM_END_FRAME 4

#include <Arduboy2.h>


// Declare a global pointer to Arduboy2 and Tinyfont instances.
extern Arduboy2* arduboy;

// Declare a function to initialize the Arduboy2 instance
void initArduboy2();

#define TICKER_SPEED 30
#define SCREEN_TRANS_SPEED 120