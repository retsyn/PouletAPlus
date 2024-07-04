#include <Arduino.h>
#include "globals.h"
#include "game.h"
#include "graphics.h"
#include "tilemap.h"
#include "entity.h"
#include "gizmos.h"
#include "digits.h"
#include "items.h"
#include "ephemeral.h"
#include "stages.h"

GameState game_state = title_screen;

// 'universal frame' for animations not part of ents, a screen-ticker speed for wait times,
// record of the power_up_seq for which powerup will drop next, and where in the free-lives
// Aware scheme we are.
uint8_t u_frame{0}, screen_ticker = 0, power_up_seq = 0, freelivesseq = 1;

int freeMemory();

Stage *stage = new Stage();

uint8_t deathtime = DEATHTIME_MAX;
uint8_t prize_seq = 0;

// Static Memory content:
PlayerEntity *player = new PlayerEntity(ENT_POULET, 10.0f, 10.0f);
uint16_t spawnstatus = 0; // Bit flags for what is spawned or not.
Foe *foe_roster[FOE_MAX];
Balloon *balloon_roster[BALLOON_MAX];
EphemeralRoster ephemerals;
ItemRoster items;

Door *door = new Door(0, 0);


int16_t scroll = 0;
bool masterblink = true;



void advance_master_frames();
void next_stage();
void fade_out();
void fade_in();

// Object roster and allocations
void allocate_foes(Foe **roster);
void init_foes(Foe **roster);
void update_foes(Foe **roster);
void allocate_balloons(Balloon **roster);

void setup()
{
    ////Serial.begin(9600);
    initArduboy2();

    // Hardware stuff
    // arduboy->begin();
    arduboy->blank();
    arduboy->setFrameRate(60);
    // arduboy->display();

    // Static memory initializations:
    allocate_foes(foe_roster);
    allocate_balloons(balloon_roster);
    setup_level();

    // Game init stuff!
    door->x = (stage->exit_x * 8);
    door->y = (stage->exit_y * 8);
    //
    door->x = 1000;
    door->y = 40;
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
        draw_level(76, 30, stage->currentstage);
        screen_ticker += 1;
        if (screen_ticker >= SCREEN_TRANS_SPEED)
        {
            screen_ticker = 0;
            game_state = in_play;
        }
        break;

    case in_play:

        // If dead!
        if (player->death)
        {
            deathtime -= 1;
            if (deathtime <= 0)
            {
                game_state = interstitial;
                deathtime = DEATHTIME_MAX;
                setup_level();
            }
        }

        // Award lives?
        if (player->score >= freelivesseq * ONEUP_MILESTONE * (freelivesseq))
        {
            freelivesseq++;
            player->lives++;
            // Animated indicator of 1up using ephem system?
        }

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
        door->draw(scroll);
        stage->draw_coins(scroll);

        draw_hud();

        if (door->open)
        {
            fade_out();
            next_stage();
            start_level();
        }

        update_balloons(balloon_roster);
        update_foes(foe_roster);

        stage->get_coin(uint16_t(player->x + SPR_LFTSKIN), uint16_t(player->y + SPR_TOPSKIN), uint16_t(player->x + SPR_RGTSKIN), uint16_t(player->y + SPR_BOTSKIN));
        player->draw(scroll);
        player->control();
        player->physics(stage);

        items.updateRoster(stage, player, scroll, &ephemerals);
        ephemerals.updateRoster(scroll);

        // Debug HUD
        draw_digits(scroll / 64, 2, 16, 57);
        draw_digits((scroll / 64) + 1, 2, 32, 57);
        draw_digits(player->flyboy, 1, 48, 57);
        draw_digits(freeMemory(), 4, 100, 57);
        draw_digits(player->x, 3, 16, 9);

        // Some in game stuff:
        if (player->y > 56)
        {
            player->vx = 0;
            player->vy = 0;
            if (!player->death)
            {
                die();
            }
        }

        // Work out what should spawn!
        cleanup_spawns();
        check_for_spawn(scroll, 2);
        // check_for_spawn(scroll, -2);

        advance_master_frames();

        break;

    default:
        break;
    }

    arduboy->display();
}

