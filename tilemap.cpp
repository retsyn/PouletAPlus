#include <Arduboy2.h>
#include "tilemap.h"
#include "graphics.h"
#include "globals.h"
#include "stages.h"

const uint8_t PROGMEM stage1_1[]{
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 9, 9, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 2,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 2,
    0, 0, 7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 6, 0, 0, 1, 1, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 2, 2, 2, 1, 0, 0, 0, 9, 9, 9, 9, 9, 0, 0, 0, 2, 2, 2, 2, 2, 2, 1, 5, 5, 5, 1, 2, 2, 2, 2, 2, 2, 0, 0, 0, 1, 1, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 7, 0, 0, 3, 3, 0, 0, 0, 0, 0, 0, 6, 0, 0, 0, 0, 0, 0, 0, 5, 5, 5, 5, 5, 5, 5, 5, 2,
    1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 1, 5, 5, 5, 1, 2, 2, 2, 2, 2, 2, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 2, 2, 2, 2, 2, 2, 2, 2

};

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

void Stage::draw_level(uint16_t cam_offset_x)
{

  int16_t tx;
  int16_t ty;

  for (int i = 0; i < MAP_MEM; i++)
  {
    // Calculate tile coordinates
    uint16_t tile_x = i % MAP_WIDTH;
    uint16_t tile_y = i / MAP_WIDTH;

    // Convert tile coordinates to pixel coordinates and apply camera offset
    tx = (tile_x * 8) - cam_offset_x;
    ty = tile_y * 8;

    // Only draw tiles within the visible screen
    if (tx > -8 && tx < 128)
    {
      uint8_t unpacked_tile = unpack_tile(tile_x, tile_y, 0);

      if (unpacked_tile != 0 && unpacked_tile != TILE_COIN1)
      {
        Sprites::drawOverwrite(tx, ty, foreground, unpacked_tile);
      }
    }
  }
}

bool Stage::is_solid(uint16_t x, int8_t y)
{
  int i;
  uint16_t tx = x / 8;
  uint16_t ty = y / 8;

  if (y < 0)
  {
    return 0;
  }

  uint8_t unpacked_tile = unpack_tile(tx, ty, 0);
  if(unpacked_tile != TILE_EMPTY && unpacked_tile <= LAST_SOLID){
    return 1;
  } else {
    return 0;
  }
  /*
  if (pgm_read_byte(mapptr + i) != TILE_EMPTY) // If not empty space...
  {
    if (pgm_read_byte(mapptr + i) <= LAST_SOLID) // If in the "solids"
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
  */
}

void Stage::fill_coins()
{
  for (uint16_t i = 0; i < 768; i++)
  {

    // For debug, just fill them all...
    size_t byte_index = i / 8;
    uint8_t bit_index = i % 8;
    coins[byte_index] &= ~(1 << bit_index);

    if (pgm_read_byte(mapptr + i + 128) == TILE_COIN1)
    {
      // Add a bit:
      coins[byte_index] |= (1 << bit_index);
    }
    else
    {
      coins[byte_index] &= ~(1 << bit_index);
    }
  }
}

void Stage::draw_coins(uint16_t cam_offset_x)
{

  int16_t tx;
  uint8_t ty;

  for (uint16_t i = 0; i < 768; i++)
  {
    size_t byte_index = i / 8;
    uint8_t bit_index = i % 8;

    if (coins[byte_index] & (1 << bit_index))
    {

      tx = ((i % MAP_WIDTH) * 8) - cam_offset_x;
      ty = (i / MAP_WIDTH) * 8 + 8;

      if (tx > -8 && tx < 128)
      {
        Sprites::drawOverwrite(tx, ty, foreground, TILE_COIN1 + tile_anim);
      }
    }
  }
}

bool Stage::get_coin(uint16_t x, uint16_t y)
{

  uint16_t i;
  uint16_t tx = x / 8;
  uint8_t ty = (y / 8) - 1;

  if (ty < 0 || ty > 7)
    return false; // Refuse to regard spaces above the screen as anything but empty.

  // Convert i to be the queried tile on the 1-d map.
  i = uint16_t(tx) + (uint16_t(ty) * 128);

  size_t byte_index = i / 8;
  uint8_t bit_index = i % 8;

  if (coins[byte_index] & (1 << bit_index))
  {
    coins[byte_index] &= ~(1 << bit_index);
    return true;
  }

  return false;
}

uint8_t Stage::unpack_tile(uint16_t x, int8_t y, uint8_t stagenum)
{
  // Reaches through the unpacking of meta-tiles to find a tile-id.

  // First find how many screens in the x value is...
  uint8_t meta_x = (x / 8); // This should point to what meta tile we are in...
  

  // We get the stage sequence "slice"
  uint8_t slice_data = pgm_read_byte(&stages[stagenum * 16 + meta_x]);

  // Now the slice data needs to be read for the piece we need.
  uint8_t meta_tile_index = (slice_data & 0x0F);

  // Calculate the index within the meta-tile:
  uint8_t tile_index = (meta_tile_index * 64) + ((y % 8) * 8) + (x % 8);

  // Now get the tile inside the meta tile?
  return pgm_read_byte(&meta_tiles[tile_index]);
}