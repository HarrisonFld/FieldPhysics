#include <stdio.h>
#include "main.h"
#include "raylib.h"

int main() {
    printf("Beginning Raylib Project\n");
    
    int curMonitor = GetCurrentMonitor();
    InitWindow(GetMonitorWidth(curMonitor), GetMonitorHeight(curMonitor), "Raylib Proj");
    ToggleBorderlessWindowed();

    while (!WindowShouldClose()) {
        BeginDrawing();
            ClearBackground(BLACK);
            DrawText("Project Begin!", 200, 200, 50, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}