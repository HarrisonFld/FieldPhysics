#include "world.h"
#include <raylib.h>

//TODO: scale based on camera zoom, position
void draw_axes(bool x, bool y) {
    if (x) {
        DrawLine(-5000, 0.0001 * METER_TO_PIXELS, 5000, 0, RED);
    }
    if (y) {
        DrawLine(0.0001 * METER_TO_PIXELS, -5000, 0, 5000, GREEN);
    }
}