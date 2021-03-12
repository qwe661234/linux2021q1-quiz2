#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "doubleLinkMerge.h"

static queue_t *q_new()
{
    queue_t *q = malloc(sizeof(queue_t));
    if (!q) return NULL;

    q->head = q->tail = NULL;
    q->size = 0;
    INIT_LIST_HEAD(&q->list);
    return q;
}

static void q_free(queue_t *q)
{
    if (!q) return;

    list_ele_t *current = q->head;
    while (current) {
        list_ele_t *tmp = current;
        current = current->next;
        free(tmp->value);
        free(tmp);
    }
    free(q);
}

bool q_insert_head(queue_t *q, char *str)
{
    if (!q) return false;

    list_ele_t *newh = malloc(sizeof(list_ele_t));
    if (!newh)
        return false;

    char *new_value = strdup(str);
    if (!new_value) {
        free(newh);
        return false;
    }

    newh->value = new_value;
    newh->next = q->head;
    q->head = newh;
    if (q->size == 0)
        q->tail = newh;
    q->size++;
    list_add_tail(&newh->list, &q->list);

    return true;
}
int main(){
    queue_t *q = q_new();
    q_insert_head(q, "aaa");
    q_insert_head(q, "bbb");
    list_ele_t *ptr;
    ptr = q->head;

    printf("%s, ", ptr->value);
}