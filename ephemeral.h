#pragma once
#include "globals.h"

enum EphemType
{
    pop = 0,
    toqueword,
    flyboy,
    proj
};

class Ephemeral
{
public:
    uint16_t x;
    uint16_t y;

    int8_t vx;
    int8_t vy;

    uint8_t frame;
    uint8_t anim_timer;

    bool done : 1;
    bool text : 1;

    unsigned char *sprite;

    Ephemeral();
    void make(uint16_t new_x, uint8_t new_y, uint8_t ephemType, int16_t vx, int16_t vy);
    void draw(uint16_t offset_x);
    void proj_update(uint16_t offset_x);
    void animate();
};

class EphemeralRoster
{

public:
    Ephemeral roster[EPHEM_MAX];

    EphemeralRoster();
    void add(uint16_t new_x, uint8_t new_y, uint8_t type, int16_t new_vx, int16_t new_vy);
    void shoot_projectile(int16_t sx, int16_t sy, int16_t tx, int16_t ty, uint8_t speed);
    void updateRoster(uint16_t offset_x);
};
