#include "levels.h"
#include "tilemap.h"
#include "gizmos.h"

const unsigned char PROGMEM stage01[] = {
    0x00, // 0
    0x00, // 1
    0x10, // 2
    0x00, // 3
    0x20, // 4
    0x00, // 5
    0xF0, // 6
    0x90, // 7
    0x00, // 8
    0x00, // 9
    0xC0, // 10
    0x00, // 11
    0x20, // 12
    0x08, // 13
    0xF0, // 14
    0xF1, // 15
    122, 5 // Door coords

};

const unsigned char PROGMEM stage02[] = {
    0x30, // Screen 1
    0x20,
    0x30, // Screen 2
    0x40,
    0x50, // Screen 3
    0x18,
    0x20, // Screen 4
    0x50,
    0x80, // Screen 5
    0xA0,
    0x10, // Screen 6
    0xA0,
    0x20, // Screen 7
    0x30,
    0xF0, // Screen 8
    0xF0,
    122, 5 // Door coords

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
    case 1:
        stage_data = stage02;
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

    game_stage->exit_x = pgm_read_byte(stage_data + 16);
    game_stage->exit_y = pgm_read_byte(stage_data + 17);

    // Proposal that we read enemy type and position here with a loop from 
    // address (stage_data + 18) to sizeof(stage)
}