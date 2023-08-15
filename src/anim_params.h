#pragma once

#include "utils.h"
#include "vector.h"
#include "anim_event.h"

struct AnimParams
{
    int16_t delta_rot;
    struct Vector3 delta_impact;
    int16_t delta_angle;
    float delta_length;
    uint16_t impact_frame;
    float impact_dist;
    int16_t min_turn_del;
    int16_t max_turn_del;
    struct Vector3 launch_dir;
    struct AnimEvent events[];
};

struct AnimParams AnimParams_from_file(FILE *infile)
{
    struct AnimParams params;
    params.delta_rot = read_i16(infile);
    params.delta_impact = Vector3_from_file(infile);
    params.delta_angle = read_i16(infile);
    params.delta_length = read_f32(infile);
    params.impact_frame = read_u16(infile);
    params.impact_dist = read_f32(infile);
    params.min_turn_del = read_i16(infile);
    params.max_turn_del = read_i16(infile);
    params.launch_dir = Vector3_from_file(infile);
    // TODO: complete this and related functions
    return params;
}
