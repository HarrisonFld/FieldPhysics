#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "physics.h"

void move_body(Body* body, Vector2 move) {
    body->position.x += move.x;
    body->position.y += move.y;
}

void rbody_logic_loop(RigidBody *rbody) { 
    //TODO: movement currently relies on pixels. make it rely on an actual measurement
    if (rbody->body.position.y >= 100) { //temporary is_on_floor calculations
        rbody->is_on_floor = true;
    } else {
        rbody->is_on_floor = false;
    }
    
    //Apply acceleration on to velocity
    rbody->velocity = Vector2Add(rbody->velocity ,Vector2Scale(rbody->acceleration, GetFrameTime()));
    
    if (rbody->is_on_floor) { //temporary floor + velocity code
       rbody->velocity.y = fmin(rbody->velocity.y, 0);
    }
    
    //Apply velocity on to position
    Vector2 vf = Vector2Scale(rbody->velocity, GetFrameTime());
    //vf = Vector2Scale(vf, PIXELS_TO_METER); //TODO: figure this out
    rbody->body.position = Vector2Add(rbody->body.position, vf);
}

//Rigidbodies
void force_rbody(RigidBody* rbody, Vector2 force) {
    //attempt by changing acceleration:
    /*
    Vector2 af = rbody->acceleration;
    force = Vector2Scale(force, rbody->mass);
    af = Vector2Add(af, force); 
    rbody->acceleration = af;
    printf("Accel: %f \n", af.y);
    */

    //Vector2 vf = Vector2Scale(force, GetFrameTime());
    Vector2 vf = force; //TODO: make this code more accurate and add an impulse force function
                        //TODO: also add mass for the rbody struct
    vf = Vector2Scale(vf, 1 / rbody->mass);
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
