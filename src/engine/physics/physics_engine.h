#pragma once

#include "physics.h"

typedef struct {
    RigidBody** rbodies;
    int rbodyCount;
    Body** bodies;
    int bodyCount;
} PhysicsEngine;


PhysicsEngine create_physics_engine(); //Creates and returns a new physics engine
void physics_engine_logic_loop(PhysicsEngine* engine); //Loop to call with a physics engine

void add_body_2_engine(PhysicsEngine* engine, Body* body); //Add body to physics engine
void add_rbody_2_engine(PhysicsEngine* engine, RigidBody* rbody); //Add rigidbody to physics engine