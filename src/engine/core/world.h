#pragma once

#include <raylib.h>

/*
    Shapes
    ------
*/
//Rectangle struct is already provided by raylib.h
//(But not any other shapes...)

typedef struct Circle {
    Vector2 center; //Meters
    float radius; //Meters
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
    World Units
    -----------
*/

//Currently meters are used for all size units
static float RES_SCALING = 1;
#define METER_TO_PIXELS (100 * RES_SCALING) //Multiply by meters to convert to pixels
#define PIXEL_TO_METERS (1.0 / METER_TO_PIXELS) //Multiply by pixels to convert to meters
