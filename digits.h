#pragma once

#include <Arduboy2.h>
#include <Arduboy.h>

void draw_digits(uint32_t value, uint8_t digits, uint8_t x, uint8_t y);
void draw_lives(uint8_t x, uint8_t y, uint8_t total);
void draw_level(uint8_t x, uint8_t y, uint8_t stage);