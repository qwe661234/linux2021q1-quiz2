#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkMerge.h"

int main(){
    queue_t *q = q_new();
    q_insert_head(q, "ccc");
    q_insert_head(q, "aaa");
    q_insert_head(q, "bbb");
    
    list_merge_sort(q);
    struct list_head *node;
    list_for_each (node, &q->list) {
        printf("%s\n", list_entry(node, list_ele_t, list)->value);
    }
    
}