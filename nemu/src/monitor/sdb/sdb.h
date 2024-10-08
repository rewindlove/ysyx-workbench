/***************************************************************************************
* Copyright (c) 2014-2022 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#ifndef __SDB_H__
#define __SDB_H__

#include <common.h>
#define NR_WP 32
typedef struct watchpoint {
  int NO;
  struct watchpoint *next;

  /* TODO: Add more members if necessary */
	char exp[32];		//expr存储算术表达式的内容
	word_t value;		//value存储表达式结果
} WP;

<<<<<<< HEAD
<<<<<<< HEAD
extern WP wp_pool[NR_WP];
=======
>>>>>>> pa1
=======
>>>>>>> pa2

word_t expr(char *e, bool *success);


WP* new_wp(char *exp);
WP* delete_wp(int pos,bool* f);
void free_wp(WP *wp);
void print_wp();
void change_check();

#endif
