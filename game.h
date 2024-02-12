#pragma once


enum GameState{
    title_screen = 0,
    in_play,
    game_over
};

enum PlayerAnimState{
    standing = 0,
    walking,
    jumping_up,
    jumping_down,
    attacking,
    dead
};