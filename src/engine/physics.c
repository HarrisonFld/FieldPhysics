#include "physics.h"
#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "world.h"

#include <stdio.h>

void move_body(Body* body, Vector2 move) {
    body->position.x += move.x;
    body->position.y += move.y;
}


//Rigidbodies
void rbody_logic_loop(RigidBody *rbody) { 
    if (rbody->body.position.y >= 0) { //temporary is_on_floor calculations
        rbody->is_on_floor = true;
    } else {
        rbody->is_on_floor = false;
    }
    
    //Apply acceleration on to velocity
    Vector2 af = rbody->acceleration; //Apply acceleration
    af = Vector2Add(af, rbody->gravity); //Apply gravity
    rbody->actual_acceleration = af;
    rbody->velocity = Vector2Add(rbody->velocity, Vector2Scale(rbody->actual_acceleration, GetFrameTime()));

    //temporary floor + velocity
    if (rbody->is_on_floor && FLOOR_ON) { 
       rbody->velocity.y = fmin(rbody->velocity.y, 0);
    }
    
    //Apply velocity on to position
    Vector2 vf = Vector2Scale(rbody->velocity, GetFrameTime());
    Vector2 pf = Vector2Add(rbody->body.position, vf);
    rbody->body.position = pf;
}

void force_rbody(RigidBody* rbody, Vector2 force) {
    Vector2 acceleration = Vector2Scale(force, 1.0f / rbody->mass);
    rbody->acceleration = acceleration;
}

void impulse_rbody(RigidBody* rbody, Vector2 impulse) {
    Vector2 deltaV = Vector2Scale(impulse, 1.0f / rbody->mass);
    rbody->velocity = Vector2Add(rbody->velocity, deltaV);
}



//Utilities
void draw_body(Body *body, Color color) {
    Vector2 pos = Vector2Scale(body->position, METER_TO_PIXELS);
    Collision col = body->collision;
    switch (col.shapeType) {
        case RECTANGLE:
        {
            Vector2 shape = Vector2Scale(
                (Vector2){col.shape.rect.width, col.shape.rect.height}, 
                METER_TO_PIXELS
            );
            DrawRectangle(pos.x, pos.y, 
                shape.x, shape.y, color);
            break;
        }
        case CIRCLE:
            DrawCircle(body->position.x, body->position.y, 
                col.shape.circ.radius, color);
            break;
    }
}

void draw_rbody(RigidBody *rbody, Color color) {
    draw_body(&rbody->body, color);
}
