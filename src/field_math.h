#pragma once

/*
* Vector 2
*/
typedef struct Vec2 {
    float x;
    float y;
} Vec2;

inline Vec2 vec2_add(Vec2 a, Vec2 b) {
    return (Vec2){a.x + b.x, a.y + b.y};
}

inline Vec2 vec2_sub(Vec2 a, Vec2 b) {
    return (Vec2){a.x - b.x, a.y - b.y};
}

inline Vec2 vec2_mul(Vec2 a, Vec2 b) {
    return (Vec2){a.x * b.x, a.y * b.y};
}

inline Vec2 vec2_div(Vec2 a, Vec2 b) {
    return (Vec2){a.x / b.x, a.y / b.y};
}

inline float vec2_dot(Vec2 a, Vec2 b) {
    return (a.x * b.x) + (a.y * b.y);
}

inline Vec2 vec2_scale(Vec2 v, float k) {
    return (Vec2){v.x * k, v.y * k};
}

/*
Vector 3
*/
typedef struct Vec3 {
    float x;
    float y;
    float z;
} Vec3;

inline Vec3 vec3_add(Vec3 a, Vec3 b) {
    return (Vec3){a.x + b.x, a.y + b.y, a.z + b.z};
}

inline Vec3 vec3_sub(Vec3 a, Vec3 b) {
    return (Vec3){a.x - b.x, a.y - b.y, a.z - b.z};
}

inline Vec3 vec3_mul(Vec3 a, Vec3 b) {
    return (Vec3){a.x * b.x, a.y * b.y, a.z * b.z};
}

inline Vec3 vec3_div(Vec3 a, Vec3 b) {
    return (Vec3){a.x / b.x, a.y / b.y, a.z / b.z};
}

inline float vec3_dot(Vec3 a, Vec3 b) {
    return (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}

inline Vec3 vec3_scale(Vec3 v, float k) {
    return (Vec3){v.x * k, v.y * k, v.z * k};
}

/*
Geometry
*/

/*2D*/
typedef enum ShapeType2D {
    RECT,
    CIRCLE,
    CAPSULE,
} ShapeType2D;

typedef struct Rect {
    float width;
    float height;
} Rect;

typedef struct Circle {
    float radius;
} Circle;

typedef struct Capsule {
    float radius;
    float height;
    float midHeight;
} Capsule;

typedef struct Shape {
    ShapeType2D type;
    union {
        Rect rect;
        Circle circle;
        Capsule capsule;
    };
} Shape;