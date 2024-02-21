#include <Arduino.h>
#include "globals.h"
#include "game.h"
#include "graphics.h"
#include "tilemap.h"
#include "entity.h"
#include "levels.h"
#include "gizmos.h"

GameState game_state = title_screen;

uint8_t u_frame{0}; // The update frame value for animations not handled by objects. (menus,etc)
uint8_t master_ticker = TICKER_SPEED;
uint8_t screen_ticker = TICKER_SPEED;

Stage *stage = new Stage();
PlayerEntity *player = new PlayerEntity(ENT_POULET, 10.0f, 10.0f);
Door *door = new Door(0, 0);


int16_t scroll = 0;
uint8_t lvl = 0;

void advance_master_frames();
void next_stage();

void setup()
{
    initArduboy2();

    // Hardware stuff
    //arduboy->begin();
    arduboy->blank();
    arduboy->setFrameRate(60);
    //arduboy->display();

    // Game init stuff!
    load_stage(0, stage);
    door->x = (stage->exit_x * 8);
    door->y = (stage->exit_y * 8);
}

void loop()
{
    if (!arduboy->nextFrame())
        return;
    arduboy->pollButtons();
    arduboy->clear();

    switch (game_state)
    {
    case title_screen:
        show_title_screen();
        advance_master_frames();

        if (arduboy->justPressed(B_BUTTON))
        {
            game_state = in_play;
        }
        break;

    case in_play:


        // Debug scroll?
        scroll = floor(player->x - 64);
        if (scroll < 0)
        {
            scroll = 0;
        }
        else if (scroll > 1024 - 128)
        {
            scroll = 1024 - 128;
        }
        stage->draw_level(scroll);

        door->update(player);
        if(door->open){
            next_stage();
        }
        door->draw(scroll);

        player->draw(scroll);
        player->control();
        player->physics(stage);

        break;

    default:
        break;
    }

    arduboy->display();
}

void advance_master_frames()
{
    // Advance the frames of all animations.
    master_ticker--;
    if (master_ticker <= 0)
    {
        u_frame++;
        master_ticker = TICKER_SPEED;
    }
}

void show_title_screen()
{
    arduboy->drawBitmap(0, 0, title, 128, 64, 1);

    
}

void next_stage(){
    lvl += 1;
    load_stage(lvl, stage);
    door->open = false;
    player->x = 10;
    player->y = 10;
}