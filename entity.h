#pragma once

#include "graphics.h"
#include "tilemap.h"

#define ENT_DUD 0
#define ENT_POULET 1
#define ENT_FENNEC 2

#define SPR_WAIT 6
#define SPR_TOPSKIN 9
#define SPR_BOTSKIN 15
#define SPR_LFTSKIN 4
#define SPR_RGTSKIN 11

#define PLAYER_JUMPPOWER 1.20f
#define PLAYER_ACCEL 0.15f
#define PLAYER_TOPSPEED 0.70f
#define PLAYER_JUMP_BUFFER_TIME 12
#define PLAYER_COYOTE_TIME 10
#define HORIZ_ATTACK_SPEED 2.0f

#define VERT_ATTACK_SPEED 1.5f
#define JUMP_JUICE 0.043f

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

class Entity
{
protected:
    // Anim state vars:
    uint8_t anim_frame;
    uint8_t anim_ticker;

    uint8_t anim_state;
    bool attack = false;
    bool flying = false;

    // Precalc framelengths--
    const uint8_t FRAMELEN[3] = {0, 2, 0};

public:
    float vx = 0.0f;
    float vy = 0.0f;

    float top_speed = 1.0f;
    float accel = 0.1f;

    bool grounded;
    bool flip;
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
    uint8_t skidding = 0;
    uint8_t coyote_buffer = 0;

    PlayerEntity(uint8_t newtype, float start_x, float start_y);
    void control();
    void draw(int16_t offset_x) override;

protected:
    // Precalc framelengths--
    const uint8_t FRAMELEN[6] = {0, 3, 0, 0, 0, 0};

    uint8_t jump_buffer = 0;
};

class Foe : public Entity
{
public:
    bool dead = false;
    bool spawned = false;

    Foe(uint8_t newtype, float start_x, float start_y);
    void draw(int16_t offset_x) override;
    void think(Stage *in_stage, PlayerEntity *player);

    void kill();
};

