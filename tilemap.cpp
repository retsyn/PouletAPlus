#include <Arduboy2.h>
#include "tilemap.h"
#include "graphics.h"
#include "globals.h"
#include "stages.h"

const unsigned char meta_tiles[] PROGMEM = {
  // 00000
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 7, 0, 0,
    0, 0, 0, 4, 4, 6, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
  // 00001    
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    4, 4, 1, 1, 1, 1, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 00010
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 7, 0, 0, 0, 0, 0,
    0, 0, 6, 4, 4, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 2, 2, 2, 2, 2, 2, 1,
    1, 2, 2, 2, 2, 2, 2, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 00011
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 00100
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 9, 9,
    0, 0, 0, 0, 0, 0, 9, 9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 1, 1, 1, 4, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 00101
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 9, 0, 0, 0, 0, 0, 0,
    9, 9, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    4, 4, 4, 1, 1, 1, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 00110
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 0, 0,
    0, 4, 4, 9, 9, 9, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 00111
    1, 1, 1, 1, 1, 1, 1, 1,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 0, 0, 5, 5, 0, 0, 5,
    5, 9, 9, 5, 5, 9, 9, 5,
    5, 0, 0, 5, 5, 0, 0, 5,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 4, 4, 4, 4, 5, 5,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 01000
    1, 1, 1, 1, 1, 1, 1, 1,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 0, 9, 9, 0, 5, 5,
    5, 5, 0, 9, 9, 0, 5, 5,
    5, 5, 5, 1, 1, 5, 5, 5,
    5, 5, 5, 5, 5, 5, 5, 5,
    5, 5, 4, 4, 4, 4, 5, 5,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 01001
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 9, 9, 0,
    1, 1, 1, 1, 0, 9, 9, 0,
    8, 8, 8, 8, 0, 9, 9, 0,
    8, 8, 8, 8, 0, 0, 0, 0,
    8, 8, 8, 8, 4, 4, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 01010
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    5, 0, 0, 5, 5, 0, 0, 5,
    5, 9, 9, 5, 5, 9, 9, 5,
    5, 0, 0, 4, 4, 0, 0, 5,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 01011
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    5, 0, 0, 5, 5, 1, 1, 1,
    5, 9, 9, 5, 5, 1, 1, 1,
    5, 0, 0, 5, 5, 5, 5, 5,
    1, 1, 1, 5, 5, 5, 5, 5,
    1, 1, 1, 4, 5, 5, 5, 5,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 01100
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 9, 9, 9,
    0, 0, 0, 0, 0, 9, 9, 9,
    0, 0, 0, 0, 0, 0, 6, 0,
    0, 0, 0, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 1, 1, 1,
    1, 1, 4, 4, 4, 1, 1, 1,
    // 01101
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 9, 9, 0, 0, 0, 9, 9,
    9, 9, 9, 0, 0, 0, 9, 9,
    0, 0, 0, 0, 7, 0, 0, 0,
    0, 0, 0, 0, 6, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0,
    4, 4, 4, 1, 1, 1, 4, 4,
    // 01110
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    // 01111
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 9, 9, 0,
    0, 0, 0, 0, 0, 9, 9, 0,
    0, 9, 9, 0, 0, 1, 1, 0,
    0, 9, 9, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    // 10000
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    // 10001
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    // 10010
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 0, 0,
    0, 0, 0, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    // 10011
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 1, 1, 1, 1, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 1, 1, 1, 0, 0, 0,
    4, 4, 4, 4, 4, 4, 4, 4,
    // 10100
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 9, 0,
    0, 0, 9, 9, 9, 9, 9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 0, 0, 0, 0, 0, 1,
    1, 1, 4, 4, 4, 4, 4, 1,
    // 10101
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 9, 9, 9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 0, 0, 0, 1, 1, 0,
    1, 1, 4, 4, 4, 1, 1, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 10110
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 2, 2, 1, 0, 0,
    0, 0, 1, 2, 2, 1, 0, 0,
    4, 4, 1, 1, 1, 1, 4, 4,
    // 10111
    0, 0, 1, 2, 2, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    9, 9, 5, 5, 5, 5, 9, 9,
    9, 9, 5, 5, 5, 5, 9, 9,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 2, 2, 1, 0, 0,
    0, 0, 1, 2, 2, 1, 0, 0,
    4, 4, 1, 2, 2, 1, 4, 4,
    // 11000
    2, 2, 2, 2, 2, 2, 2, 2,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 9, 9, 9, 9, 9, 9, 9,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 0, 0, 1, 0, 0, 0,
    0, 1, 0, 0, 1, 0, 0, 0,
    4, 1, 4, 4, 1, 4, 4, 4,
    // 11001
    2, 2, 2, 2, 2, 2, 2, 2,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 1, 1, 0, 0, 0,
    4, 4, 4, 1, 1, 4, 4, 4,
    // 11010
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 9, 0, 0,
    0, 0, 0, 0, 9, 1, 0, 0,
    0, 0, 0, 9, 1, 1, 0, 0,
    0, 0, 9, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    4, 4, 1, 1, 1, 1, 4, 4,
    // 11011
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 9, 9, 9, 1, 0, 0,
    0, 1, 4, 4, 4, 1, 0, 0,
    0, 1, 1, 1, 1, 1, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    // 11100
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 9, 9, 9, 9, 9, 9, 0,
    0, 0, 0, 0, 4, 0, 0, 0,
    0, 0, 0, 1, 1, 1, 1, 0,
    0, 0, 4, 1, 0, 0, 0, 0,
    0, 1, 1, 1, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    // 11101
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 0, 0,
    0, 0, 0, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 4, 1, 4, 0, 0,
    0, 0, 0, 1, 1, 1, 0, 0,
    // 11110
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    9, 9, 9, 9, 4, 4, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    8, 5, 5, 5, 5, 5, 5, 8,
    8, 5, 5, 5, 5, 5, 5, 8,
    8, 5, 5, 5, 5, 5, 5, 8,
    1, 1, 1, 1, 1, 1, 1, 1,
    // 11111
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    4, 0, 0, 0, 0, 0, 0, 4,
    1, 1, 1, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 1,
    1, 1, 1, 0, 0, 1, 1, 1,
};

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
      uint8_t unpacked = unpack_tile(tile_x, tile_y);

      if (unpacked != 0 && unpacked != TILE_COIN1)
      {
        Sprites::drawSelfMasked(tx, ty, foreground, unpacked);
      }
    }
  }
}

