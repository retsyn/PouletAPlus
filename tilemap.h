#pragma once

extern const uint8_t PROGMEM meta_tiles[];

class Stage
{

private:
    uint8_t maparray[1024] = {1};

public:
    void write_meta_tile(uint8_t horizontal_meta, uint8_t meta_index, bool spikeson, bool flooroff, bool castle, bool holes);
    void draw_level(uint16_t offset_x);
};
