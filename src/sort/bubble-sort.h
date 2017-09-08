/****************************************************************
 * Filename: bubble-sort.h
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

#ifndef _BUBBLE_SORT_H_
#define _BUBBLE_SORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef BUBBLE_SORT_GB
#define BUBBLE_SORT_EX extern
#else
#define BUBBLE_SORT_EX
#endif

BUBBLE_SORT_EX void bubble_sort(int *a, int len);


#ifdef __cplusplus
}
#endif

#endif /* end _BUBBLE_SORT_H_ */

