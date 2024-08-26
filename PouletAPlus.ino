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

static GameState game_state = title_screen;

// 'universal frame' for animations not part of ents, a screen-ticker speed for wait times,
// record of the power_up_seq for which powerup will drop next, and where in the free-lives
// Aware scheme we are.
static uint8_t u_frame{0}, screen_ticker = 0, power_up_seq = 0, freelivesseq = 1;

// int freeMemory();

static Stage stage;

static uint8_t deathtime = DEATHTIME_MAX;
static uint8_t prize_seq = 0;

// Static Memory content:
static PlayerEntity player(ENT_POULET, 10.0f, 10.0f);
static uint16_t spawnstatus = 0; // Bit flags for what is spawned or not.
static Foe foe_roster[FOE_MAX];
static Balloon balloon_roster[BALLOON_MAX];
static EphemeralRoster ephemerals;
static ItemRoster items;

static Door door;
static Pole pole;

static int16_t scroll = 0;
static bool masterblink = true;

static void advance_master_frames();
static void next_stage();
static void fade_out();
static void fade_in();

// Object roster and allocations
static void allocate_foes();
static void init_foes();
static void update_foes();
static void allocate_balloons();

static void setup()
{
    // serial.begin(9600);
    initArduboy2();

    // Hardware stuff
    // arduboy->begin();
    arduboy->blank();
    arduboy->setFrameRate(60);
    // arduboy->display();

    // Static memory initializations:
    allocate_foes();
    allocate_balloons();
    setup_level();

    // Game init stuff!
    door.x = (stage.exit_x * 8);
    door.y = (stage.exit_y * 8);
    //
    door.x = 1000;
    door.y = 40;
}

static void loop()
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
        SpritesB::drawOverwrite(36, 30, stage_label, 0);
        draw_level(76, 31, stage.currentstage);
        screen_ticker += 1;
        if (screen_ticker >= SCREEN_TRANS_SPEED)
        {
            screen_ticker = 0;
            game_state = in_play;
        }
        break;

    case in_play:

        // Set up pole:
        if (stage.currentstage % 3 == 2)
        {
            pole.on = true;
            door.on = false;
        }
        else
        {
            pole.on = false;
            door.on = true;
        }

        // If dead!
        if (player.death)
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
        if (player.score >= freelivesseq * ONEUP_MILESTONE * (freelivesseq))
        {
            freelivesseq++;
            player.lives++;
            // Animated indicator of 1up using ephem system?
        }

        // Debug scroll?
        scroll = floor(player.x - 64);
        if (scroll < 0)
        {
            scroll = 0;
        }
        else if (scroll > 1024 - 128)
        {
            scroll = 1024 - 128;
        }
        stage.draw_level(scroll);

        // pole.update(&player);
        pole.draw(scroll);

        door.update(&player);
        pole.update(&player);
        door.draw(scroll);
        stage.draw_coins(scroll);

        draw_hud();

        if (door.open)
        {
            advance_stage();
        }

        update_balloons();
        update_foes();

        if (stage.get_coin(uint16_t(player.x + SPR_LFTSKIN), uint16_t(player.y + SPR_TOPSKIN), uint16_t(player.x + SPR_RGTSKIN), uint16_t(player.y + SPR_BOTSKIN)))
        {
            player.score += 5;
        }
        player.draw(scroll);
        player.control();
        if (player.physics(&stage))
            player.hitspike();

        items.updateRoster(&stage, &player, scroll, &ephemerals);
        if(ephemerals.updateRoster(scroll, player.x, player.y)){
            player.hitspike();
        }

        // Some in game stuff:
        if (player.y > 56)
        {
            player.vx = 0;
            player.vy = 0;
            if (!player.death)
            {
                die();
            }
        }

        // Work out what should spawn!
        cleanup_spawns();
        check_for_spawn(scroll, 3);
        check_for_spawn(scroll, -2);

        advance_master_frames();

        // If a flagpole was touched and the player is "celebrating"
        if (player.celebrate)
        {
            SpritesB::drawOverwrite(28, 30, stage_label, 0);
            SpritesB::drawOverwrite(66, 30, done_label, 0);
            screen_ticker += 1;
            if (screen_ticker > LEVEL_END_SPEED)
            {
                screen_ticker = 0;
                advance_stage();
            }
        }

        break;

    default:
        break;
    }

    arduboy->display();
}

