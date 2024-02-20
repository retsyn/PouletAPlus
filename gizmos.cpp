#include "globals.h"
#include "graphics.h"
#include "gizmos.h"
#include "entity.h"

void Door::update(PlayerEntity *player){

    bool collided = false;
    // Check for collision with the player.
    if(((player->x + player->left_skin) > x) && ((player->x + player->right_skin) < x + w)){
        if(((player->y + player->top_skin) > y) && ((player->y + player->bottom_skin) < y + h)){
            collided = true;
        }
    }

    if(collided){
        open = true;
    }
}

Door::Door(uint16_t start_x, uint16_t start_y){
    x = start_x;
    y = start_y;

}


void Door::draw(){
    Sprites::drawPlusMask(x, y, door_plus_mask, 0);
}