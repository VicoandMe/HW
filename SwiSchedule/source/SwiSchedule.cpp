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


/*************************************************************************************************
函数说明：创建软中断
输入参数：
      swiId： 创建软中断ID；
	  prio：  创建软中断优先级；
      proc：  创建软中断处理函数。
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/

#include<queue>
#include<map>
#include<stdlib.h>
using namespace std;
struct Swi {
  int swiId;
	int prio;
	int num;
	void (* proc)(void);
	friend bool operator < (Swi swi1, Swi swi2) {
	  return swi1.prio > swi2.prio;
	}
};

priority_queue<Swi> wait_queue;
static map<int, Swi> swi_map;
static struct Swi current_swi;
bool begin = 0;
int num;

int SwiCreate(unsigned int swiId, unsigned int prio, void (* proc)(void))
{
	if (begin == 0) {
	  current_swi.num = -1;
		num = 0;
		begin = 1;
	}
	if (prio < 0 || prio > 31) {
	  return -1;
	}

	if (proc == NULL) {
	  return -1;
	}

	if (swi_map.count(swiId)) {
	  return -1;
	}
  struct Swi t;
	t.swiId = swiId;
	t.prio = prio;
	t.proc = proc;
	swi_map[swiId] = t;
	return 0;
}

/*************************************************************************************************
函数说明：软中断激活
输入参数：swiId： 待激活软中断ID
输出参数：无
返回值  ：成功返回0， 其它情况返回-1
**************************************************************************************************/
int SwiActivate(unsigned int swiId)
{
	if (!swi_map.count(swiId)) {
	  return -1;
	}
	struct Swi temp = swi_map[swiId];
  struct Swi store;
	temp.num = num;
	num++;
	wait_queue.push(temp);
	while (!wait_queue.empty()) {
	  store = current_swi;
		temp = wait_queue.top();
		if (current_swi.num != temp.num) {
		  current_swi = temp;
		  temp.proc();
		  current_swi = store;
      wait_queue.pop();
		} else {
		  break;
		}
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
  current_swi.num = -1;
	swi_map.clear();
	num = 0;
	begin = 0;
}
