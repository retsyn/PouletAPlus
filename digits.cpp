#include "digits.h"
#include "graphics.h"

void draw_digits(uint32_t value, uint8_t digits, uint8_t x, uint8_t y){

    uint16_t number = value;

    for(int i = 0; i < digits; i++){
        if(number > 0){
            int next_digit = number % 10; // least significant digit
            number /= 10;
            SpritesB::drawOverwrite(x - (i * 8), y, digits_sheet, next_digit);
        } else {
            SpritesB::drawOverwrite(x - (i * 8), y, digits_sheet, 0);
        }
    }
}

void draw_lives(uint8_t x, uint8_t y, uint8_t total){

    SpritesB::drawOverwrite(x + 8, y, digits_sheet, 11);
    SpritesB::drawOverwrite(x, y, digits_sheet, 10);
    draw_digits(total, 2, x + 24, y);

}

void draw_level(uint8_t x, uint8_t y, uint8_t stage){
    
    uint8_t world = (stage / 3) + 1;
    uint8_t sublevel = (stage % 3) + 1;
    SpritesB::drawOverwrite(x, y, digits_sheet, world);
    SpritesB::drawOverwrite(x + 8, y, digits_sheet, 12);
    SpritesB::drawOverwrite(x + 16, y, digits_sheet, sublevel);

}
