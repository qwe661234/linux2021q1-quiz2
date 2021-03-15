#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "doubleLinkMerge.h"

int main(void)
{
    clock_t start, end;
    start = clock();
    FILE *fp = fopen("cities.txt", "r");
    if (!fp) {
        perror("failed to open cities.txt");
        exit(EXIT_FAILURE);
    }

    queue_t *q = q_new();
    char buf[256];
    while (fgets(buf, 256, fp))
        q_insert_head(q, buf);
    fclose(fp);
    list_merge_sort(q);
    assert(validate(q));

    q_free(q);
    end = clock();
    end -= start;
    printf("%ld ms\n", end);
    return 0;
}
