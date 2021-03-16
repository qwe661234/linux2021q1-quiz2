#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "bitcopy.h"

int main(int _argc, char **_argv)
{
    FILE *fp = fopen("a.txt", "w");
    if (!fp) {
        perror("failed to open a.txt");
        exit(EXIT_FAILURE);
    }
    memset(&input[0], 0xFF, sizeof(input));

    for(int l = 0; l < 1000; l++){
        clock_t start, end;
        start = clock();
        for (int i = 1; i <= 32; ++i) {
            for (int j = 0; j < 16; ++j) {
                for (int k = 0; k < 16; ++k) {
                    memset(&output[0], 0x00, sizeof(output));
                    // printf("%2d:%2d:%2d ", i, k, j);
                    bitcpy(&output[0], k, &input[0], j, i);
                    // dump_binary(&output[0], 8);
                    // printf("\n");
                }
            }
        }
        end = clock();
        end -= start;
        fprintf(fp, "%lums\n", end);
    }
    return 0;
}