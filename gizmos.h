#pragma once

#include "entity.h"


class Door
{

public:
    int16_t x;
    int16_t y;
    Door(int16_t start_x, int16_t start_y);
    void update(PlayerEntity *player);
    void draw(int16_t offset_x);
    bool open = false;

protected:
    int8_t w = 16;
    int8_t h = 16;


};