#pragma once

#include "physics.h"

typedef struct {
    RigidBody** rbodies;
    unsigned int rbodyCount;
    Body** bodies;
    unsigned int bodyCount;
} PhysicsEngine;


PhysicsEngine create_physics_engine(); //Creates and returns a new physics engine
void physics_engine_logic_loop(PhysicsEngine* engine); //Loop to call with a physics engine

void add_body_2_engine(PhysicsEngine* engine, Body* body); //Add body to physics engine
void add_rbody_2_engine(PhysicsEngine* engine, RigidBody* rbody); //Add rigidbody to physics engine


/*
    Bounding Volume Hirearchy
    -------------------------
*/
typedef struct BVHNode BVHNode;

typedef struct BVHNode {
    Bounds bounds;
    BVHNode* left;
    BVHNode* right;
    int children[];
} BVHNode;

BVHNode* create_bvh_node(); //Create BVH node
BVHNode* build_bvh(PhysicsEngine* engine); //Builds BVH and returns root node
void update_bvh(BVHNode** root, PhysicsEngine* engine); //Update BVH root node to engine
void free_bvh(BVHNode* root); //Traverses BVH and frees memory allocated 
int** bvh_aabb_test(BVHNode* root, Bounds bounds); //Tests BVH and returns an array of arrays of colliding indices