static void advance_stage()
{
    fade_out();
    next_stage();
    start_level();
    player.celebrate = 0;
}

static void advance_master_frames()
{
    static uint8_t master_ticker = TICKER_SPEED;
    // Advance the frames of all animations.
    master_ticker--;
    if (master_ticker <= 0)
    {
        u_frame++;
        master_ticker = TICKER_SPEED;
        stage.tile_anim = !stage.tile_anim;
    }
}

static void show_title_screen()
{

    SpritesB::drawSelfMasked(7, 11, smallpoulet, 0);
    SpritesB::drawSelfMasked(60, 16, titlecard, 0);
    SpritesB::drawSelfMasked(74, 36, aplus, 0);
}

static void next_stage()
{
    spawnstatus = 0;
    stage.currentstage += 1;
    door.open = false;
    player.x = 0;
    scroll = 0;
}

static void fade_out()
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

static void fade_in()
{
    for (uint8_t i = 1; i < 128; i += 5)
    {
        if (!arduboy->nextFrame())
        {
            i -= 5;
        }
        stage.draw_level(scroll);
        stage.draw_coins(scroll);
        player.draw(scroll);
        arduboy->fillRect(0, 0, 128 - i, 64, BLACK);

        arduboy->display();
    }
}

static void allocate_balloons()
{
    for (uint8_t i = 0; i < BALLOON_MAX; i++)
    {
        balloon_roster[i] = Balloon(0, 0);
        balloon_roster[i].popped = true;
    }
}

static void allocate_foes()
{
    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        foe_roster[i] = Foe(ENT_FENNEC, 180, 10);
        foe_roster[i].x = 180 * i;
        foe_roster[i].spawned = false;
        foe_roster[i].dead = true;
    }
}

static void spawn_foe(uint16_t newx, uint8_t newy, uint8_t etype)
{

    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        if (foe_roster[i].spawned == false)
        {
            foe_roster[i].x = newx;
            foe_roster[i].y = newy;
            foe_roster[i].spawned = true;
            foe_roster[i].dead = false;
            foe_roster[i].act = false;
            foe_roster[i].enttype = etype;
            foe_roster[i].assign_sprite();
            break;
        }
    }
}

static void update_foes()
{
    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        foe_roster[i].update(&stage, &player, &ephemerals);
        foe_roster[i].draw(scroll);

        // No need to operate on dead foes.
        if (foe_roster[i].dead)
        {
            continue;
        }

        if (foe_roster[i].x < (scroll - 128))
        {
            foe_roster[i].spawned = false;
            foe_roster[i].dead = true;
        }
        if (foe_roster[i].x > (scroll + 256))
        {
            foe_roster[i].spawned = false;
            foe_roster[i].dead = true;
        }

        if (foe_roster[i].collide(&player))
        {
            if (!player.attack)
            {
                player.takehit(&foe_roster[i]);
            }
            else
            {
                foe_roster[i].dead = true;
                // player.attack = false; // Attack persists until touching ground!
                player.vy = -KILL_BOUNCE;
                player.score += 25;
            }
        }
    }
}

static void spawn_balloon(uint16_t newx, uint8_t newy)
{

    for (uint8_t i = 0; i < BALLOON_MAX; i++)
    {
        if (balloon_roster[i].popped == true)
        {
            balloon_roster[i].x = newx;
            balloon_roster[i].y = newy;
            balloon_roster[i].popped = false;
            break;
        }
    }
}

static void update_balloons()
{
    // Draw them all on screen
    for (uint8_t i = 0; i < BALLOON_MAX; i++)
    {
        if (balloon_roster[i].popped)
        {
            continue;
        }
        balloon_roster[i].draw(scroll);

        if (balloon_roster[i].collide(&player))
        {
            ephemerals.add(balloon_roster[i].x, balloon_roster[i].y, pop, 0, 0);

            switch (prize_seq)
            {
            case PRIZE_TOQUE:
                items.add(balloon_roster[i].x, balloon_roster[i].y, PRIZE_TOQUE);
                break;

            case PRIZE_GLASSES:
                items.add(balloon_roster[i].x, balloon_roster[i].y, PRIZE_GLASSES);
                break;

            case PRIZE_1UP:
                items.add(balloon_roster[i].x, balloon_roster[i].y, PRIZE_1UP);
                break;

            default:
                break;
            }

            balloon_roster[i].popped = true;
            prize_seq += 1;
            if (prize_seq > PRIZE_1UP)
            {
                prize_seq = PRIZE_TOQUE;
            }
        }
    }
}

