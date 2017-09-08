/****************************************************************
 * Filename: order-table.c
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 31/08 2017 17:46
 * Description:
 *
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	31/08 2017
 ****************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define ORDER_TABLE_GB
#include "order-table.h"
#undef ORDER_TABLE_GB

#define TABLE_SIZE (4)

int main(int argc, const char *argv[])
{
    order_table_t *t = NULL;

    table_init(&t, TABLE_SIZE);

    for (int i = 0; i < TABLE_SIZE; i++) {
        t->head[i] = i+1;
        t->cur_len++;
    }

    table_display(t);

    table_del_elem(t, 1);
    table_display(t);

    table_insert(t, 2, 5);
    table_display(t);

    table_select(t, 3);
    table_display(t);

    table_amend(t, 3, 6);
    table_display(t);

    table_destroy(t);

    return 0;
}

int table_init(order_table_t **t, int size)
{
    assert(size > 0);
    assert(t);

    if (size <= 0 || !t)
        return -1;

    order_table_t *temp = (order_table_t *)malloc(sizeof(order_table_t));
    if (!temp) {
        printf("malloc faild \n");
        return -1;
    }

    temp->head = (int *)malloc(size * sizeof(int));
    if (!temp->head) {
        printf("malloc faild \n");
        return -1;
    }

    temp->cur_len = 0;
    temp->capacity = size;

    *t = temp;

    return 0;
}

void table_destroy(order_table_t *t)
{
    assert(t);

    if (!t)
        return;

    free(t->head);

    free(t);
}

int table_select(order_table_t *t, int elem)
{
    assert(t);

    if (!t)
        return -1;

    for (int i = 0; i < t->cur_len; i++) {
        if (t->head[i] == elem) {
            return i+1;
        }
    }

    return -1;
}

int table_amend(order_table_t *t, int elem, int new_elem)
{
    assert(t);

    if (!t)
        return -1;

    int index = table_select(t, elem);
    t->head[index - 1] = new_elem;

    return 0;
}

int table_insert(order_table_t *t, int index, int elem)
{
    assert(t);

    if (!t)
        return -1;

    if (index > t->cur_len + 1 || index < 1) {
        printf("index error \n");
        return -1;
    }

    if (t->cur_len == t->capacity) {
        t->head = (int *)realloc(t->head, (t->capacity + 1) * sizeof(int));
        if (!t->head) {
            printf("realloc faild \n");
            return -1;
        }
        t->capacity += 1;
    }

    for (int i = t->cur_len - 1; i >= index - 1; i--) {
        t->head[i + 1] = t->head[i];
    }

    t->head[index - 1] = elem;
    t->cur_len++;

    return 0;
}

int table_del_elem(order_table_t *t, int index)
{
    assert(t);

    if (!t)
        return -1;

    if (index > t->cur_len || index < 1) {
        printf("index error \n");
        return -1;
    }

    for (int i = index; i < t->cur_len; i++) {
        t->head[i - 1] = t->head[i];
    }

    t->cur_len--;

    return 0;
}

void table_display(order_table_t *t)
{
    for (int i = 0; i < t->cur_len; i++) {
        printf("%d ", t->head[i]);
    }
    printf("\n");
}

