#include <Arduboy2.h>
#include "entity.h"

Entity::Entity(uint8_t newtype, float start_x, float start_y)
{

    x = start_x;
    y = start_y;
    type = newtype;

    // Generic collision skins (biased to middle bottom of the 16x16 sprite)
    top_skin = 9;
    bottom_skin = 16;
    left_skin = 4;
    right_skin = 11;



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
}

void Entity::physics(Stage *in_stage)
{
    bool vert_collide = 0;
    bool horiz_collide = 0;

    // Cap horizontal movement speed:
    if (vx > top_speed) vx = top_speed;
    if (vx < -top_speed) vx = -top_speed;

    // Apply gravity!
    vy += PHYS_GRAVITY;

    // Check where velocity will put this ent next:
    int16_t nx = (x + vx);
    int16_t ny = (y + vy);

    if (vy > 0)
    {
        // Check for downward collision by iterating through pixels travelled;
        for (int i = y; i <= int(ny); i++)
        {
            if (in_stage->is_solid(x + left_skin, i + bottom_skin) or in_stage->is_solid(x + right_skin, i + bottom_skin))
            {
                vy = 0;
                y = i - 1;
                vert_collide = 1;
            }
        }
    }
    else if (vy < 0)
    {
        // Check for upward collision by iterating through pixels travelled;
        for (int i = y; i >= int(ny); i--)
        {
            if (in_stage->is_solid(x + left_skin + 1, i + top_skin) or in_stage->is_solid(x + right_skin - 1, i + top_skin))
            {
                vy = 0;
                y = i + 1;
                vert_collide = 1;
            }
        }
    }
    if (!vert_collide)
        y += vy;

    if (vx > 0)
    {
        // Check for right collision...
        for (int i = x; i <= int(nx); i++)
        {
            if (in_stage->is_solid(i + right_skin, y + bottom_skin - 1) or in_stage->is_solid(i + left_skin, y + bottom_skin - 1))
            {
                vx = 0;
                x = i - 1;
                horiz_collide = 1;
            }
        }
    }
    else if (vx < 0)
    {
        // Check for left collision...
        for (int i = x; i >= int(nx); i--)
        {
            if (in_stage->is_solid(i + left_skin, y + top_skin + 1) or in_stage->is_solid(i + left_skin, y + bottom_skin - 1))
            {
                vx = 0;
                x = i + 1;
                horiz_collide = 1;
            }
        }
    }
    if (!horiz_collide)
        x += vx;
}
