#include <Arduino.h>
#include "globals.h"
#include "game.h"
#include "graphics.h"
#include "tilemap.h"
#include "entity.h"

GameState game_state = title_screen;

uint8_t u_frame{0}; // The update frame value for animations not handled by objects. (menus,etc)
uint8_t master_ticker = TICKER_SPEED;
uint8_t screen_ticker = TICKER_SPEED;

Stage *stage = new Stage();
PlayerEntity *player = new PlayerEntity(ENT_POULET, 10.0f, 10.0f);

int16_t scroll = 0;

void advance_master_frames();

void setup()
{
    initArduboy2();

    // Hardware stuff
    arduboy->begin();
    arduboy->blank();
    arduboy->setFrameRate(60);
    arduboy->display();

    // Game init stuff!
    stage->write_meta_tile(0, 0, 0, 0, 0, 0);
    stage->write_meta_tile(1, 0, 0, 0, 0, 0);
    stage->write_meta_tile(2, 0, 0, 0, 0, 0);
    stage->write_meta_tile(3, 1, 0, 0, 0, 0);
    stage->write_meta_tile(4, 0, 0, 0, 0, 0);
    stage->write_meta_tile(5, 2, 0, 0, 0, 0);
    stage->write_meta_tile(6, 0, 0, 0, 0, 0);
    stage->write_meta_tile(7, 3, 0, 0, 0, 0);
    stage->write_meta_tile(8, 4, 1, 0, 0, 0);
    stage->write_meta_tile(9, 5, 1, 0, 0, 0);
    stage->write_meta_tile(10, 0, 1, 0, 1, 0);
    stage->write_meta_tile(11, 0, 0, 0, 1, 0);
    stage->write_meta_tile(12, 0, 0, 0, 1, 0);
    stage->write_meta_tile(13, 3, 0, 0, 1, 0);
    stage->write_meta_tile(14, 1, 0, 0, 1, 0);
    stage->write_meta_tile(15, 0, 0, 0, 0, 0);
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
        if (arduboy->justPressed(B_BUTTON))
        {
            game_state = in_play;
        }
        break;

    case in_play:
        stage->draw_level(scroll);

        // Debug shit!

        // Debug scroll?
        scroll = player->x - 64;
        player->draw(scroll);
        player->control();
        player->physics(stage);


    default:
        break;
    }
    advance_master_frames();

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
    tinyfont->setCursor(82, 45);
    tinyfont->print("START");
    tinyfont->setCursor(82, 50);
    tinyfont->print("OPTIONS");
}