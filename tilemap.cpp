#include <Arduboy2.h>
#include "tilemap.h"


const uint8_t meta_tile01[] PROGMEM = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,7,0,
    0,0,0,4,4,0,6,0,
    1,1,1,1,1,1,1,1
};

const uint8_t meta_tile02[] PROGMEM = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,1,0,0,0,1,0,
    0,1,1,4,4,4,1,1,
    1,1,1,1,1,1,1,1
};

const uint8_t meta_tile03[] PROGMEM = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,1,1,1,1,
    0,0,0,0,1,2,2,1,
    0,0,4,4,1,2,2,1,
    1,1,1,1,1,1,1,1
};

const uint8_t meta_tile04[] PROGMEM = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,1,1,1,1,0,0,
    0,0,5,5,5,5,0,0,
    0,0,5,5,5,5,0,0,
    0,0,5,5,5,5,0,0,
    0,0,5,5,5,5,0,0,
    1,1,1,1,1,1,1,1
};

const uint8_t meta_tile05[] PROGMEM = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    1,1,0,0,0,0,1,1,
    1,1,0,0,0,0,1,1
};

const uint8_t meta_tile06[] PROGMEM = {
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,
    0,0,3,3,3,3,0,0,
    0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0
};


// Need a Map class here:
// Review how to do classes in cpp and make a map class.


/*
void draw_tiles(int x, int y, Game *game)
{

  // x and y are offsets from the camera.
  int i;
  uint16_t tx;
  uint16_t ty;

  for (i = 0; i < (sizeof(maparray)); i++)
  {
    if (pgm_read_byte(maparray + i) != 0)
    {
      tx = (i % 128) * 8;
      ty = (i / 128) * 8;

      Sprites::drawOverwrite(tx - game->camerax, ty, tileset, pgm_read_byte((maparray + i)) - 1);
    }
  }
}
*/