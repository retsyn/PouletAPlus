#include <Arduboy2.h>
#include "tilemap.h"
#include "graphics.h"

const unsigned char meta_tiles[] PROGMEM = {
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

void Stage::write_meta_tile(uint8_t horizontal_meta, uint8_t meta_index, bool spikeson, bool flooroff, bool castle, bool holes)
{
  uint8_t meta_tile[64] = {0};

  // The meta tiles are arranged "vertically" for easy of copying in this phase.
  // Copying them to the actual in-game tilemap is gonna be "interlaced" in a way.
  for (int i = 0; i < 64; ++i)
  {
    meta_tile[i] = pgm_read_byte(meta_tiles + i + (meta_index * 64));
  }

  // Now that we have a copy from progmem, we can edit it based on the flags.
  // Hard mode holes!
  if (holes)
  {
    for (int i = 0; i < 64; ++i)
    {
      if ((i % 8) > 2 && (i % 8) < 6)
      {
        meta_tile[i] = TILE_EMPTY;
      }
    }
  }

  // Spikes or no spikes
  if (!spikeson)
  {

    for (int i = 0; i < 64; ++i)
    {
      if (meta_tile[i] == TILE_SPIKE)
      {
        meta_tile[i] = TILE_EMPTY;
      }
    }
  }

  // Floor or no floor.
  if (flooroff)
  {
    for (int i = 56; i < 64; ++i)
    {
      meta_tile[i] = TILE_EMPTY;
    }
  }

  // In a castle or not.
  if (castle)
  {
    for (int i = 0; i < 64; ++i)
    {
      if (meta_tile[i] == TILE_EMPTY)
      {
        meta_tile[i] = TILE_CASTLEWALL;
      }
      else if (meta_tile[i] == TILE_CLASSIC)
      {
        meta_tile[i] = TILE_CASTLEBLOCK;
      }
    }
  }

  // Now that we have edited the meta_tile, we "paste" it to the in-game array.
  for (int row = 0; row < 8; ++row)
  {
    for (int column = 0; column < 8; ++column)
    {
      maparray[(horizontal_meta * 8) + (row * 128) + column] = meta_tile[(row * 8) + column];
    }
  }
}

void Stage::draw_level(uint16_t cam_offset_x)
{

  int16_t tx;
  int16_t ty;

  for (int i = 0; i < sizeof(maparray); i++)
  {
    if (maparray[i] != 0)
    {
      tx = (i % 128) * 8;
      ty = (i / 128) * 8;
      Sprites::drawOverwrite(tx - cam_offset_x, ty, foreground, maparray[i]);
    }
  }
}
