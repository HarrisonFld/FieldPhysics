#include "physics_engine.h"
#include "physics.h"
#include <stdlib.h>
#include <string.h>

PhysicsEngine create_physics_engine() {
    return (PhysicsEngine) {
        NULL,
        0,
        NULL,
        0
    };
}

void physics_engine_logic_loop(PhysicsEngine* engine) {
    for (int i = 0; i < engine->rbodyCount; i++) {
        rbody_logic_loop(engine->rbodies[i]);
    }
}

void add_body_2_engine(PhysicsEngine* engine, Body* body) {
    //TODO: decide whether to encode sizeof(engine->bodies) in the struct
    engine->bodies = realloc(engine->bodies, sizeof(Body*) * (engine->bodyCount + 1));
    engine->bodies[engine->bodyCount] = body;
    engine->bodyCount++;
}

void add_rbody_2_engine(PhysicsEngine* engine, RigidBody* rbody) {
    engine->rbodies = realloc(engine->rbodies, sizeof(RigidBody*) * (engine->rbodyCount + 1));
    engine->rbodies[engine->rbodyCount] = rbody;
    engine->rbodyCount++;
}