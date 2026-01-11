#pragma once
#include "module.h"
#include "field_math.h"

Module* m_physics(); //Create the module

typedef struct Body {
    Vec2 position; //Meters
    float rotation; //Degrees
    Vec2 origin; //Meters
    Shape collision;
} Body;