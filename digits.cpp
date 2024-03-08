#include "digits.h"
#include "graphics.h"

void draw_digits(uint32_t value, uint8_t digits, uint8_t x, uint8_t y){

    uint16_t number = value;

    for(int i = 0; i < digits; i++){
        if(number > 0){
            int next_digit = number % 10; // least significant digit
            number /= 10;
            Sprites::drawPlusMask(x - (i * 6), y, digits_plus_mask, next_digit);
        } else {
            Sprites::drawPlusMask(x - (i * 6), y, digits_plus_mask, 0);
        }
    }
}

void draw_lives(uint8_t x, uint8_t y, uint8_t total){

    Sprites::drawPlusMask(x + 7, y, digits_plus_mask, 11);
    Sprites::drawPlusMask(x, y, digits_plus_mask, 10);
    draw_digits(total, 2, x + 19, y);

}