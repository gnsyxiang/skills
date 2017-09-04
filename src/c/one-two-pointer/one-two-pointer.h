/****************************************************************
 * Filename: one-two-pointer.h
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 04/09 2017 16:27
 * Description:
 * 
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	04/09 2017
 ****************************************************************/

#ifndef _ONE_TWO_POINTER_H_
#define _ONE_TWO_POINTER_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ONE_TWO_POINTER_GB
#define ONE_TWO_POINTER_EX extern
#else
#define ONE_TWO_POINTER_EX
#endif

    typedef struct teacher {
        char *name;         //名字
        char **course;       //所教授的课程，比如：数学，音乐，体育
        int age;
        int id;
    }teacher;


ONE_TWO_POINTER_EX int teacher_init(teacher **p, int num);
ONE_TWO_POINTER_EX void teacher_destroy(teacher *p, int num);
#ifdef __cplusplus
}
#endif

#endif /* end _ONE_TWO_POINTER_H_ */