bool Stage::is_spike(uint16_t x, int8_t y)
{
  int i;
  uint16_t tx = x / 8;
  uint16_t ty = y / 8;

  if (y < 0)
  {
    return 0;
  }
  else if (y >= 56)
  {
    return 0;
  }

  uint8_t unpacked = unpack_tile(tx, ty);
  if (unpacked == TILE_SPIKE)
  {
    return 1;
  }
  else
  {
    return 0;
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
  else if (y > 56)
  {
    return 0;
  }

  uint8_t unpacked = unpack_tile(tx, ty);
  if (unpacked != TILE_EMPTY && unpacked <= LAST_SOLID)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void Stage::fill_coins()
{
  for (uint16_t i = 0; i < COIN_ARRAY; ++i)
    coins[i] = 0;

  for (uint16_t i = 0; i < COIN_ARRAY * 8; i++)
  {
    size_t byte_index = i / 8;
    uint8_t bit_index = i % 8;

    uint8_t tx = i % 128;
    uint8_t ty = (i / 128) + 1;
    if (unpack_tile(tx, ty) >= TILE_COIN1)
    {
      // Add a bit:
      coins[byte_index] |= (1 << bit_index);
    }
  }
}

void Stage::draw_coins(uint16_t cam_offset_x)
{

  int16_t tx;
  uint8_t ty;

  for (uint16_t i = 0; i < COIN_ARRAY * 8; i++)
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

bool Stage::check_coin(uint16_t x, uint16_t y)
{

  uint16_t i;
  uint16_t tx = x / 8;
  uint8_t ty = (y / 8) - 1;
  if (y < 8 || y > 56)
    return false; // Refuse to regard spaces above the screen as anything but empty.

  // Convert i to be the queried tile on the 1-d map.
  i = uint16_t(tx) + (uint16_t(ty) * 128);

  size_t byte_index = i / 8;
  uint8_t bit_index = i % 8;

  if (byte_index >= COIN_ARRAY) return false;

  if (coins[byte_index] & (1 << bit_index))
  {
    coins[byte_index] &= ~(1 << bit_index);
    return true;
  }

  return false;
}

bool Stage::get_coin(uint16_t x, uint16_t y, uint16_t x2, uint16_t y2)
{
  // Four corner coin check:
  if(check_coin(x, y) || check_coin(x2, y) || check_coin(x, y2) || check_coin(x2, y2)){
    return true;
  } else {
    return false;
  }
}



uint8_t Stage::unpack_tile(uint16_t x, uint8_t y)
{
  // Reaches through the unpacking of meta-tiles to find a tile-id.

  // If below or above playfield, tile must return nothing.
  if (y > 7)
  {
    return TILE_EMPTY;
  }

  uint8_t mx = (x % 8);

  // First find how many screens in the x value is...
  uint8_t meta_x = (x / 8); // This should point to what meta tile we are in...

  // We get the stage sequence "slice"
  uint16_t slice_data = pgm_read_word(&stages[currentstage * 16 + meta_x]);

  // Now the slice data needs to be read for the piece we need-- last five bits are meta-tile
  uint16_t meta_tile_index = (slice_data & 0x1F);

  /* Unpacking debug hooey
  //Serial.print("Slice Data: ");
  //Serial.println(slice_data, BIN);
  //Serial.print("Meta Tile BIN: ");
  //Serial.println(meta_tile_index, BIN);
  //Serial.print("Meta Tile Dec: ");
  //Serial.println(meta_tile_index, DEC);
  delay(0);
  */

  // //Serial output at this point was:
  //Slice Data: 101
  //Meta Tile BIN: 101
  //Meta Tile Dec: 5

  //Which is absolutely correct.  The issue is somewhere else.

  // Calculate the index within the meta-tile:
  uint16_t tile_index = (meta_tile_index * 64) + ((y % 8) * 8) + (x % 8);

  // Now get the tile inside the meta tile?
  uint8_t unpacked = pgm_read_byte(&meta_tiles[tile_index]);

  // Now perform 'mutations'
  // 0x0020- Coins on or off
  if (unpacked >= TILE_COIN1)
  {
    if ((slice_data & 0x20) == 0)
    {
      unpacked = TILE_EMPTY;
    }
  }

  // 0x0040- Spikes on or off
  if (unpacked == TILE_SPIKE)
  {
    if ((slice_data & 0x0040) == 0)
    {
      unpacked = TILE_EMPTY;
    }
  }

  // 0x0080- Floorless on or off
  if (y == 7)
  {
    if ((slice_data & 0x0080) != 0)
    {
      unpacked = TILE_EMPTY;
    }
  }

  // 0x0400- Hole Punch Floor on or off
  if ((slice_data & 0x0400) != 0)
  {
    if (mx > 1 && mx < 6 && y > 4)
    {
      unpacked = TILE_EMPTY;
    }
  }

  // 0x0100- Castle tiles on or off
  if ((slice_data & 0x0100) != 0)
  {
    if (unpacked == TILE_CLASSIC)
    {
      unpacked = TILE_CASTLEBLOCK;
    }
    else if (unpacked == TILE_EMPTY)
    {
      unpacked = TILE_CASTLEWALL;
    }
  }

  // 0x0200- Fill backwall on or off
  if ((slice_data & 0x0200) != 0)
  {
    if (unpacked == TILE_EMPTY)
    {
      unpacked = TILE_CHOCWALL;
    }
  }

  return unpacked;

}