inline void advance_master_frames()
{
    static uint8_t master_ticker = TICKER_SPEED;
    // Advance the frames of all animations.
    master_ticker--;
    if (master_ticker <= 0)
    {
        u_frame++;
        master_ticker = TICKER_SPEED;
        stage->tile_anim = !stage->tile_anim;
    }
}

inline void show_title_screen()
{

    Sprites::drawOverwrite(7, 11, smallpoulet, 0);
    Sprites::drawOverwrite(60, 16, titlecard, 0);
    Sprites::drawOverwrite(74, 36, aplus, 0);
    
}

inline void next_stage()
{
    spawnstatus = 0;
    stage->currentstage += 1;
    door->open = false;
    player->x = 0;
    scroll = 0;
}

inline void fade_out()
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
        stage->draw_coins(scroll);
        player->draw(scroll);
        arduboy->fillRect(0, 0, 128 - i, 64, BLACK);

        arduboy->display();
    }
}

void allocate_foes(Foe **roster)
{
    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        roster[i] = new Foe(ENT_FENNEC, 180 * i, 10);
        roster[i]->spawned = false;
        roster[i]->dead = true;
    }
}

void spawn_foe(Foe **roster, uint16_t newx, uint8_t newy, uint8_t etype)
{

    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        if (roster[i]->spawned == false)
        {
            roster[i]->x = newx;
            roster[i]->y = newy;
            roster[i]->spawned = true;
            roster[i]->dead = false;
            roster[i]->enttype = etype;
            roster[i]->assign_sprite();
            break;
        }
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

        if (roster[i]->x < (scroll - 128))
        {
            roster[i]->spawned = false;
            roster[i]->dead = true;
        }
        if (roster[i]->x > (scroll + 256))
        {
            roster[i]->spawned = false;
            roster[i]->dead = true;
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
                // player->attack = false; // Attack persists until touching ground!
                player->vy = -KILL_BOUNCE;
                player->score += 25;
            }
        }
    }
}

void allocate_balloons(Balloon **roster)
{
    // Build a static array for balloons
    for (uint8_t i = 0; i < BALLOON_MAX; i++)
    {
        roster[i] = new Balloon(0, 0);
        roster[i]->popped = true;
    }
}

void spawn_balloon(uint16_t newx, uint8_t newy)
{

    for (uint8_t i = 0; i < BALLOON_MAX; i++)
    {
        if (balloon_roster[i]->popped == true)
        {
            balloon_roster[i]->x = newx;
            balloon_roster[i]->y = newy;
            balloon_roster[i]->popped = false;
            break;
        }
    }
}

void update_balloons(Balloon **roster)
{
    // Draw them all on screen
    for (uint8_t i = 0; i < BALLOON_MAX; i++)
    {
        if (roster[i]->popped)
        {
            continue;
        }
        roster[i]->draw(scroll);

        if (roster[i]->collide(player))
        {
            ephemerals.add(roster[i]->x, roster[i]->y, pop);

            switch (prize_seq)
            {
            case PRIZE_TOQUE:
                items.add(roster[i]->x, roster[i]->y, PRIZE_TOQUE);
                break;

            case PRIZE_GLASSES:
                items.add(roster[i]->x, roster[i]->y, PRIZE_GLASSES);
                break;

            case PRIZE_1UP:
                items.add(roster[i]->x, roster[i]->y, PRIZE_1UP);
                break;

            default:
                break;
            }

            roster[i]->popped = true;
            prize_seq += 1;
            if(prize_seq > PRIZE_1UP){
                prize_seq = PRIZE_TOQUE;
            }
        }
    }
}

inline void draw_hud()
{
    draw_digits(player->score, 7, 78, 1);
    draw_lives(100, 1, player->lives);
    draw_level(1, 1, stage->currentstage);
}

void start_level()
{
    scroll = 0;
    if (stage->currentstage % 3 == 0)
    {
        game_state = interstitial;
    }
    else
    {
        game_state = in_play;
    }

    kill_all_foes();

    setup_level();
    // Check for spawns in this tile and one to the right:
    // check_for_spawn(scroll, 0);
    // check_for_spawn(scroll, 1);
    // check_for_spawn(scroll, 2);

    if (game_state == in_play)
    {
        fade_in();
    }
}

