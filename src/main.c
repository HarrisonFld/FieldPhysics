#include <stdio.h>
#include <string.h>
#include <raylib.h>
#include <glib.h>
#include "main.h"

#define WINDOW_SIZE (Vector2){800, 400}

int main(int argc, char* argv[]) {
    printf("Beginning Raylib Project\n");
    
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Raylib Proj");
    SetExitKey(KEY_NULL);
    //ToggleBorderlessWindowed();
    handleArgs(argc, argv);
    
    Camera2D camera;
    camera.offset = (Vector2){WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2};
    camera.target = (Vector2){100, 100};
    camera.zoom = 1;
    
    while (!WindowShouldClose()) {
        if (IsKeyPressedRepeat(KEY_A)) {
            camera.target.x += 1 * GetFrameTime();
            printf("test");
        } 

        BeginDrawing();
            DrawRectangle(50, 50, 50, 50, BLUE);
            DrawRectangle(10, 50, 50, 50, GREEN);
            BeginMode2D(camera);
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