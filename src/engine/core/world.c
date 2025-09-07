#include <raylib.h>
#include <raymath.h>
#include "world.h"
#include "physics.h"

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

