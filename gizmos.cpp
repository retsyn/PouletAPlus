#include "globals.h"
#include "graphics.h"
#include "gizmos.h"
#include "entity.h"

void Door::update(PlayerEntity *player)
{
    if (!on)
        return;

    bool collided = false;
    // Check for collision with the player.
    if (player->y > 0)
    {
        if (((player->x + SPR_LFTSKIN) > x) && ((player->x + SPR_RGTSKIN) < x + w))
        {
            if (((player->y + SPR_TOPSKIN) > y) && ((player->y + SPR_BOTSKIN) < y + h))
            {
                collided = true;
            }
        }
    }

    if (collided)
    {
        open = true;
    }
}

Door::Door(int16_t start_x, int16_t start_y)
{
    x = start_x;
    y = start_y;
    on = false;
}

void Door::draw(int16_t camera_offset)
{
    if (on)
    {
        Sprites::drawOverwrite(x - camera_offset, y, doorspr, open);
    }
}

void Pole::draw(int16_t camera_offset)
{
    if (on)
    {
        for (uint8_t i = 24; i <= 48; i += 8)
        {
            Sprites::drawOverwrite(POLE_X - camera_offset, i, polemid, 0);
        }
        Sprites::drawOverwrite(POLE_X - camera_offset, 16, poletop, 0);
    }
}