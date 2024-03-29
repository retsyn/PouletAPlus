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
    0, 0, 0, 4, 4, 0, 0, 0,
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
    4, 4, 0, 0, 0, 0, 4, 4,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 4, 0, 0,
    0, 0, 3, 3, 3, 3, 3, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 3, 3, 3, 3, 3, 3, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 4, 0, 0, 4, 0, 0,
    1, 1, 1, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 0, 0, 0, 1, 1, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 1, 1, 1, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 4, 0, 0,
    1, 2, 2, 2, 2, 2, 2, 1,
    1, 2, 2, 2, 2, 2, 2, 1,
    1, 2, 2, 2, 2, 2, 2, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 0, 0, 8, 8, 8,
    8, 8, 8, 0, 0, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 4, 4, 8, 8, 8,
    8, 8, 1, 1, 1, 1, 1, 1,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 1, 1, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0, 0,
    0, 8, 8, 0, 0, 0, 0, 0,
    0, 8, 8, 0, 0, 1, 1, 0,
    0, 8, 8, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 8, 8, 0,
    4, 1, 1, 0, 0, 8, 8, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 8, 8, 8, 8, 0, 0,
    0, 0, 8, 8, 8, 8, 0, 0,
    0, 0, 3, 3, 3, 3, 0, 0,
    0, 0, 0, 8, 8, 0, 0, 0,
    0, 0, 0, 8, 8, 0, 0, 0,
    0, 0, 0, 8, 8, 0, 0, 0,
    4, 4, 0, 3, 3, 0, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 3, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    8, 5, 5, 5, 5, 5, 5, 8,
    8, 5, 5, 5, 5, 5, 5, 8,
    8, 5, 5, 5, 5, 5, 5, 8,
    1, 1, 1, 1, 1, 1, 1, 1};

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
      maparray[(horizontal_meta * 8) + (row * MAP_WIDTH) + column] = meta_tile[(row * 8) + column];
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
      tx = ((i % MAP_WIDTH) * 8) - cam_offset_x;
      ty = (i / MAP_WIDTH) * 8;

      if (tx > -8 && tx < 128)
        Sprites::drawOverwrite(tx, ty, foreground, maparray[i]);
        
    }
  }
}

bool Stage::is_solid(uint16_t x, uint16_t y)
{
  int i;
  uint16_t tx = x / 8;
  uint16_t ty = y / 8;

  if (ty < 0)
    return false; // Refuse to regard spaces above the screen as anything but empty.

  // Convert i to be the queried tile on the 1-d map.
  i = tx + (ty * 128);

  if (maparray[i] != TILE_EMPTY) // If not empty space...
  {
    if (maparray[i] <= LAST_SOLID) // If in the "solids"
    {
      return 1;
    }
    else
    {
      return 0;
    }
  }
  else
  {
    return 0;
  }
}