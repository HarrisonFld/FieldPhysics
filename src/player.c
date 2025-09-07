#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include "player.h"
#include "physics.h"
#include "world.h"


//player logic called every game loop
void player_logic_loop(Player* player) {
    //some basic movement TODO: make it based off forces/physics
    Vector2 move = get_wasd_vector2();
    if (player->rbody.is_on_floor && IsKeyDown(KEY_LEFT_SHIFT)) {
        move = Vector2Scale(move, 3); //some basic running (temp)
    }
    //force_rbody(&player->rbody, move);
    //move = Vector2Scale(move, GetFrameTime());
    move = Vector2Scale(move, 200);
    force_rbody(&player->rbody, move);

    //some basic jumping 
    if (player->rbody.is_on_floor && IsKeyUp(KEY_SPACE) && FLOOR_ON) {
        player->rbody.body.position.y = 0;
    }
    if (player->rbody.is_on_floor && IsKeyPressed(KEY_SPACE)) {
        impulse_rbody(&player->rbody, (Vector2){0, -350});
    }    

    //rbody_logic_loop(&player->rbody);
    player->camera.target = Vector2Scale(player->rbody.body.position, METER_TO_PIXELS);
}


Vector2 get_wasd_vector2() {
    float x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    float y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    return (Vector2){x, y};
}