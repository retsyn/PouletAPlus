#include "globals.h"
#include "stages.h"


/* Stage content 16-bit fields for every 8x8 section of stage:
0b0000000000011111
0x001F - Choice of 31 meta-tiles

0b0000000000100000
0x0020- Coins on or off

0b0000000001000000
0x0040- Spikes on or off

0b0000000010000000
0x0080- Floorless on or off

0b0000000100000000
0x0100- Castle tiles on or off

0b0000001000000000
0x0200- Fill backwall on or off

0b0000010000000000
0x0400- Hole Punch Floor on or off

0b0000100000000000
0x0800- Ent Spawn on lowest or Highest tile

0b1111000000000000
0xF000- 16 choices of spawn, from nothing to 3x balloon to 12(?) monsters (if that fits in rom?)

*/

const uint16_t stages[] PROGMEM = {
    // Stage 1 (8 slices, each 16 bits)
    // Entity IDs:
    // 0000 Nothing
    // 0001 Balloon
    // 0010 Fennec
    // 0011 Goob!
    // 0100 Bloob!
    // 0101 Drake!

    //EEEEHPWCFSCTTTTT    EEEEHPWCFSCTTTTT
    // Stage 1-1
    0b0000000000000000, 0b0000000000100000,
    0b0110000000000000, 0b0000000000100001,
    0b0000000000100000, 0b0011000000000000,
    0b0000100000000000, 0b0010000000000011,
    0b0000000000000101, 0b0001000000000000,
    0b0000000000100010, 0b0000000000000000,
    0b0000010000000000, 0b0010000000000100,
    0b0011000000000000, 0b0011001000000000,

    // Stage 3 (8 slices, each 16 bits)
    // The one with the extra fennecs and holes
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,

    // Stage 3 (8 slices, each 16 bits)
    // The one with our first glasses maybe?
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,
    0b0000000000000000, 0b0000000000000000,

    // Stage 2-1 (8 slices, each 16 bits)
    // The one with the birds!
    0b0000001000000000, 0b0000000000000000,
    0b0000000000000010, 0b0010100000100010,
    0b0000100000000000, 0b0010000001000100,
    0b0000000000000101, 0b0100100000000000,
    0b0100100000000000, 0b0100100001001100,
    0b0100100001000000, 0b0000000000010101,
    0b0010000000100111, 0b0100100000001000,
    0b0100100000100000, 0b0000001000001011,


};