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

#include "sdb.h"

static WP *head = NULL, *free_ = NULL;
static WP wp_pool[NR_WP]={};

void init_wp_pool() {
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }

  head = NULL;
  free_ = wp_pool;
}

/* TODO: Implement the functionality of watchpoint */

WP* new_wp(char * exp){
		assert(free_!=NULL);
		WP *tmp = free_;
		free_ = free_->next;
		tmp->next = NULL;		//将第一个结点从free链表中断开
		bool success = true;
		strcpy(tmp->exp,exp);
		tmp->value = expr(tmp->exp,&success);
		assert(success);

		if(head == NULL)		//若head为空，则将tmp结点设置为头结点
						head = tmp;
		else{								//若head不为空，则将tmp结点接到head链表的最后一个位置
				WP *p = head;
				while(p->next)
								p = p->next;
				p->next = tmp;
		}
		return tmp;
}
void free_wp(WP *wp){
		assert(head!=NULL);
		assert(wp!=NULL);
		if(wp==head) head=head->next;
		else{
				WP *p= head;
				while(p!=NULL&&p->next!=wp) p = p->next;
				p->next = wp->next;
		}
		wp->next=free_;
		free_=wp;
		wp->value=0;
		wp->exp[0] = '\0';
}

void change_check(){
	WP* tmp = head;
	while(tmp){
		bool success;
		word_t result,pc;
		result = expr(tmp->exp, &success);
		if(result != tmp->value){
			nemu_state.state = NEMU_STOP;
			pc = expr("$pc", &success);
			Log(ANSI_FG_RED"watchpoint %d has changed at address "FMT_WORD ANSI_NONE, tmp->NO, pc);
      printf("Expr: %s\n",tmp->exp);
      printf("Old value = "FMT_WORD"\n", tmp->value);
      printf("New value = "FMT_WORD"\n", result);
			tmp->value = result;
			}
			tmp = tmp->next;
		}
		return ;
	}
void print_wp(){
		WP* h = head;
		if(h == NULL)
						printf("No watchpoint!\n");
		while(h!=NULL)
		{
				printf("Watchpoint %d :%s. Value:%d \n",h->NO,h->exp,h->value);
				h=h->next;
		}
}
WP* delete_wp(int pos,bool* f){
		WP* del=head;
		while(del!=NULL&&del->NO != pos){
				del=del->next;
		}
		if(del==NULL) *f=false;
		return del;
}
