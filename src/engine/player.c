#include <raylib.h>
#include <raymath.h>
#include "player.h"


//player logic called every game loop
void player_logic_loop(Player* player) {
    Vector2 move = Vector2Scale(get_wasd_vector2(), 100);
    move = Vector2Scale(move, GetFrameTime());
    move_body(&player->body, move);
    player->camera.target = player->body.position;
}


Vector2 get_wasd_vector2() {
    float x = IsKeyDown(KEY_D) - IsKeyDown(KEY_A);
    float y = IsKeyDown(KEY_S) - IsKeyDown(KEY_W);
    return (Vector2){x, y};
}