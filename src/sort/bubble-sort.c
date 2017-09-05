/****************************************************************
 * Filename: bubble-sort.c
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 05/09 2017 10:21
 * Description:
 * 
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	05/09 2017
 ****************************************************************/

#include <stdio.h>
#include <assert.h>

#define BUBBLE_SORT_GB
#include "bubble-sort.h"
#undef BUBBLE_SORT_GB

#define ARRAY_LEN (7)

void print_array(int *a, int len);

int main(int argc, const char *argv[])
{
    int a[ARRAY_LEN] = {522, 200, 350, 4, 8, 9, 12};
    print_array(a, ARRAY_LEN);

    bubble_sort(a, ARRAY_LEN);
    print_array(a, ARRAY_LEN);

    return 0;
}


/* 每次找出最小的值，放在a[i]上 */
void bubble_sort(int *a, int len)
{
    assert(a);

    if (!a)
        return;

    int tmp;

    /* 外层：比较多少趟 n-1趟 */
    for (int i = 0; i < len; i++) {

        /* 内层：找到最小的 */
        for (int j = i + 1; j < len; j++) {

            /* 两者比较，取最小值 */
            if (a[i] > a[j]) {
                tmp = a[i];
                a[i] = a[j];
                a[j] = tmp;
            }
        }
    }
}

void print_array(int *a, int len)
{
    assert(a);

    if (!a)
        return;

    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }

    printf("\n");
}


