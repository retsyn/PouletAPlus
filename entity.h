#pragma once

#include "graphics.h"
#include "tilemap.h"

#define ENT_DUD 0
#define ENT_POULET 1
#define ENT_FENNEC 2
#define ENT_GOOB 3
#define ENT_BLOOB 4

#define SPAWN_NOTHING 0
#define SPAWN_BALLOON 1
#define SPAWN_FENNEC 2
#define SPAWN_GOOB 3
#define SPAWN_BLOOB 4

#define SPR_WAIT 6
#define SPR_TOPSKIN 9
#define SPR_BOTSKIN 15
#define SPR_LFTSKIN 4
#define SPR_RGTSKIN 11


// Foe speeds:
#define SPEED_FENNEC 10

#define DEATH_ANIM 90

// Game Rule stuff.
#define PLAYER_IFRAMES 130

// Player physics:
#define PLAYER_JUMPPOWER 1.20f
#define PLAYER_ACCEL 0.15f
#define PLAYER_TOPSPEED 0.75f
#define PLAYER_JUMP_BUFFER_TIME 12
#define PLAYER_COYOTE_TIME 10
#define HORIZ_ATTACK_SPEED 2.0f
#define VERT_ATTACK_SPEED 1.5f
#define JUMP_JUICE 0.043f

// World physics
#define PHYS_GRAVITY 0.07f
#define PHYS_FRICTION 0.06f

enum PlayerAnimState
{
    idle = 0,
    walking,
    jumping_up,
    jumping_down,
    attacking,
    deading
};

enum FoeState
{
    moving = 0,
    dying,
};

enum FoeAI
{
    miller = 0,
    flyer,
    hflyer
};

class Foe;

class Entity
{
protected:
    // Anim state vars:
    uint8_t anim_frame = 0;
    uint8_t anim_ticker = 0;
    uint8_t anim_state = 0;

    // Precalc framelengths--
    const uint8_t FRAMELEN[3] = {0, 2, 0};

public:
    float vx = 0.0f;
    float vy = 0.0f;

    //float top_speed = 1.0f;
    float accel = 0.1f;

    uint16_t score = 0;
    uint8_t lives = 5;

    bool flying : 1;
    bool blinkon : 1;
    bool death : 1;
    bool grounded : 1;

    bool flip : 1;
    bool attack : 1;
    bool blinking : 1;

    uint8_t iframes = 0;


    uint8_t type = 0;
    float x = 0.0f;
    float y = 0.0f;
    const unsigned char *sprite;

    Entity(uint8_t newtype, float start_x, float start_y);
    virtual void draw(int16_t offset_x);
    void physics(Stage *in_stage);
};

class PlayerEntity : public Entity
{
public:
    bool flyboy = false;
    bool toque = false;
    uint8_t skidding = 0;
    uint8_t coyote_buffer = 0;

    PlayerEntity(uint8_t newtype, float start_x, float start_y);
    void control();
    void draw(int16_t offset_x) override;
    void takehit(Foe *hitter);

protected:
    // Precalc framelengths--
    const uint8_t FRAMELEN[6] = {0, 3, 0, 0, 0, 0};

    uint8_t jump_buffer = 0;
};

class Foe
{
public:
    bool spawned : 1;
    bool dead : 1;
    bool flip : 1;
    bool anim_bit : 1; // Just two frames.  We gotta be elfin'.

    uint8_t enttype = ENT_DUD;
    int16_t x = 0;
    uint8_t y = 0;
    uint8_t timer = 0; // We aren't using any floats for enemies, so we have a timer ticker.
    // When enemies die they probably won't fly away, just blink.

    void draw(int16_t offset);
    void update(Stage *stage, PlayerEntity *player);
    bool collide(PlayerEntity *player);
    void assign_sprite();

    Foe(uint8_t newtype, uint16_t start_x, uint8_t start_y);
    unsigned char *sprite;
};
