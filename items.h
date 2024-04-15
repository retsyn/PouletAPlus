#pragma once

#include "graphics.h"

class Balloon{

public:
    bool popped : 1;
    
    uint16_t x = 0;
    uint8_t y = 0;

    unsigned char *sprite;

    Balloon(uint16_t start_x, uint8_t start_y);
    void draw(uint16_t offset_x);

};

