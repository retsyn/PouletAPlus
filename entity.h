#pragma once

#include "graphics.h"
#include "tilemap.h"

#define ENT_DUD 0
#define ENT_POULET 1
#define ENT_FENNEC 2

#define PHYS_GRAVITY 0.05f

class Entity
{

private:
    float vx = 0.0f;
    float vy = 0.0f;
    uint8_t anim_frame;
    uint8_t anim_ticker;
    uint8_t anim_wait;
    uint8_t anim_state;

public:
    bool grounded;
    uint8_t type = 0;
    float x = 0.0f;
    float y = 0.0f;
    const unsigned char *sprite;

    Entity(uint8_t newtype, float start_x, float start_y);
    void draw(int16_t offset_x);
    void physics(Stage *in_stage);
};