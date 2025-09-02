#include <stdio.h>
#include <string.h>
#include <raylib.h>
#include <raymath.h>
#include "main.h"
#include "engine/player.h"
#include "engine/physics.h"

#define WINDOW_SIZE (Vector2){800, 400}

int main(int argc, char* argv[]) {
    printf("Beginning Raylib Project\n");
    
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Raylib Proj");
    SetExitKey(KEY_NULL);
    //ToggleBorderlessWindowed();
    handleArgs(argc, argv);
    
    Camera2D camera;
    camera.offset = (Vector2){WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2};
    camera.target = (Vector2){0, 0};
    camera.zoom = 1;
    camera.rotation = 0;
    
    RigidBody playerBody;
    playerBody.body.collision = (Collision){RECTANGLE, (Rectangle){0, 0, 50, 50}};
    playerBody.body.position = (Vector2){0, 0};
    playerBody.acceleration = Vector2Zero();
    playerBody.gravity = Vector2Scale(V_GRAVITY, 0.5);
    playerBody.mass = 75;
    playerBody.velocity = Vector2Zero();
    Player player = {camera, playerBody};
    
    int test = 0;
    SetTargetFPS(60);
    while (!WindowShouldClose()) {
        
        
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(player.camera);
                player_logic_loop(&player);
                draw_rbody(&player.rbody, BLUE);
                DrawRectangle(100, 100, 50, 50, RED);
            EndMode2D();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}

void handleArgs(int argc, char* argv[]) {
    for (int i = 1; i < argc; i++) { //skip first arg since it's just the program name
        char* arg = argv[i];

        if (!strcmp(arg, "debug")) {
            SetExitKey(KEY_DELETE);
            continue;
        }
    }
}