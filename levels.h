#pragma once

#include "globals.h"
#include "tilemap.h"

extern const unsigned char PROGMEM stage01[];

extern void load_stage(uint8_t stage_num, Stage *game_stage);