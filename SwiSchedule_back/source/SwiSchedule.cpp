/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 2010/3
Last Modified :
Description   :
Function List :

History       :
1.Date        : 2010/3
Author      :
Modification: Created file

******************************************************************************/

#include"list.h"
#include<stdlib.h>
#include<malloc.h>

struct Swi {
  unsigned int swiId;
	unsigned int prio;
	void (* proc)(void);
	struct list_elem allelem;
	struct list_elem waitelem;
	struct list wait_list;
};

static struct list all_list;
static struct Swi *current_swi;
bool begin = 0;

struct Swi * get_swi_by_id(unsigned int swiId) {
  struct list_elem *e;
	for (e = list_begin(&all_list); e != list_end(&all_list); e = list_next(e)) {
	  struct Swi * t = list_entry (e, struct Swi, allelem);
		if(t->swiId == swiId) {
		  return t;
		}
	}
	return 0;
}

/*************************************************************************************************
函数说明：创建软中断
输入参数：
      swiId： 创建软中断ID；
	  prio：  创建软中断优先级；
      proc：  创建软中断处理函数。
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void))
{
	if (0 == begin) {
		list_init(&all_list);
    current_swi = 0;
		begin = 1;
	}
	if (proc == 0) {
	  return -1;
	}

	if (prio < 0 || prio >31) {
	  return -1;
	}
  if (get_swi_by_id(swiId) != 0) {
	  return -1;
	}

	struct Swi* newSwi;
	newSwi = (struct Swi *) malloc (sizeof(struct Swi));
	newSwi->swiId = swiId;
	newSwi->prio = prio;
  newSwi->proc = proc;
  list_init(&newSwi->wait_list);
  list_push_back(&all_list, &newSwi->allelem);
	return 0;
}

bool swi_less_func(struct list_elem *a, struct list_elem *b) {
  return list_entry(a, struct Swi, allelem)->prio > list_entry(b, struct Swi, allelem)->prio;
}
/*************************************************************************************************
函数说明：软中断激活
输入参数：swiId： 待激活软中断ID
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiActivate(unsigned int swiId)
{
	struct Swi* t;
	struct Swi* store;
	t = get_swi_by_id (swiId);
	if (0 == current_swi) {
	  current_swi = t;
		t->proc();
	} else {
	  if (current_swi->prio >= t->prio) {
		  list_push_back(&current_swi->wait_list, &t->waitelem);
			//list_sort(&current_swi->wait_list, swi_less_func, NULL);
		} else {
			store = current_swi;
			current_swi = t;
			current_swi->proc();
			current_swi = store;
		}
	}
  
	while(!list_empty(&current_swi->wait_list)) {
    struct Swi *head = list_entry((current_swi->wait_list).head.next,struct Swi, waitelem);
	  store = current_swi;
		current_swi = head;
		current_swi->proc();
		current_swi = store;
		list_remove (&(head->waitelem));
	}
	return 0;
}

/*************************************************************************************************
函数说明：清空所有的信息
输入参数：无
输出参数：无
返回值  ：无
**************************************************************************************************/
void Clear(void)
{
	begin = 0;
	list_init(&all_list);
}
