#include <stdio.h>
#include <string.h>
#include <raylib.h>
#include <raymath.h>
#include "main.h"
#include "physics_engine.h"
#include "collision.h"
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
    
    RigidBody playerBody = create_rbody(create_body((Vector2){1,0}, 0, (Collision){RECTANGLE, (Rectangle){0, 0, 0.5, 0.5} }), 75);
    Player player = {camera, playerBody};
    player.camera.target = playerBody.body.origin;

    RigidBody redBody = create_rbody(create_body((Vector2){0,0}, 0, (Collision){RECTANGLE, (Rectangle){0, 0, 0.5, 0.5} }), 65);

    PhysicsEngine engine = create_physics_engine();
    add_rbody_2_engine(&engine, &redBody);
    add_rbody_2_engine(&engine, &player.rbody);

    //SetTargetFPS(60);
    while (!WindowShouldClose()) {
        //printf("Y - A: %f : V: %f : P: %f\n", player.rbody.actual_acceleration.y, player.rbody.velocity.y, player.rbody.body.position.y);
        //printf("X - A: %f : V: %f : P: %f\n", player.rbody.actual_acceleration.x, player.rbody.velocity.x, player.rbody.body.position.x);
        physics_engine_logic_loop(&engine);
        BeginDrawing();
            ClearBackground(BLACK);
            BeginMode2D(player.camera);
                draw_axes(true, true, &player.camera, 1);

                draw_rbody(&redBody, RED);

                draw_rbody(&player.rbody, BLUE);
                player_logic_loop(&player);
                

                //TESTING
                Rectangle col = GetCollisionRec(b2pr(&redBody.body), b2pr(&player.rbody.body));
                DrawRectanglePro(col, player.rbody.body.origin, 0, PINK);
                
                //Very basic collision code
                if (col.width != 0 || col.height != 0) {
                    collision_rbody_rbody(&player.rbody, &redBody);
                }
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
