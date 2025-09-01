#include <raylib.h>
#include <raymath.h>
#include "physics.h"

//For when it's needed~~~
/* switch (body->collision.shapeType) {
        case RECTANGLE:
            body->collision.shape.rect.x = position.x;
            body->collision.shape.rect.y = position.y;
            break;
        case CIRCLE:
            body->collision.shape.circ.center.x = position.x;
            body->collision.shape.circ.center.y = position.y;
            break;
    } */

void move_body(Body* body, Vector2 move) {
    body->position.x += move.x;
    body->position.y += move.y;
}

void rbody_logic_loop(RigidBody *rbody) { 
    //TODO: movement currently relies on pixels. make it rely on an actual measurement
    if (rbody->body.position.y < 100) {
        //Apply acceleration on to velocity
        rbody->velocity = Vector2Add(rbody->velocity ,Vector2Scale(rbody->acceleration, GetFrameTime()));
        rbody->is_on_floor = false;
    } else if (rbody->velocity.y > 0.1) {
        rbody->velocity = Vector2Zero();
        rbody->is_on_floor = true;
    }
    
    //Apply velocity on to position
    Vector2 vf = Vector2Scale(rbody->velocity, GetFrameTime());
    //vf = Vector2Scale(vf, PIXELS_TO_METER); //TODO: figure this out
    rbody->body.position = Vector2Add(rbody->body.position, vf);
}

//Rigidbodies
void force_rbody(RigidBody* rbody, Vector2 force) {
    //Vector2 vf = Vector2Scale(force, GetFrameTime());
    Vector2 vf = force; //TODO: make this code more accurate and add an impulse force function
                        //TODO: also add mass for the rbody struct
    vf = Vector2Add(rbody->velocity, vf);
    rbody->velocity = vf;
}


//Utilities
void draw_body(Body *body, Color color) {
    Collision col = body->collision;
    switch (col.shapeType) {
        case RECTANGLE:
            DrawRectangle(body->position.x, body->position.y, 
                col.shape.rect.width, col.shape.rect.height, color);
            break;
        case CIRCLE:
            DrawCircle(body->position.x, body->position.y, 
                col.shape.circ.radius, color);
            break;
    }
}

void draw_rbody(RigidBody *rbody, Color color) {
    draw_body(&rbody->body, color);
}
