#include <raylib.h>
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
