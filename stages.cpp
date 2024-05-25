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
    0b0000000000000000, 0b0000000000100000,
    0b0000000001100000, 0b0000000011100000,
    0b0000000111101111, 0b0000001111101111,
    0b0111001001101111, 0b0011001100101111,
    0b1000111110001111, 0b0100111001001110,
    0b1100110111001111, 0b0000100000001111,
    0b1111000011101111, 0b1011000110101111,
    0b0111001001101111, 0b0011001100101111,

    // Stage 2 (8 slices, each 16 bits)
    0b1000111110001111, 0b0100111001001110,
    0b1100110111001101, 0b0000100000001000,
    0b1111000011110000, 0b1011000110110001,
    0b0111001001110010, 0b0011001100110011,
    0b1000111110001111, 0b0100111001001110,
    0b1100110111001101, 0b0000100000001000,
    0b1111000011110000, 0b1011000110110001,
    0b0111001001110010, 0b0011001100110011,

};