#pragma once

#include "utils.h"

struct Vector3
{
    float x;
    float y;
    float z;
};

struct Vector3 Vector3_init(float x, float y, float z)
{
    struct Vector3 v;
    v.x = x;
    v.y = y;
    v.z = z;
    return v;
}

struct Vector3 Vector3_from_file(FILE *infile)
{
    struct Vector3 v;
    v.x = read_f32(infile);
    v.y = read_f32(infile);
    v.z = read_f32(infile);
    return v;
};

struct Vector3 *Vector3_multiply(struct Vector3 *v, float by)
{
    v->x *= by;
    v->y *= by;
    v->z *= by;
    return v;
}

bool Vector3_equal(struct Vector3 *v1, struct Vector3 *v2)
{
    return v1->x == v2->x && v1->y == v2->y && v1->z == v2->z;
}
