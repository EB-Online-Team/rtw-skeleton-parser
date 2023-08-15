#pragma once

#include "utils.h"
#include "vector.h"

/**
 * types:
 *   0 = unknown
 *   1 = saddle
 *   2 = platform (?)
 *   3 = wheel
 *   4 = left hand
 *   5 = right hand
 */

struct Bone
{
    uint32_t type;
    struct Vector3 pose;
    int32_t parent_index;
    bool has_translation;
    bool apply_IK;
};

struct Bone Bone_from_file(FILE *infile)
{
    struct Bone b;
    b.type = read_u32(infile);
    b.pose = Vector3_from_file(infile);
    b.parent_index = read_i32(infile);
    b.has_translation = read_bool(infile);
    b.apply_IK = read_bool(infile);
    read_pad(infile, 2);
    return b;
}

// TODO: complete related functions
