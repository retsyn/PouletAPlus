#include "items.h"
#include "globals.h"

Balloon::Balloon(uint16_t new_x, uint8_t new_y)
{
    x = new_x;
    y = new_y;

    sprite = balloon_plus_mask;
}

void Balloon::draw(uint16_t offset_x)
{

    if (!popped)
    {
        Sprites::drawPlusMask(x - offset_x, y, sprite, 0);
    }
}