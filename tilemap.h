#pragma once

#define MAP_WIDTH 128

#define TILE_SPIKE 4
#define TILE_EMPTY 0
#define TILE_CASTLEWALL 5
#define TILE_CHOCWALL 8
#define TILE_CLASSIC 1
#define TILE_CASTLEBLOCK 2
#define TILE_CHOCBLOCK 3
#define LAST_SOLID 3

extern const uint8_t PROGMEM meta_tiles[];

class Stage
{

private:
    uint8_t maparray[1024] = {1};

public:
    void write_meta_tile(uint8_t horizontal_meta, uint8_t meta_index, bool spikeson, bool flooroff, bool castle, bool holes);
    void draw_level(uint16_t offset_x);
    bool is_solid(uint16_t x, uint16_t y);
};
