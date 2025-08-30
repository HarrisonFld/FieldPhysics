#pragma once

#include <raylib.h>
#include "physics.h"

typedef struct Player {
    Camera2D camera;
    Body body;
} Player;

void player_logic_loop(Player* player); //Player logic loop called every game loop