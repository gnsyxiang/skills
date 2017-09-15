/****************************************************************
 * Filename: queue-list.c
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 15/09 2017 10:43
 * Description:
 * 
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	15/09 2017
 ****************************************************************/

#include <stdio.h>

#define QUEUE_LIST_GB
#include "queue-list.h"
#undef QUEUE_LIST_GB


int en_queue(int *a, int rear, int data)
{
    a[rear++] = data;
    return rear;
}

void de_queue(int *a, int front, int rear)
{
    while (front != rear) {
        printf("%d \n", a[front]);
        front++;
    }
}

void print_queue(int *a, int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

#define QUEUE_LIST_TEST

#ifdef QUEUE_LIST_TEST
int main(int argc, const char *argv[])
{
#define QUEUE_LEN (10)
    int a[QUEUE_LEN];
    int front, rear;

    front = rear = 0;

    for (int i = 0; i < QUEUE_LEN; i++) {
        rear = en_queue(a, rear, i);
    }

    print_queue(a, QUEUE_LEN);

    de_queue(a, front, rear);

    return 0;
}
#endif




