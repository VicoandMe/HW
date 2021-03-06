/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2012/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2012/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <iostream>
using namespace std;

#define null 0
#define MAXSIZE 50

struct strlnode
{
	int data;
	struct strlnode *plast;
	struct strlnode *pnext;
};
void readtolnode(struct strlnode **p, int *a, int size);
void writetosqlist(int *a, struct strlnode *p);
void create(struct strlnode **p, int x)  /*创建双链表(表头节点)*/
{
	struct strlnode *q;

	q = (struct strlnode *)malloc(sizeof(struct strlnode));
	q->data = x;
	q->plast = null;
	q->pnext = null;

	*p = q;

	return;
}

void insertnode(struct strlnode **p, int i, int x) /* 在链表第i个位置插入数据等于x的节点 */
{
  if (0 == p) {
	  return;
	}
	if (i < 0) {
	  return;
	}
	int index = 0;
	struct strlnode * temp = *p;
	while(temp != 0 && index < i - 1) {
	  if (index != i - 1) {
		  temp = temp->pnext;
			index++;
		} else {
		  break;
		}
	}
	if (temp == null) {
	  return;
	}
	struct strlnode *q;

	q = (struct strlnode *)malloc(sizeof(struct strlnode));
	q->data = x;
	q->pnext = temp->pnext;
	q->plast = temp;	
	if(temp->pnext != 0) {
	  (temp->pnext)->plast = q;
	}
	temp->pnext = q;
}

void deletenode(struct strlnode **p, int i) /* 删除链表中第i个节点 */
{
  if (0 == p) {
	  return;
	}
	if (i < 0) {
	  return;
	}
	int index = 0;
	struct strlnode * temp = *p;
	while(temp != 0 && index < i - 1) {
	  if (index != i - 1) {
		  temp = temp->pnext;
			index++;
		} else {
		  break;
		}
	}
	if (index != i - 1) {
	  return;
	}
  struct strlnode *next = temp->pnext;
	temp->pnext = (temp->pnext)->pnext;
  (temp->pnext)->plast = temp;
	free(next);
}

int getnodenum(struct strlnode **p)  /*获取链表中节点个数*/
{
	int nodenum = 0;
  if (0 == p) {
	  return 0;
	}
	struct strlnode * temp = *p;
	while(temp != 0) {
		nodenum++;
		temp = temp->pnext;
	}
	return nodenum;
}

void bignumberplus(struct strlnode **plus, struct strlnode **p, struct strlnode **q) /* 使用链表实现大整数相加 */
{
  int a[100];
	int b[100];
	int c[100] = {0};
  writetosqlist(a, *p);
	writetosqlist(b, *q);
	int lengtha = getnodenum(p) - 1;
	int lengthb = getnodenum(q) - 1;
  int index = 0;
	int i = lengtha - 1;
	int j = lengthb - 1;
	while(i >= 0 || j >= 0) {
	  if (i >= 0) {
		  c[index] += a[i];
			i--;
		}
		if (j >= 0) {
		  c[index] += b[j];
			j--;
		}
		c[index + 1] = c[index] / 10;
		c[index] = c[index] % 10;
		index++;
	}
	if(c[index] == 0) {
	  index--;
	}
	j = index;
	i = 0;
	int t = 0;
 
	while(i != j && i < j) {
	  t = c[i];
		c[i] = c[j];
		c[j] = t;
		i++;
		j--;
	}
	//for(int z = 0; z < index+1; z++) {
	// cout<< c[z];
	//}
	//cout<<endl;
  readtolnode(plus, c, index+1);
}


void readtolnode(struct strlnode **p, int *a, int size)  /* 将数组写入链表中，链表中的数据的先后顺序和数组中的顺序要保持一致 */
{
	int j = 0;
	int data = 0;
	struct strlnode *s = *p;

	for(j = 1; j < (size+1); j++)
	{
		data = *(a + (size-j));
		insertnode(p, 0, data);
	}
	return;
}


void writetosqlist(int *a, struct strlnode *p)  /* 将链表写入数组中，数组中的数据的先后顺序和链表中的顺序要保持一致 */
{
	int j = 0;
	struct strlnode *s = p->pnext;

	while(s != null)
	{
		*(a + j) = s->data;
		s = s->pnext;
		j++;
	}
	return;
}




