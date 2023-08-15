#include "../src/utils.h"

int main(void)
{
    double t0 = get_time();

    const char *path_to_skeleton = "test.bin";
    FILE *fp_skeleton = fopen(path_to_skeleton, "rb");

    int16_t i16 = read_i16(fp_skeleton);
    uint16_t u16 = read_u16(fp_skeleton);
    int32_t i32 = read_i32(fp_skeleton);
    uint32_t u32 = read_u32(fp_skeleton);
    int64_t i64 = read_i64(fp_skeleton);
    float f32 = read_f32(fp_skeleton);
    bool b = read_bool(fp_skeleton);
    char c = read_char(fp_skeleton);
    read_pad(fp_skeleton, 2);
    char *string = read_string(fp_skeleton);

    fclose(fp_skeleton);

    assert(i16 == -53);
    assert(u16 == 53);
    assert(i32 == -53);
    assert(u32 == 53);
    assert(i64 == -53);
    assert(f32 == -0.53f);
    assert(b == true);
    assert(c == 'V');
    assert(strcmp(string, "Vartan") == 0);

    puts("All tests passed.");

    double t1 = get_time();
    double time_elapsed = t1 - t0;
    printf("Completed in %.3f ms\n", time_elapsed * 1000);

    return EXIT_SUCCESS;
}
