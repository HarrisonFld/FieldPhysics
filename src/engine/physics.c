#include <raylib.h>
#include <raymath.h>
#include <math.h>
#include "physics.h"

#include <stdio.h>

void move_body(Body* body, Vector2 move) {
    body->position.x += move.x;
    body->position.y += move.y;
}


//Rigidbodies
void rbody_logic_loop(RigidBody *rbody) { 
    //TODO: movement currently relies on pixels. make it rely on an actual measurement
    if (rbody->body.position.y >= 100) { //temporary is_on_floor calculations
        rbody->is_on_floor = true;
    } else {
        rbody->is_on_floor = false;
    }
    
    //Apply gravity on to acceleration
    rbody->acceleration.y += GRAVITY; //TODO: figure out a unconstrained method of doing this
    //rbody->acceleration.y = Clamp(rbody->acceleration.y, 0, 9.8);

    //Apply acceleration on to velocity
    rbody->velocity = Vector2Add(rbody->velocity ,Vector2Scale(rbody->acceleration, GetFrameTime()));
    
    if (rbody->is_on_floor && FLOOR_ON) { //temporary floor + velocity + acceleration code
       rbody->velocity.y = fmin(rbody->velocity.y, 0);
    }
    
    //Apply velocity on to position
    Vector2 vf = Vector2Scale(rbody->velocity, GetFrameTime());
    vf = Vector2Scale(vf, PIXELS_TO_METER); //Convert the physics units to pixels
    Vector2 pf = Vector2Add(rbody->body.position, vf);
    rbody->body.position = pf;
    
    rbody->acceleration = Vector2Zero(); /* TODO: figure out how to do this neatly:
        currently this piece of code is responsible for making sure acceleration doesn't keep
        increasing due to GRAVITY by just zeroing acceleration after using it.
        Which means to handle acceleration outside, acceleration needs to keep being set
        with functions like force_rbody().
        This all sucks, and it means I can't read the acceleration value outside this function
    */
}

void force_rbody(RigidBody* rbody, Vector2 force) {
    Vector2 acceleration = Vector2Scale(force, 1.0f / rbody->mass);
    rbody->acceleration = acceleration;
    //Vector2 deltaVelocity = Vector2Scale(acceleration, GetFrameTime());
    //rbody->velocity = Vector2Add(rbody->velocity, deltaVelocity);
}

void impulse_rbody(RigidBody* rbody, Vector2 impulse) {
    Vector2 deltaV = Vector2Scale(impulse, 1.0f / rbody->mass);
    rbody->velocity = Vector2Add(rbody->velocity, deltaV);
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
