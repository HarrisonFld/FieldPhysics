#include <stdio.h>
#include <raylib.h>
#include <raymath.h>
#include "player.h"
#include "physics.h"


//player logic called every game loop
void player_logic_loop(Player* player) {
    Vector2 move = Vector2Scale(get_wasd_vector2(), PIXELS_TO_METER);
    if (player->rbody.is_on_floor && IsKeyDown(KEY_LEFT_SHIFT)) {
        move = Vector2Scale(move, 3); //some basic running (temp)
    }
    move = Vector2Scale(move, GetFrameTime());
    move_body(&player->rbody.body, move);

    //some basic jumping 
    if (player->rbody.is_on_floor && IsKeyUp(KEY_SPACE) && FLOOR_ON) {
        player->rbody.body.position.y = 100;
    }
    if (player->rbody.is_on_floor && IsKeyPressed(KEY_SPACE)) {
        impulse_rbody(&player->rbody, (Vector2){0, -350});
    }

    printf("A: %f : V: %f : P: %f\n", player->rbody.actual_acceleration.y, player->rbody.velocity.y, player->rbody.body.position.y / PIXELS_TO_METER);
    
    rbody_logic_loop(&player->rbody);
    player->camera.target = player->rbody.body.position;
}


Vector2 get_wasd_vector2() {
    float x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    float y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    return (Vector2){x, y};
}