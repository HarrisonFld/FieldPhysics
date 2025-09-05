#pragma once

#include <raylib.h>
#include "physics.h"

//TODO: somehow handle different shape collision mixing
//for now it is just rectangles

/*
Bounding Volumes
    – Spheres
    – Axis Aligned Bounding Boxes (AABB)
    – Oriented Bounding Boxes (OBB)
    – Swept Sphere Volumes (SSV)
*/

void collision_rbody_rbody(RigidBody* a, RigidBody* b); //Apply collision of two rigidbodies
void collision_body_rbody(Body* a, RigidBody* b); //Apply collision of rigidbody and body
Vector2 get_collision_normal(Body* a, Body* b); //Get normal of two body collisions

//void get_obb();