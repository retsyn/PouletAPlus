#include "globals.h"
#include "graphics.h"
#include "gizmos.h"
#include "entity.h"

void Door::update(PlayerEntity *player)
{

    bool collided = false;
    // Check for collision with the player.
    if (((player->x + player->left_skin) > x) && ((player->x + player->right_skin) < x + w))
    {
        if (((player->y + player->top_skin) > y) && ((player->y + player->bottom_skin) < y + h))
        {
            collided = true;
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
}

void Door::draw(int16_t camera_offset)
{
    Sprites::drawPlusMask(x - camera_offset, y, door_plus_mask, open);
}