#include <Arduino.h>
#include "globals.h"
#include "game.h"
#include "graphics.h"
#include "tilemap.h"
#include "entity.h"
#include "gizmos.h"
#include "digits.h"

GameState game_state = title_screen;

uint8_t u_frame{0}; // The update frame value for animations not handled by objects. (menus,etc)
uint8_t master_ticker = TICKER_SPEED;
uint8_t screen_ticker = 0;

Stage *stage = new Stage();
uint8_t level = 0;
PlayerEntity *player = new PlayerEntity(ENT_POULET, 10.0f, 10.0f);
// Foe *foe = new Foe(ENT_FENNEC, 40, 10);
Foe *foe_roster[FOE_MAX];

Door *door = new Door(0, 0);

int16_t scroll = 0;
uint8_t lvl = 0;

void advance_master_frames();
void next_stage();
void fade_out();
void fade_in();
void init_foes(Foe **roster);
void update_foes(Foe **roster);

void setup()
{
    initArduboy2();

    // Hardware stuff
    // arduboy->begin();
    arduboy->blank();
    arduboy->setFrameRate(60);
    // arduboy->display();

    // Game init stuff!
    door->x = (stage->exit_x * 8);
    door->y = (stage->exit_y * 8);
    //
    door->x = 1000;
    door->y = 32;
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
            fade_out();
            arduboy->clear();

            screen_ticker = 0;
            game_state = interstitial;
        }
        break;

    case interstitial:

        draw_hud();
        Sprites::drawOverwrite(36, 30, stage_label, 0);
        draw_level(76, 30, level);
        screen_ticker += 1;
        if (screen_ticker >= SCREEN_TRANS_SPEED)
        {
            init_foes(foe_roster);
            stage->fill_coins();
            fade_in();
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
        stage->draw_coins(scroll);

        door->update(player);
        door->draw(scroll);

        draw_hud();

        if (door->open)
        {
            fade_out();
            next_stage();
            fade_in();
        }

        update_foes(foe_roster);
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

    Sprites::drawOverwrite(0, 0, title, 0);
}

void next_stage()
{
    lvl += 1;
    door->open = false;
    player->x = 0;
    scroll = 0;
}

void fade_out()
{
    for (uint8_t i = 128; i > 3; i -= 3)
    {
        if (!arduboy->nextFrame())
        {
            i += 3;
        }
        arduboy->drawFastVLine(i, 0, 128, BLACK);
        arduboy->drawFastVLine(i - 1, 0, 128, BLACK);
        arduboy->drawFastVLine(i - 2, 0, 128, BLACK);

        arduboy->display();
    }
}

void fade_in()
{
    for (uint8_t i = 1; i < 128; i += 5)
    {
        if (!arduboy->nextFrame())
        {
            i -= 5;
        }
        stage->draw_level(scroll);
        player->draw(scroll);
        arduboy->fillRect(0, 0, 128 - i, 64, BLACK);

        arduboy->display();
    }
}

void init_foes(Foe **roster)
{
    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        roster[i] = new Foe(ENT_FENNEC, 160 * i, 10);
        roster[i]->spawned = true;
        roster[i]->dead = false;
    }
}

void update_foes(Foe **roster)
{
    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        roster[i]->update(stage, player);
        roster[i]->draw(scroll);

        // No need to operate on dead foes.
        if (roster[i]->dead)
        {
            continue;
        }

        if (roster[i]->collide(player))
        {
            if (!player->attack)
            {
                player->takehit(roster[i]);
            }
            else
            {
                roster[i]->dead = true;
                player->attack = false;
                player->vy = -KILL_BOUNCE;
                player->score += 25;
            }
        }
    }
}

void draw_hud()
{
    draw_digits(player->score, 7, 78, 1);
    draw_lives(100, 1, 5);
    draw_level(1, 1, level);
}