static void draw_hud()
{
    draw_digits(player.score, 7, 80, 0);
    draw_lives(96, 0, player.lives);
    draw_level(1, 0, stage.currentstage);
}

static void start_level()
{
    scroll = 0;
    if (stage.currentstage % 3 == 0)
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
    check_for_spawn(scroll, 0);
    check_for_spawn(scroll, 1);
    check_for_spawn(scroll, 2);

    if (game_state == in_play)
    {
        fade_in();
    }
}

static void setup_level()
{
    items.emptyRoster();
    stage.fill_coins();
    player.x = 8;
    player.y = 8;
    player.vx = 0;
    player.vy = 0;
    player.death = false;
}

/*
int freeMemory()
{
    extern int __heap_start, *__brkval;
    int v;
    return (int)&v - (__brkval == 0 ? (int)&__heap_start : (int)__brkval);
}
*/

static void die()
{
    player.death = true;
    player.lives -= 1;
    player.toque = false;
    player.flyboy = false;
}

static bool check_spawn_status(uint8_t position)
{
    uint16_t reversed_position = 15 - position;
    return (spawnstatus & (1 << reversed_position)) != 0;
}

static void set_spawn_status(bool newstate, uint16_t position)
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

static uint8_t spawn_type(uint8_t position)
{
    // Put some bounds checking here?
    if ((int8_t)position < 0)
    {
        return 0;
    }

    uint16_t slice_data = pgm_read_word(&stages[stage.currentstage * 16 + position]);
    return (slice_data >> 12) & 0x0F;
}

static bool spawn_high(uint8_t position)
{
    uint16_t slice_data = pgm_read_word(&stages[stage.currentstage * 16 + position]);
    return (slice_data >> 11) & 0x01;
}

static void cleanup_spawns()
{
    uint8_t meta_tile = (scroll / 64);
    for (uint8_t i = 0; i < 16; i++)
    {
        if (i < (meta_tile - 2) || i > (meta_tile + 5))
        {
            set_spawn_status(false, i);
        }
    }
}

static void kill_all_foes()
{

    for (uint8_t i = 0; i < FOE_MAX; i++)
    {
        foe_roster[i].dead = true;
        foe_roster[i].act = false;
        foe_roster[i].spawned = false;
    }
}

static void check_for_spawn(uint16_t scroll_x, int8_t tile_offset)
{
    uint8_t meta_tile = (scroll_x / 64) + tile_offset;

    uint16_t spawnheight = 0;

    if (check_spawn_status(meta_tile) == false)
    {
        uint16_t spawnx = ((meta_tile * 64) + 16);
        if (spawn_high(meta_tile) == true)
        {
            for (uint8_t i = 0; i < 40; i += 8)
            {
                if (stage.is_solid(spawnx, i + 16) == 0)
                {
                    spawnheight = i;
                    break;
                }
            }
        }
        else
        {
            for (uint8_t i = 40; i > 0; i -= 8)
            {
                if (stage.is_solid(spawnx, i + 16) == 0)
                {
                    spawnheight = i;
                    break;
                }
            }
        }

        switch (spawn_type(meta_tile))
        {
        case SPAWN_BALLOON:
            spawn_balloon(spawnx, spawnheight);
            break;

        case SPAWN_FENNEC:
            spawn_foe(spawnx, spawnheight, ENT_FENNEC);
            break;

        case SPAWN_GOOB:
            spawn_foe(spawnx, spawnheight, ENT_GOOB);
            break;

        case SPAWN_BLOOB:
            spawn_foe(spawnx, spawnheight, ENT_BLOOB);
            break;

        case SPAWN_DRAKE:
            spawn_foe(spawnx, spawnheight, ENT_DRAKE);
            break;

        default:
            break;
        }

        set_spawn_status(true, meta_tile);

    }
}
