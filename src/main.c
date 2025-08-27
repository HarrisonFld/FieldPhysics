#include <stdio.h>
#include "main.h"
#include "raylib.h"

#define WINDOW_SIZE (Vector2){800, 400}

int main() {
    printf("Beginning Raylib Project\n");
    
    int curMonitor = GetCurrentMonitor();
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Raylib Proj");
    //ToggleBorderlessWindowed();
    
    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Project Begin!", 200, 200, 50, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}