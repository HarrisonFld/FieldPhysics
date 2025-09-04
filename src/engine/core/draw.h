#pragma once

#include <raylib.h>
#include "physics.h"

void draw_axes(bool x, bool y, Camera2D* camera, float interval); //Draw axis x and/or y
void draw_body(Body* body, Color color); //Draw body
void draw_rbody(RigidBody* rbody, Color color); //Draw rigidbody