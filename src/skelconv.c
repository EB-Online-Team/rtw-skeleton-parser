#include "utils.h"
#include "vector.h"

int main(int argc, char const *argv[])
{
    double t0 = get_time();

    if (argc < 2)
    {
        puts("Usage: skelconv.exe <path_to_skeleton>");
        return EXIT_FAILURE;
    }

    const char *path_to_skeleton = argv[1];
    FILE *fp_skeleton = fopen(path_to_skeleton, "rb");

    // TODO: read skeleton pack here

    fclose(fp_skeleton);

    double t1 = get_time();
    double time_elapsed = t1 - t0;
    printf("Completed in %.3f ms\n", time_elapsed * 1000);

    return EXIT_SUCCESS;
}
