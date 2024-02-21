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
Door *door = new Door(10, 10);


int16_t scroll = 0;

void advance_master_frames();

void setup()
{
    initArduboy2();

    // Hardware stuff
    //arduboy->begin();
    arduboy->blank();
    arduboy->setFrameRate(60);
    //arduboy->display();

    // Game init stuff!
    load_stage(1, stage);
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
        stage->draw_level(scroll);


        // Debug scroll?
        scroll = player->x - 64;
        if (scroll < 0)
        {
            scroll = 0;
        }
        else if (scroll > 1024 - 128)
        {
            scroll = 1024 - 128;
        }

        door->update(player);  // Can't uncomment this without ruining the sketch somehow!
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