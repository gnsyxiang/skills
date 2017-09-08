/****************************************************************
 * Filename: array.c
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 05/09 2017 14:22
 * Description:
 * 
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	05/09 2017
 ****************************************************************/

#include <stdio.h>

#define ARRAY_GB
#include "array.h"
#undef ARRAY_GB

void print_array(int a[], int len);

int main(int argc, const char *argv[])
{
    int a[] = { 522, 200, 350, 4, 8, 9, 12};
    int len = sizeof(a)/sizeof(a[0]);

    print_array(a, len);

    return 0;
}

/*
 * 数组做参数会退化成一个指针：
 * 1，把数组的首地址和有效长度传给被调用函数
 * 2，实参a和形参a的数据类型的本质不一样，
 *    形参中的数组，编译器会把他当成指针处理，只是C的特色
 * 3，形参写在函数括号内和写在函数内是一样的，只不过前者有对外的属性而已
 */
void print_array(int a[], int len)
{
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}




