#pragma once


class Ephemeral{

public:
    bool done : 1;

    uint16_t x;
    uint8_t y;

    uint8_t frame;
    uint8_t anim_timer;


    unsigned char *sprite;

    Ephemeral(uint16_t new_x, uint8_t new_y);

    void make(uint16_t new_x, uint8_t new_y);
    void draw(uint16_t offset_x);
    void animate();


};

