#include <stdio.h>
#include <string.h>
#include <raylib.h>
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
    
    Body playerBody;
    playerBody.collision = (Collision){RECTANGLE, (Rectangle){0, 0, 50, 50}};
    playerBody.position = (Vector2){0, 0};
    Player player = {camera, playerBody};
    
    while (!WindowShouldClose()) {
        move_body(&player.body, (Vector2){0.001, 0.001});
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(camera);
                DrawRectangleV(player.body.position, (Vector2){player.body.collision.shape.rect.width, player.body.collision.shape.rect.height}, GREEN);
                   
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