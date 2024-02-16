#pragma once

#include "graphics.h"
#include "tilemap.h"

#define ENT_DUD 0
#define ENT_POULET 1
#define ENT_FENNEC 2

#define PLAYER_JUMPPOWER 1.20f
#define PLAYER_ACCEL 0.1f
#define PLAYER_TOPSPEED 0.75f
#define JUMP_JUICE 0.043f

#define PHYS_GRAVITY 0.07f
#define PHYS_FRICTION 0.2f

class Entity
{
private:
    // Anim state vars:
    uint8_t anim_frame;
    uint8_t anim_ticker;
    uint8_t anim_wait;
    uint8_t anim_state;
    // Collision "skins" pixel widths:
    uint8_t top_skin;
    uint8_t bottom_skin;
    uint8_t left_skin;
    uint8_t right_skin;

public:
    float vx = 0.0f;
    float vy = 0.0f;

    float top_speed = 1.0f;
    float accel = 0.1f;

    bool grounded;
    uint8_t type = 0;
    float x = 0.0f;
    float y = 0.0f;
    const unsigned char *sprite;

    Entity(uint8_t newtype, float start_x, float start_y);
    void draw(int16_t offset_x);
    void physics(Stage *in_stage);
};

class PlayerEntity : public Entity
{
public:

    bool flyboy = 0;

    PlayerEntity(uint8_t newtype, float start_x, float start_y);
    void control();

private:
    uint8_t jump_buffer = 0;
};