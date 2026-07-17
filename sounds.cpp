#include "globals.h"
#include "sounds.h"

// Constructed with Arduboy2's audio-enabled function so all sound
// automatically honours the saved mute state.
ArduboyTones sound(Arduboy2Audio::enabled);

// ---- Tone sequences (flash/PROGMEM, ~4 bytes per note) ----
// Format: NOTE, duration_ms, ... TONES_END

static const uint16_t seq_jump[] PROGMEM = {
    NOTE_E5H, 13,  NOTE_FS5H, 13,  NOTE_G5H, 13, TONES_END};

static const uint16_t seq_coin[] PROGMEM = {
    NOTE_F5H, 26,  NOTE_C6H, 26,
    TONES_END};

static const uint16_t seq_stomp[] PROGMEM = {
    NOTE_DS3H, 13,  NOTE_A5H, 13,  NOTE_GS3H, 13,  NOTE_A3H, 13,
    NOTE_C4H, 13,  NOTE_D4H, 13,  NOTE_C6H, 13,
    TONES_END};

static const uint16_t seq_pop[] PROGMEM = {
    NOTE_GS4H, 13,  NOTE_CS4H, 13,  NOTE_E6H, 13,  NOTE_A3H, 13,
    NOTE_AS3H, 13,  NOTE_B3H, 13,  NOTE_G3H, 13,  NOTE_B3H, 13,
    TONES_END};

static const uint16_t seq_powerup[] PROGMEM = {
    NOTE_G3H, 26,  NOTE_E3H, 26,  NOTE_G3H, 26,  NOTE_C4H, 26,
    NOTE_G4H, 26,  NOTE_E5H, 26,  NOTE_C6H, 26,  NOTE_G6H, 26,
    TONES_END};

static const uint16_t seq_oneup[] PROGMEM = {
    NOTE_G5, 55, NOTE_C6, 55, NOTE_E6, 55, NOTE_G6, 130, TONES_END};

static const uint16_t seq_hurt[] PROGMEM = {
    NOTE_G4, 40, NOTE_DS4, 80, TONES_END};

static const uint16_t seq_die[] PROGMEM = {
    NOTE_E5H, 13,  NOTE_FS5H, 13,  NOTE_G5H, 13,  NOTE_CS6H, 13,
    NOTE_FS6H, 13,  NOTE_A6H, 13,  NOTE_G6H, 13,  NOTE_D6H, 13,
    NOTE_GS5H, 13,  NOTE_E5H, 13,  NOTE_DS5H, 13,  NOTE_D5H, 13,
    NOTE_DS5H, 13,
    TONES_END};

static const uint16_t seq_clear[] PROGMEM = {
    NOTE_C5, 70, NOTE_F5, 70, NOTE_A5, 70, NOTE_C6, 140, NOTE_A5, 70, NOTE_C6, 300, TONES_END};

static const uint16_t seq_start[] PROGMEM = {
    NOTE_C5, 50, NOTE_G5, 50, NOTE_C6, 120, TONES_END};

// ---- Players ----
void sfx_jump()    { sound.tones(seq_jump); }
void sfx_coin()    { sound.tones(seq_coin); }
void sfx_stomp()   { sound.tones(seq_stomp); }
void sfx_pop()     { sound.tones(seq_pop); }
void sfx_powerup() { sound.tones(seq_powerup); }
void sfx_oneup()   { sound.tones(seq_oneup); }
void sfx_hurt()    { sound.tones(seq_hurt); }
void sfx_die()     { sound.tones(seq_die); }
void sfx_clear()   { sound.tones(seq_clear); }
void sfx_start()   { sound.tones(seq_start); }
