#pragma once
#include "globals.h"

enum EphemType{
    pop = 0,
};


class Ephemeral{

public:
    bool done : 1;

    uint16_t x;
    uint8_t y;

    uint8_t frame;
    uint8_t anim_timer;


    unsigned char *sprite;

    Ephemeral();
    void make(uint16_t new_x, uint8_t new_y, uint8_t ephemType);

    void draw(uint16_t offset_x);
    void animate();

};


class EphemeralRoster{


public:
    Ephemeral *roster[EPHEM_MAX];

    EphemeralRoster();
    void add(uint16_t new_x, uint8_t new_y, uint8_t type);
    void updateRoster(uint16_t offset_x);

};

