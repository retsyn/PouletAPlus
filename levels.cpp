#include "levels.h"
#include "tilemap.h"

const unsigned char PROGMEM stage01[] = {
    0x00, // Screen 1
    0x00,

    0x10, // Screen 2
    0x00,

    0x20, // Screen 3
    0x08,

    0xF0, // Screen 4
    0x50,

    0x00, // Screen 5
    0x00,

    0x10, // Screen 6
    0x00,

    0x20, // Screen 7
    0x08,

    0xF0, // Screen 8
    0xF1

};

void load_stage(uint8_t stage_num, Stage *game_stage)
{

    game_stage->write_meta_tile(0, 15, 0, 0, 0, 0);

    unsigned char *stage_data;
    switch (stage_num)
    {
    case 0:
        stage_data = stage01;
        break;
    default:
        break;
    }

    // Read each byte of the Stage data from progmem and write it to the level.

    for (int i = 0; i < 16; i++)
    {
        unsigned char next_data = pgm_read_byte(stage_data + i);

        // Use masks to get the meta-tile nibble and the flags nibble.
        byte mask = 0x0F;
        byte paintover_flags = next_data & mask;
        mask = 0xF0;
        byte meta_tile = (next_data & mask) >> 4;

        // Grab all flags.
        bool spikeson = paintover_flags & 0x01;
        bool flooroff = paintover_flags & 0x02;
        bool castle = paintover_flags & 0x04;
        bool holes = paintover_flags & 0x08;

        // game_stage->write_meta_tile(i, meta_tile, spikeson, flooroff, castle, holes);
        game_stage->write_meta_tile(i, meta_tile, spikeson, flooroff, castle, holes);
    }
}