#include <Arduboy2.h>
#include "tilemap.h"

const uint8_t meta_tiles[] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 7, 0,
    0, 0, 0, 4, 4, 0, 6, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 4, 4, 4, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1,
    0, 0, 0, 0, 1, 2, 2, 1,
    0, 0, 4, 4, 1, 2, 2, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 3, 3, 3, 3, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0};

class Stage
{

  uint8_t maparray[1024] = {0};

public:
  void write_meta_tile(uint8_t horizontal_meta, uint8_t meta_index, bool spikeson, bool flooroff, bool castle, bool holes)
  {
    uint8_t meta_tile[64] = {0};
    
    // The meta tiles are arranged "vertically" for easy of copying in this phase.
    // Copying them to the actual in-game tilemap is gonna be "interlaced" in a way.
    for (int i = 0; i < 64; ++i)
    {
      meta_tile[i] = meta_tiles[i + (meta_index * 8)];
    }

    // Now that we have a copy from progmem, we can edit it based on the flags.
    // TODO!  make spikeson etc, work.

    // Now that we have edited the meta_tile, we "paste" it to the in-game array.
    for (int row = 0; row < 8; ++row)
    {
      for (int column = 0; column < 8; ++column)
      {
        maparray[(horizontal_meta * 8) + (row * 128) + column] = meta_tile[(row * 8) + column];
      }
    }
  }
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