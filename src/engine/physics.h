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
    Physics   
    -------
*/

#define GRAVITY = 9.8;

typedef struct Collision {
    ShapeType shapeType;
    Shape shape;
} Collision;

typedef struct Body {
    Vector2 position;
    Collision collision;
} Body;

void move_body(Body* body, Vector2 move); //Add 'move' to 'body' position
