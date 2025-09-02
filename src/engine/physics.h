#pragma once

#include <raylib.h>
#include "world.h"

/*
    StaticBodies   
    ------------
*/

typedef struct Collision {
    ShapeType shapeType;
    Shape shape;
} Collision;

typedef struct Body {
    Vector2 position; //Meters
    float rotation; //Degrees
    Vector2 origin; //Meters
    Collision collision;
} Body;

void move_body(Body* body, Vector2 move); //Add Vec2 move to body position


/*
    RigidBodies
    -----------
*/
#define GRAVITY (9.8f)
#define V_GRAVITY (Vector2){0, GRAVITY}

#define FLOOR_ON true //for debugging currently

typedef struct RigidBody {
    Body body;
    Vector2 velocity; //Meters per second
    Vector2 acceleration; //Meters per second^2
    float mass; //Kg
    Vector2 gravity; //Meters per second^2. Gravity applied individually. Most rbodies should use V_GRAVITY

    //Changed at runtime
    bool is_on_floor;
    Vector2 actual_acceleration; //Actual rbody acceleration (combines: gravity, acceleration)
} RigidBody;

void rbody_logic_loop(RigidBody* rbody); //Rigidbody logic loop to be called every frame
void force_rbody(RigidBody* rbody, Vector2 force); //Apply Vec2 force onto rbody acceleration (call routinely)
void impulse_rbody(RigidBody* rbody, Vector2 impulse); //Apply Vec2 impulse force onto rbody velocity (1 call)

/*
    Utilities
    ---------
*/
void draw_body(Body* body, Color color);
void draw_rbody(RigidBody* rbody, Color color); 