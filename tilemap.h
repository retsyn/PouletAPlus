#pragma once

#define MAP_WIDTH 128
#define MAP_MEM 1024

#define TILE_SPIKE 4
#define TILE_EMPTY 0
#define TILE_CASTLEWALL 5
#define TILE_CHOCWALL 8
#define TILE_CLASSIC 1
#define TILE_CASTLEBLOCK 2
#define TILE_CHOCBLOCK 3
#define LAST_SOLID 3

extern const uint8_t PROGMEM meta_tiles[];
extern const uint8_t PROGMEM stage1_1[];
extern const uint8_t PROGMEM stage1_2[];

class Stage
{

protected:
    uint8_t *mapptr = stage1_1;

public:
    uint8_t exit_x;
    uint8_t exit_y;

    void draw_level(uint16_t offset_x);
    bool is_solid(uint16_t x, uint16_t y);
};
