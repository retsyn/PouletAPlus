#pragma once
#include "entity.h"

class Door
{

public:
    uint16_t x;
    uint16_t y;
    const unsigned char *sprite;

protected:
    uint8_t w = 16;
    uint8_t h = 16;

    bool open = false;

    Door(uint16_t start_x, uint16_t start_y);
    void update(PlayerEntity *player);
    void draw();

};