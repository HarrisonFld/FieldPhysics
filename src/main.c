#include <stdio.h>
#include <string.h>
#include <raylib.h>
#include <raymath.h>
#include "main.h"
#include "player.h"
#include "physics.h"
#include "world.h"
#include "draw.h"

static Vector2 WINDOW_SIZE = (Vector2){800, 400};

int main(int argc, char* argv[]) {
    printf("Beginning Raylib Project\n");
    
    InitWindow(WINDOW_SIZE.x, WINDOW_SIZE.y, "Raylib Proj");
    SetExitKey(KEY_NULL);
    handleArgs(argc, argv);
    //ToggleBorderlessWindowed();
    //WINDOW_SIZE = (Vector2){GetMonitorWidth(GetCurrentMonitor()), GetMonitorHeight(GetCurrentMonitor())};
    //SetWindowSize(WINDOW_SIZE.x, WINDOW_SIZE.y);
    
    Camera2D camera;
    camera.offset = (Vector2){WINDOW_SIZE.x / 2, WINDOW_SIZE.y / 2};
    camera.zoom = 1;
    camera.rotation = 0;
    
    RigidBody playerBody;
    playerBody.body.collision = (Collision){RECTANGLE, (Rectangle){0, 0, 0.5, 0.5}};
    playerBody.body.position = (Vector2){0, 0};
    playerBody.body.rotation = 0;
    playerBody.body.origin = (Vector2){0.25, 0.5};
    playerBody.acceleration = Vector2Zero();
    playerBody.gravity = Vector2Scale(V_GRAVITY, 1);
    playerBody.mass = 75;
    playerBody.velocity = Vector2Zero();
    Player player = {camera, playerBody};

    player.camera.target = playerBody.body.origin;

    //SetTargetFPS(60);
    while (!WindowShouldClose()) {
        printf("Y - A: %f : V: %f : P: %f\n", player.rbody.actual_acceleration.y, player.rbody.velocity.y, player.rbody.body.position.y);
        printf("X - A: %f : V: %f : P: %f\n", player.rbody.actual_acceleration.x, player.rbody.velocity.x, player.rbody.body.position.x);
        //force_rbody(&player.rbody, (Vector2){0, -1500});

        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(player.camera);
                draw_axes(true, true, &player.camera, 1);

                draw_rbody(&player.rbody, BLUE);
                player_logic_loop(&player);

                Rectangle rect = {0, 0, METER_TO_PIXELS * 0.5 , METER_TO_PIXELS * 0.5};
                DrawRectanglePro(rect, (Vector2){rect.width / 2, rect.height}, 0, RED);

                Vector2 pos = player.rbody.body.position;
                Rectangle rect_test = player.rbody.body.collision.shape.rect;
                Rectangle tester = {pos.x * METER_TO_PIXELS, pos.y * METER_TO_PIXELS, rect_test.width * METER_TO_PIXELS, rect_test.height * METER_TO_PIXELS};
                //printf("%f %f\n", tester.x, tester.y);
                printf("%d", CheckCollisionRecs(rect, tester));
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