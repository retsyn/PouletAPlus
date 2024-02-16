#pragma once

#define MIRROR 8

#include <Arduboy2.h>
#include <Arduboy.h>

extern const unsigned char PROGMEM foreground[];
extern const unsigned char PROGMEM poulet_plus_mask[];
extern const unsigned char PROGMEM aviator_plus_mask[];
extern const uint8_t PROGMEM title[];

// Frame id's
extern const unsigned char PROGMEM poulet_anim_idle[];
extern const unsigned char PROGMEM poulet_anim_walk[];
extern const unsigned char PROGMEM poulet_anim_jump_up[]; 
extern const unsigned char PROGMEM poulet_anim_jump_down[];
extern const unsigned char PROGMEM poulet_anim_attack[];
extern const unsigned char PROGMEM poulet_anim_death[];