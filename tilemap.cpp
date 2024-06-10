#include <Arduboy2.h>
#include "tilemap.h"
#include "graphics.h"
#include "globals.h"
#include "stages.h"

const unsigned char meta_tiles[] PROGMEM = {
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 7, 0,
    0, 0, 0, 4, 4, 0, 6, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 1, 0, 0, 0, 1, 0,
    0, 1, 1, 4, 4, 4, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 9, 9, 9, 0,
    0, 0, 0, 0, 9, 9, 9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 1, 1, 1, 1,
    0, 0, 0, 0, 1, 2, 2, 1,
    0, 0, 4, 4, 1, 2, 2, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 4, 4, 0, 0, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 0, 5, 5, 5, 5, 0, 9,
    0, 0, 5, 5, 5, 5, 0, 9,
    0, 0, 5, 5, 5, 5, 0, 9,
    0, 0, 5, 5, 5, 5, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 0, 0, 0,
    4, 4, 0, 9, 9, 0, 4, 4,
    1, 1, 0, 0, 0, 0, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 9, 9, 9, 9, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 4, 0, 0,
    0, 0, 3, 3, 3, 3, 3, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    3, 3, 3, 3, 3, 3, 3, 3,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 9, 9,
    0, 0, 4, 0, 0, 4, 9, 9,
    1, 1, 1, 0, 0, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 9, 0,
    0, 0, 0, 0, 1, 1, 9, 0,
    0, 0, 0, 1, 1, 1, 9, 0,
    0, 0, 1, 1, 1, 1, 0, 0,
    0, 1, 1, 1, 1, 1, 4, 4,
    1, 1, 1, 1, 1, 1, 1, 1,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 3, 0, 0, 0, 0, 0, 0,
    0, 3, 9, 9, 0, 0, 0, 0,
    0, 0, 9, 9, 0, 0, 0, 0,
    0, 0, 0, 0, 4, 4, 0, 0,
    1, 2, 2, 2, 2, 2, 2, 1,
    1, 2, 2, 2, 2, 2, 2, 1,
    1, 2, 2, 2, 2, 2, 2, 1,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 9, 9, 9, 9, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 1, 0, 0,
    0, 1, 0, 0, 0, 0, 0, 0,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 0, 0, 8, 8, 8,
    8, 8, 8, 9, 9, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    1, 1, 1, 1, 1, 1, 1, 1,
    1, 1, 1, 1, 1, 1, 1, 1,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 8, 8, 8, 8, 8,
    8, 8, 8, 4, 4, 8, 8, 8,
    8, 8, 1, 1, 1, 1, 1, 1,
    8, 8, 8, 9, 9, 8, 8, 8,
    8, 8, 8, 9, 9, 8, 8, 8,
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
    0, 0, 0, 0, 9, 9, 0, 0,
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
    1, 1, 1, 1, 1, 1, 1, 1,
    // Repeats begin here, make more!
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
      uint8_t unpacked = unpack_tile(tile_x, tile_y);

      if (unpacked != 0 && unpacked != TILE_COIN1)
      {
        Sprites::drawOverwrite(tx, ty, foreground, unpacked);
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
  for (uint16_t i = 0; i < 768; i++)
  {

    // For debug, just fill them all...
    size_t byte_index = i / 8;
    uint8_t bit_index = i % 8;
    coins[byte_index] &= ~(1 << bit_index);

    uint8_t tx = i % 128;
    uint8_t ty = (i / 128) + 1;
    if (unpack_tile(tx, ty) >= TILE_COIN1)
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

bool Stage::check_coin(uint16_t x, uint16_t y){

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

void Stage::get_coin(uint16_t x, uint16_t y, uint16_t x2, uint16_t y2)
{
  // Four corner coin check:
  check_coin(x, y);
  check_coin(x2, y);
  check_coin(x, y2);
  check_coin(x2, y2);
}

uint8_t Stage::unpack_tile(uint16_t x, uint8_t y)
{
  // Reaches through the unpacking of meta-tiles to find a tile-id.

  // If below playfield, tile must return nothing.
  if(y > 64 || y < 0){
    return TILE_EMPTY;
  }

  // First find how many screens in the x value is...
  uint8_t meta_x = (x / 8); // This should point to what meta tile we are in...

  // We get the stage sequence "slice"
  uint16_t slice_data = pgm_read_word(&stages[currentstage * 16 + meta_x]);

  // Now the slice data needs to be read for the piece we need-- last five bits are meta-tile
  uint8_t meta_tile_index = (slice_data & 0x1F);

  // Calculate the index within the meta-tile:
  uint8_t tile_index = (meta_tile_index * 64) + ((y % 8) * 8) + (x % 8);

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

  //0x0400- Hole Punch Floor on or off
  if(x > 1 && x < 6 && y > 1){
    unpacked == TILE_EMPTY;
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
  if((slice_data & 0x0200) != 0)
  {
    if(unpacked == TILE_EMPTY){
      unpacked == TILE_CHOCWALL;
    }
  }
  return unpacked;

}
