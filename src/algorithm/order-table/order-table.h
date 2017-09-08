/****************************************************************
 * Filename: order-table.h
 * -------------------------------
 * Copyright(C),
 * Author: zhenquan.qiu
 * Version: V1.0.0
 * Last modified: 31/08 2017 17:47
 * Description:
 *
 * Change Log:
 * NO.	Author		    Date		Modified
 * 00	zhenquan.qiu	31/08 2017
 ****************************************************************/

#ifndef _ORDER_TABLE_H_
#define _ORDER_TABLE_H_

#ifdef __cplusplus
extern "C" {
#endif

#ifndef ORDER_TABLE_GB
#define ORDER_TABLE_EX extern
#else
#define ORDER_TABLE_EX
#endif

#define TOTAL_CAPACITY (10)

    typedef struct _order_table {
        int * head;
        int cur_len;
        int capacity;
    }order_table_t;

ORDER_TABLE_EX int table_init(order_table_t **t, int size);
ORDER_TABLE_EX void table_destroy(order_table_t *t);
ORDER_TABLE_EX int table_select(order_table_t *t, int elem);
ORDER_TABLE_EX int table_amend(order_table_t *t, int elem, int new_elem);
ORDER_TABLE_EX int table_insert(order_table_t *t, int index, int elem);
ORDER_TABLE_EX int table_del_elem(order_table_t *t, int index);
ORDER_TABLE_EX void table_display(order_table_t *t);

#ifdef __cplusplus
}
#endif

#endif /* end _ORDER_TABLE_H_ */

