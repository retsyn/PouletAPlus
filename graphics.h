#pragma once

#define MIRROR 8
#define FOE_MIRROR 3

#include <Arduboy2.h>
#include <Arduboy.h>

extern const unsigned char PROGMEM foreground[];
extern const unsigned char PROGMEM poulet_plus_mask[];
extern const unsigned char PROGMEM aviator_plus_mask[];
//extern const uint8_t PROGMEM title[];
extern const unsigned char PROGMEM smallpoulet[];
extern const unsigned char PROGMEM titlecard[];
extern const unsigned char PROGMEM aplus[];


// Anim frame id's for Poulet
extern const unsigned char PROGMEM poulet_anim_idle[];
extern const unsigned char PROGMEM poulet_anim_walk[];
extern const unsigned char PROGMEM poulet_anim_jump_up[]; 
extern const unsigned char PROGMEM poulet_anim_jump_down[];
extern const unsigned char PROGMEM poulet_anim_attack[];
extern const unsigned char PROGMEM poulet_anim_death[];
extern const unsigned char PROGMEM poulet_anim_hover[];

// objects
extern const unsigned char PROGMEM doorspr[];
extern const unsigned char PROGMEM polemid[];
extern const unsigned char PROGMEM poletop[];


// Anim frame id's for all foes
extern const unsigned char PROGMEM foe_anim_walk[];
extern const unsigned char PROGMEM foe_anim_die[];

// Foes
extern const unsigned char PROGMEM fennec_plus_mask[];
extern const unsigned char PROGMEM goob_plus_mask[];
extern const unsigned char PROGMEM bloob_plus_mask[];

// The toque!
extern const unsigned char PROGMEM toque_plus_mask[];

// The digits
extern const unsigned char PROGMEM digits_plus_mask[];

// Other text
extern const uint8_t PROGMEM stage_label[];

// Items:
extern const unsigned char PROGMEM glasses_plus_mask[];
extern const unsigned char PROGMEM balloon_plus_mask[];
extern const unsigned char PROGMEM toquepowerup_plus_mask[];
extern const unsigned char PROGMEM oneup_plus_mask[];
extern const unsigned char PROGMEM toquetext_plus_mask[];

// Ephemeral effects:
extern const unsigned char PROGMEM pop_plus_mask[];
extern const unsigned char PROGMEM flyboy_plus_mask[];