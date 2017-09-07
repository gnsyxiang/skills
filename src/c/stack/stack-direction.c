/****************************************************************
 * Filename: stack-direction.c
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 07/09 2017 09:13
 * Description:
 * 
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	07/09 2017
 ****************************************************************/

#include <stdio.h>

int main(int argc, const char *argv[])
{
    int a;
    int b;
    char buf[3];

    printf("%p \n", &a);
    printf("%p \n", &b);

    for (int i = 0; i < 3; i++) {
        printf("%p \n", &buf[i]);
    }

    return 0;
}

/* 栈的开口方向：
 * 开口向下的栈先分配大地址，从下到上地址编号依次变大
 * 开口向上的栈先分配小地址
 *
 * 一般情况下，操作系统提供的栈都是向下的
 *
 * 不管栈的开口朝向，数组buf的内存地址buf+1永远向上
 */