void setup_level()
{
    items.emptyRoster();
    stage->fill_coins();
    player->x = 8;
    player->y = 8;
    player->vx = 0;
    player->vy = 0;
    player->death = false;
}

int freeMemory()
{
    extern int __heap_start, *__brkval;
    int v;
    return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}

inline void die()
{
    player->death = true;
    player->lives -= 1;
    player->toque = false;
}

bool check_spawn_status(uint8_t position)
{
    uint16_t reversed_position = 15 - position;
    return (spawnstatus & (1 << reversed_position)) != 0;
}

void set_spawn_status(bool newstate, uint16_t position)
{
    uint16_t reversed_position = 15 - position;
    if (newstate == true)
    {
        spawnstatus |= (1 << reversed_position);
    }
    else
    {
        spawnstatus &= ~(1 << reversed_position);
    }
}

uint8_t spawn_type(uint8_t position)
{
    // Put some bounds checking here?
    if (position < 0)
    {
        return 0;
    }

    uint16_t slice_data = pgm_read_word(&stages[stage->currentstage * 16 + position]);
    return (slice_data >> 12) & 0x0F;
}

bool spawn_high(uint8_t position)
{
    uint16_t slice_data = pgm_read_word(&stages[stage->currentstage * 16 + position]);
    return (slice_data >> 11) & 0x01;
}

void cleanup_spawns()
{
    uint8_t meta_tile = (scroll / 64);
    for (uint8_t i; i < 16; i++)
    {
        if (i < (meta_tile - 1) || i > (meta_tile + 5))
        {
            set_spawn_status(false, i);
        }
    }
}

void kill_all_foes()
{

    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        foe_roster[i]->dead = true;
        foe_roster[i]->spawned = false;
    }
}

void check_for_spawn(uint16_t scroll_x, int8_t tile_offset)
{
    uint8_t meta_tile = (scroll_x / 64) + tile_offset;
    bool height = (spawn_high(meta_tile));

    uint16_t spawnheight = 0;

    if (check_spawn_status(meta_tile) == false)
    {
        //Serial.print("Unspawned chunk!:\n");
        //Serial.print("Meta Tile is: ");
        //Serial.println(meta_tile);
        //Serial.print("Type was: ");
        //Serial.println(spawn_type(meta_tile));

        uint16_t spawnx = ((meta_tile * 64) + 16);

        if (spawn_high(meta_tile) == true)
        {
            //Serial.print("...high\n");
            for (uint8_t i = 0; i < 40; i += 8)
            {

                if (stage->is_solid(spawnx, i + 16) == 0)
                {

                    spawnheight = i;
                    break;
                }
            }
        }
        else
        {
            //Serial.print("...low\n");
            for (uint8_t i = 40; i > 0; i -= 8)
            {
                if (stage->is_solid(spawnx, i + 16) == 0)
                {

                    spawnheight = i;
                    break;
                }
            }
        }

        //Serial.print("\n\nMetaTile: ");
        //Serial.print(meta_tile);
        //Serial.print("\nSpawn Coords chosen: ");
        //Serial.print(spawnx);
        //Serial.print(", ");
        //Serial.print(spawnheight);
        //Serial.print("\n");
        switch (spawn_type(meta_tile))
        {

        case SPAWN_BALLOON:
            spawn_balloon(spawnx, spawnheight);
            set_spawn_status(true, meta_tile);
            //Serial.print("BALLOON SPAWNED!\n");
            break;

        case SPAWN_FENNEC:
            spawn_foe(foe_roster, spawnx, spawnheight, ENT_FENNEC);
            set_spawn_status(true, meta_tile);
            //Serial.print("FENNEC SPAWNED!\n");
            break;

        case SPAWN_GOOB:
            spawn_foe(foe_roster, spawnx, spawnheight, ENT_GOOB);
            set_spawn_status(true, meta_tile);
            //Serial.print("GOOB SPAWNED!\n");
            break;

        case SPAWN_BLOOB:
            spawn_foe(foe_roster, spawnx, spawnheight, ENT_BLOOB);
            set_spawn_status(true, meta_tile);
            //Serial.print("BLOOB SPAWNED!\n");
            break;

        default:
            set_spawn_status(true, meta_tile);
            break;
        }
    }
}