#include "graphics.h"
#include "ephemeral.h"
#include "globals.h"

Ephemeral::Ephemeral()
{
    x = 0;
    y = 0;
    frame = 0;
    anim_timer = EPHEM_ANIM_SPEED;
    done = true;
}

void Ephemeral::make(uint16_t new_x, uint8_t new_y, uint8_t ephemType)
{

    // Assign new sprite if needed:
    // Will be a switch case if more ephemera are added.
    switch (ephemType)
    {
    case pop:
        sprite = pop_plus_mask;
        break;

    default:
        break;
    }

    sprite = pop_plus_mask;
    frame = 0;
    done = false;
    anim_timer = EPHEM_ANIM_SPEED;

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
        // If the done flag is set, this ephem is "gone."
        return;
    }

    if (anim_timer > 0)
    {
        anim_timer--;
    }
    else
    {
        frame++;
        anim_timer = EPHEM_ANIM_SPEED;
        if (frame >= EPHEM_END_FRAME)
        {
            done = true;
        }
    }
}

EphemeralRoster::EphemeralRoster()
{

    for (uint8_t i; i < EPHEM_MAX; i++)
    {
        roster[i] = new Ephemeral();
    }
}

void EphemeralRoster::add(uint16_t new_x, uint8_t new_y, uint8_t type)
{

    uint8_t i = 0;
    for (i = 0; i < EPHEM_MAX - 1; i++)
    {
        if (roster[i]->done)
        {
            break;
        }

    }

    roster[i]->make(new_x, new_y, type);
}


void EphemeralRoster::updateRoster(uint16_t scroll){

    for(uint8_t i = 0; i < EPHEM_MAX; i++){
        if(!roster[i]->done){
            roster[i]->draw(scroll);
            roster[i]->animate();
        } else {
            continue;
        }
    }
}