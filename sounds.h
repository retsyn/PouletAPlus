/*
 * sounds.h
 * Created Date: 2026-07-17
 * Author: Matthew Riche
 * 
 */
#pragma once

#include <Arduboy2.h>
#include <ArduboyTones.h>

// Global tone generator (defined in sounds.cpp).
// Respects the audio mute setting (hold B while powering on to toggle).
extern ArduboyTones sound;

void sfx_jump();    // player jumps
void sfx_coin();    // coin collected
void sfx_stomp();   // foe stomped/attacked
void sfx_pop();     // balloon popped
void sfx_powerup(); // toque / glasses collected
void sfx_oneup();   // extra life (item or score milestone)
void sfx_hurt();    // non-lethal hit (lost a powerup)
void sfx_die();     // lethal hit or pit fall
void sfx_clear();   // level clear (pole / door)
void sfx_start();   // title screen -> game
