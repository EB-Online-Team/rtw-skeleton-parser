#pragma once

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>
#include <inttypes.h>
#include <windows.h>

// NOTE! This functions requires the program be run in a Windows environment
double get_time()
{
    LARGE_INTEGER t, f;
    QueryPerformanceCounter(&t);
    QueryPerformanceFrequency(&f);
    return (double)t.QuadPart / (double)f.QuadPart;
}

int16_t read_i16(FILE *infile)
{
    int16_t value = 0;
    fread(&value, 2, 1, infile);
    return value;
}

uint16_t read_u16(FILE *infile)
{
    uint16_t value = 0;
    fread(&value, 2, 1, infile);
    return value;
}

int32_t read_i32(FILE *infile)
{
    int32_t value = 0;
    fread(&value, 4, 1, infile);
    return value;
}

uint32_t read_u32(FILE *infile)
{
    uint32_t value = 0;
    fread(&value, 4, 1, infile);
    return value;
}

int64_t read_i64(FILE *infile)
{
    int64_t value = 0;
    fread(&value, 8, 1, infile);
    return value;
}

float read_f32(FILE *infile)
{
    float value = 0;
    fread(&value, 4, 1, infile);
    return value;
}

bool read_bool(FILE *infile)
{
    bool value = false;
    fread(&value, 1, 1, infile);
    return value;
}

char read_char(FILE *infile)
{
    char value = 0;
    fread(&value, 1, 1, infile);
    return value;
}

void read_pad(FILE *infile, size_t length)
{
    for (size_t i = 0; i < length; i++)
    {
        fgetc(infile);
    }
}

char *read_string(FILE *infile)
{
    const size_t MAX_LENGTH = 1024;
    char *string = malloc(MAX_LENGTH);
    fgets(string, MAX_LENGTH, infile);
    return string;
}
