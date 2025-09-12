#include <raylib.h>
#include <raymath.h>
#include "world.h"
#include "physics.h"

void draw_bounds(Bounds* bounds, Color color) {
    DrawRectangle(
        bounds->min.x * METER_TO_PIXELS,
        bounds->min.y * METER_TO_PIXELS, 
        (bounds->max.x - bounds->min.x) * METER_TO_PIXELS, 
        (bounds->max.y - bounds->min.y) * METER_TO_PIXELS, 
        color
    );
}

Rectangle b2mr(Body* body) {
    Rectangle rect = body->collision.shape.rect;
    return (Rectangle) {
        rect.x + body->position.x,
        rect.y + body->position.y,
        rect.width,
        rect.height
    };
}

Rectangle b2pr(Body* body) {
    Rectangle rect = b2mr(body);
    return (Rectangle) {
        rect.x * METER_TO_PIXELS,
        rect.y * METER_TO_PIXELS,
        rect.width * METER_TO_PIXELS,
        rect.height * METER_TO_PIXELS
    };
}

Bounds b2bds(Body *body) {
    //Still only supporting rectangles
    Rectangle shape = b2mr(body);
    Bounds bound = {
        shape.x - shape.width / 2, shape.y - shape.height / 2,
        shape.x + shape.width / 2, shape.y + shape.height / 2
    };
    return bound;
}
