#include "physics_engine.h"
#include "physics.h"
#include "world.h"
#include <raymath.h>
#include <stdlib.h>
#include <stdio.h>
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
    Body** tmp = realloc(engine->bodies, sizeof(Body*) * (engine->bodyCount + 1));
    if (!tmp) { return; } //TODO: handle this better
    engine->bodies = tmp;
    engine->bodies[engine->bodyCount] = body;
    engine->bodyCount++;
}

void add_rbody_2_engine(PhysicsEngine* engine, RigidBody* rbody) {
    RigidBody** tmp = realloc(engine->rbodies, sizeof(RigidBody*) * (engine->rbodyCount + 1));
    if (!tmp) { return; } //TODO: handle this better
    engine->rbodies = tmp;
    engine->rbodies[engine->rbodyCount] = rbody;
    engine->rbodyCount++;
}


/*
    Sweep and Prune -- Collision Detection Broad Phase Algorithm
    ---------------
*/

//Currently sweep along the x axis currently
SaPResult sweep_and_prune(PhysicsEngine* engine) {
    SaPResult result;
    
    float curMaxX = b2bds(&engine->rbodies[0]->body).min.x;

    int* group; //Group of indexes
    int groups = 0;
    int groupCount = 0;
    int groupMemSize = 0;
    

    //Currently only support rbody & rbody collisions
    for (int i = 0; i < engine->rbodyCount; i++) {
        
        //Body is within bounds
        if (curMaxX > b2bds(&engine->rbodies[i]->body).min.x) {
            
            //check if int* group has enough size to accomodate new index
            int memSize = sizeof(int) * groupCount;
            if (groupMemSize < memSize) {
                group = malloc(memSize);
            }
            group[groupCount] = i;
            ++groupCount;

        } else {
            result.rbodiesIndexes[groups - 1] = group;
            groupCount = 0;
            group = realloc(group, 0);
        }
    }

    free(group);
}



/*
    Bounding Volume Hirearchy -- Collision Detection Broad Phase Algorithm
    -------------------------
*/

void _split_bvh_node(BVHNode* node, int level);
void _update_node_bounds(BVHNode* node, PhysicsEngine* engine);

BVHNode* create_bvh_node() {
    BVHNode* node = malloc(sizeof(BVHNode));
    node->left = NULL;
    node->right = NULL;
    return node;
}

BVHNode* build_bvh(PhysicsEngine* engine) {
    BVHNode* root = create_bvh_node();
    _update_node_bounds(root, engine);
    _split_bvh_node(root, 1);

    /*
    TODO:
        Traverse/Assign bodies and rbodies to the leaves
    */

    return root;
}

void update_bvh(BVHNode** root, PhysicsEngine* engine) {
    free_bvh(*root);
    *root = build_bvh(engine);
}

void _split_bvh_node(BVHNode* node, int level) {
    if (level > 4) { 
        return; 
    }

    node->left = create_bvh_node();
    node->right = create_bvh_node();
    
    node->left->bounds = node->bounds;
    node->right->bounds = node->bounds;

    float lengthX = node->bounds.max.x - node->bounds.min.x;
    float lengthY = node->bounds.max.y - node->bounds.min.y; 
    
    
    if (lengthX > lengthY) {
        lengthX /= 2;
        node->left->bounds.max.x -= lengthX;
        node->right->bounds.min.x = node->left->bounds.max.x;
    } else {
        lengthY /= 2;
        node->left->bounds.max.y -= lengthY;
        node->right->bounds.min.y = node->left->bounds.max.y;
    }

    draw_bounds(&node->left->bounds, (Color){100, 100, level * 10, 100});
    draw_bounds(&node->right->bounds, (Color){100, level * 10, 100, 100});

    _split_bvh_node(node->left, level + 1);
    _split_bvh_node(node->right, level + 1);
}

void _update_node_bounds(BVHNode* node, PhysicsEngine* engine) {
    if (engine->rbodyCount == 0) {
        node->bounds.min = (Vector2){0};
        node->bounds.max = (Vector2){0};
        return;
    }

    Bounds initial = b2bds(&engine->rbodies[0]->body);
    node->bounds.min = initial.min;
    node->bounds.max = initial.max;
    for (int i = 1; i < engine->rbodyCount; i++) {
        Bounds bounds = b2bds(&engine->rbodies[i]->body);
        node->bounds.min = Vector2Min(node->bounds.min, bounds.min);
        node->bounds.max = Vector2Max(node->bounds.max, bounds.max);
    }
}

void free_bvh(BVHNode *root) {
    if (root == NULL) {
        return;
    }

    free_bvh(root->left);
    free_bvh(root->right);

    free(root);
}

int** bvh_aabb_test(BVHNode* root, Bounds bounds) {

}