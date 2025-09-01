#pragma once

#include <raylib.h>

/*
    Shapes
    ------
*/
//Rectangle struct is already provided by raylib.h
//(But not any other shapes...)

typedef struct Circle {
    Vector2 center;
    float radius;
} Circle;

typedef union Shape {
    Rectangle rect;
    Circle circ;
} Shape;

typedef enum ShapeType {
    RECTANGLE,
    CIRCLE,
} ShapeType;



/*
    StaticBodies   
    ------------
*/

typedef struct Collision {
    ShapeType shapeType;
    Shape shape;
} Collision;

typedef struct Body {
    Vector2 position;
    Collision collision;
} Body;

void move_body(Body* body, Vector2 move); //Add Vec2 move to body position


/*
    RigidBodies
    -----------
*/
#define PIXELS_TO_METER 100 //The amount of pixels for one meter
#define GRAVITY (9.8f)
#define V_GRAVITY (Vector2){0, GRAVITY}

#define FLOOR_ON true //for debugging currently

typedef struct RigidBody {
    Body body;
    Vector2 velocity; //Meters per second
    Vector2 acceleration; //Meters per second^2
    float mass; //Kg

    //Changed at runtime
    bool is_on_floor;
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