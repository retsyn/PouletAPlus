#include "graphics.h"
#include "ephemeral.h"
#include "globals.h"

Ephemeral::Ephemeral(uint16_t new_x, uint8_t y)
{

    // Hardcoded animation for pop.
    sprite = pop_plus_mask;

    frame = 0;
    anim_timer = EPHEM_ANIM_SPEED;
    done = true;
}

void Ephemeral::make(uint16_t new_x, uint8_t new_y)
{

    // Assign new sprite if needed:
    // Will be a switch case if more ephemera are added.

    sprite = pop_plus_mask;
    frame = 0;
    done = false;

    x = new_x;
    y = new_y;
}

void Ephemeral::draw(uint16_t offset_x)
{
    if (!done)
    {
        Sprites::drawPlusMask(x - offset_x, y, sprite, frame);
    }
}

void Ephemeral::animate()
{
    if (done)
    {
        return;
    }

    anim_timer--;
    if (anim_timer <= 0)
    {
        frame++;
        if (frame > 3)
        {
            done = true;
        }
        anim_timer = EPHEM_ANIM_SPEED;
    }
}