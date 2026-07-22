#pragma once

#include <Arduboy2.h>
#include <ArduboyTones.h>

// Global tone generator (defined in sounds.cpp).
// Respects the audio mute setting (hold B while powering on to toggle).
extern ArduboyTones sound;

void sfx_jump();    
void sfx_coin();    
void sfx_stomp();   
void sfx_pop();     
void sfx_powerup(); 
void sfx_oneup();   
void sfx_hurt();    
void sfx_die();     
void sfx_clear();   
void sfx_start();   
void sfx_attack();
void sfx_door();