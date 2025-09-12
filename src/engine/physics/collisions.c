#include <raylib.h>
#include <raymath.h>
#include "physics.h"
#include "world.h"


//https://en.wikipedia.org/wiki/Elastic_collision#One-dimensional_Newtonian
void collision_rbody_rbody(RigidBody* a, RigidBody* b) {
    Vector2 velocityCom;
    {
        Vector2 am = get_rbody_momentum(a);
        Vector2 bm = get_rbody_momentum(b);
        velocityCom = Vector2Scale(Vector2Add(am, bm), (1 / (a->mass + b->mass)));
    }
    //V_f = (1 + e)V_com - e * V_i 
    float e = 1; //elastic collisions
    Vector2 aVelocityFinal = Vector2Subtract(Vector2Scale(velocityCom, (1 + e)), Vector2Scale(a->velocity, e));
    Vector2 bVelocityFinal = Vector2Subtract(Vector2Scale(velocityCom, (1 + e)), Vector2Scale(b->velocity, e));
    a->velocity = aVelocityFinal;
    b->velocity = bVelocityFinal;
}


void collision_rbody_body(RigidBody* a, Body* b); //TODO



Vector2 get_collision_normal(Body* a, Body* b) {
    if (
        a->rotation != 0 || b->rotation != 0 ||
        a->collision.shapeType != RECTANGLE || b->collision.shapeType != RECTANGLE
    ) { return (Vector2){0, 0}; } //no rotations or non rectangle collisions yet



    /*
    Steps:
        1. Get direction and axis of collision (assume AABB)
        2. 

    */

}

