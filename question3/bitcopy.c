#include <stdio.h>
#include <string.h>
#include <time.h>
#include "bitcopy.h"

int main(int _argc, char **_argv)
{
    clock_t start, end;
    start = clock();
    memset(&input[0], 0xFF, sizeof(input));

    for (int i = 1; i <= 32; ++i) {
        for (int j = 0; j < 16; ++j) {
            for (int k = 0; k < 16; ++k) {
                memset(&output[0], 0x00, sizeof(output));
                printf("%2d:%2d:%2d ", i, k, j);
                bitcpy(&output[0], k, &input[0], j, i);
                dump_binary(&output[0], 8);
                printf("\n");
            }
        }
    }
    end = clock();
    end -= start;
    printf("%ld ms\n", end);
    return 0;
}