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
#define TILE_COIN1 9
#define TILE_COIN2 10
#define LAST_SOLID 3

#define TILE_ANIM_SPEED 20


extern const uint8_t PROGMEM stage1_1[];
extern const uint8_t PROGMEM stage1_2[];
extern const uint8_t PROGMEM stage1_3[];


class Stage
{

public:
    uint8_t *mapptr = stage1_1;
    uint8_t exit_x;
    uint8_t exit_y;

    uint8_t tile_anim = 0;
    bool coin_map[1024] = {0};
    bool frame_two = false;

    void draw_level(uint16_t offset_x);
    void fill_coins();
    void draw_coins(uint16_t offset_x);
    bool get_coin(uint16_t x, uint8_t y);
    bool is_solid(uint16_t x, int8_t y);

    
};
