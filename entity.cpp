#include "globals.h"
#include "entity.h"

Entity::Entity(uint8_t newtype, float start_x, float start_y)
{

    x = start_x;
    y = start_y;
    type = newtype;

    anim_wait = 5;

    // Generic collision skins (biased to middle bottom of the 16x16 sprite)
    top_skin = 9;
    bottom_skin = 15;
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
}

/*
// This function is virtual now.
void Entity::draw(int16_t offset_x)
{
    Sprites::drawPlusMask(x - offset_x, y, sprite, 0);
}
*/

void Entity::physics(Stage *in_stage)
{
    bool vert_collide = 0;
    bool horiz_collide = 0;

    // Cap horizontal movement speed:
    if (vx > top_speed)
        vx = top_speed;
    if (vx < -top_speed)
        vx = -top_speed;

    // Apply gravity!
    vy += PHYS_GRAVITY;

    // Check where velocity will put this ent next:
    int16_t nx = (x + vx);
    int16_t ny = (y + vy);

    if (vy > 0)
    {
        
        // Check for downward collision by iterating through pixels travelled;
        for (int i = floor(y); i <= floor(ny) + 1; i++)
        {
            if (in_stage->is_solid(floor(x) + left_skin, i + bottom_skin) || in_stage->is_solid(floor(x) + right_skin, i + bottom_skin))
            {
                vy = 0;
                y = i - 1;
                vert_collide = 1;
                grounded = true;
                break;
            } else {
                grounded = false;
            }
        }
        
    }

    else if (vy < 0)
    {
        // Check for upward collision by iterating through pixels travelled;
        for (int i = y; i >= int(ny); i--)
        {
            if (in_stage->is_solid(x + left_skin + 1, i + top_skin) || in_stage->is_solid(x + right_skin - 1, i + top_skin))
            {
                vy = 0;
                y = i + 1;
                vert_collide = 1;
                break;
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
            if (in_stage->is_solid(i + right_skin, y + bottom_skin - 1) || in_stage->is_solid(i + left_skin, y + bottom_skin - 1))
            {
                vx = 0;
                x = i - 1;
                horiz_collide = 1;
                break;
            }
        }
    }
    else if (vx < 0)
    {
        // Check for left collision...
        for (int i = x; i >= int(nx); i--)
        {
            if (in_stage->is_solid(i + left_skin, y + top_skin + 1) || in_stage->is_solid(i + left_skin, y + bottom_skin - 1))
            {
                vx = 0;
                x = i + 1;
                horiz_collide = 1;
                break;
            }
        }
    }
    if (!horiz_collide)
        x += vx;

    // Add friction:
    // Add friction:
    if (grounded)
    {
        if (vx > 0)
        {
            vx -= PHYS_FRICTION;
        }
        if (vx < 0)
        {
            vx += PHYS_FRICTION;
        }
        if (abs(vx) < PHYS_FRICTION)
        {
            vx = 0;
        }
    }
}

PlayerEntity::PlayerEntity(uint8_t newtype, float start_x, float start_y) : Entity(newtype, start_x, start_y)
{
    jump_buffer = 0;
    accel = PLAYER_ACCEL;
    top_speed = PLAYER_TOPSPEED;
}

void PlayerEntity::control()
{
    tinyfont->setCursor(1, 1);
    if (grounded)
        tinyfont->print("GRND");
    tinyfont->setCursor(1, 6);
    if (flip)
        tinyfont->print("FLIP");
    tinyfont->setCursor(24, 1);
    tinyfont->print(anim_frame);
    tinyfont->setCursor(24, 6);
    tinyfont->print(anim_ticker);

    if (arduboy->pressed(LEFT_BUTTON))
    {
        vx -= accel;
        flip = true;
    }
    if (arduboy->pressed(RIGHT_BUTTON))
    {
        vx += accel;
        flip = false;
    }
    if (arduboy->justPressed(B_BUTTON))
    {
        if (grounded)
            vy = -PLAYER_JUMPPOWER;
        grounded = false;
    }

    // Little physics manipulation outside the physics module so we don't have to override:
    if (vy < 0 and arduboy->pressed(B_BUTTON))
    {
        vy -= JUMP_JUICE;
    }
}

void PlayerEntity::draw(int16_t offset_x)
{

    // Anim state determination:
    if (grounded)
    {
        if (abs(vx) > 0.1)
        {
            anim_state = walking;
        }
        else
        {
            anim_state = idle;
        }
    }
    else
    {
        if (vy < 0)
        {
            anim_state = jumping_up;
        }
        else
        {
            anim_state = jumping_down;
        }
    }

    // Advance animation frames:
    anim_ticker--;
    if (anim_ticker <= 0)
    {
        anim_frame++;
        anim_ticker = anim_wait;
    };
    // If the frame exceeds the current animation, refer to the pre-calced anim lengths.
    if (anim_frame > FRAMELEN[anim_state])
    {
        anim_frame = 0;
    };

    switch (anim_state)
    {
    case idle:
        Sprites::drawPlusMask(x - offset_x, y, sprite, pgm_read_byte(&poulet_anim_idle[anim_frame]) + (MIRROR * int(flip)));
        break;
    case walking:
        Sprites::drawPlusMask(x - offset_x, y, sprite, pgm_read_byte(&poulet_anim_walk[anim_frame]) + (MIRROR * int(flip)));
        break;
    case jumping_up:
        Sprites::drawPlusMask(x - offset_x, y, sprite, pgm_read_byte(&poulet_anim_jump_up[anim_frame]) + (MIRROR * int(flip)));
        break;
    case jumping_down:
        Sprites::drawPlusMask(x - offset_x, y, sprite, pgm_read_byte(&poulet_anim_jump_down[anim_frame]) + (MIRROR * int(flip)));
        break;
    case attacking:
        Sprites::drawPlusMask(x - offset_x, y, sprite, pgm_read_byte(&poulet_anim_attack[anim_frame]) + (MIRROR * int(flip)));
        break;
    case dead:
        Sprites::drawPlusMask(x - offset_x, y, sprite, pgm_read_byte(&poulet_anim_death[anim_frame]) + (MIRROR * int(flip)));
        break;
    default:
        break;
    }
}
