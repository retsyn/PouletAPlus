#pragma once

#include "graphics.h"

#define ITEM_ANIM_SPEED 10

class Balloon{

public:
    bool popped : 1;
    
    uint16_t x = 0;
    uint8_t y = 0;

    Balloon(uint8_t newtype, uint16_t start_x, uint8_t start_y);
    unsigned char *sprite;

};

