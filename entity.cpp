#include <Arduboy2.h>
#include "entity.h"


Entity::Entity(uint8_t newtype, float start_x, float start_y)
{

    x = start_x;
    y = start_y;
    type = newtype;

    // Get sprite to point to the spot in progmem.
    switch (type)
    {
    case ENT_POULET:
        sprite = poulet_plus_mask;
        break;

    default:
        break;
    }

    vx = 0.0f;
    vy = 0.0f;
    grounded = false;
}

void Entity::draw(int16_t offset_x)
{
    Sprites::drawPlusMask(x - offset_x, y, sprite, 0);
    // Sprites::drawPlusMask(x, y, poulet_plus_mask, 1);
}

void Entity::physics(Stage *in_stage){
    vy += PHYS_GRAVITY;

    x += vx;
    
    // Apply gravity!
    if(!in_stage->is_solid(x, y + 16)){
        y += vy;
    }


}
