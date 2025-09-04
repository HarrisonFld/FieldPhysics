#pragma once

#include <raylib.h>
#include "physics.h"

typedef struct Player {
    Camera2D camera;
    RigidBody rbody;
} Player;

void player_logic_loop(Player* player); //Player logic loop called every game loop

//input
Vector2 get_wasd_vector2(); //Return a Vector2 representing the WASD user input