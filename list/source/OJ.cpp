#include <stdlib.h>
#include "OJ.h"
#include <iostream>
#include <map>

using namespace std;
/*
功能:  输入一个不带头节点的单向链表(链表的节点数小于100),删除链表中内容重复的节点（重复的节点全部删除），剩余的节点逆序倒排。
    
输入:   pstrIn： 输入一个不带头节点的单向链表
    
输出:   pstrOut：删除内容重复的节点后，逆序排列的链表(不带头节点,链表第一个节点的内存已经申请)。
     
返回:

示例:
输入链表的内容依次为 6,7,8,8,9,10,6
则输出链表的内容依次应该是 10,9,7
     
*/


int iChanProcess(strNode * pstrIn,strNode * pstrOut)
{
  map<int, int> map;
	if (pstrIn == NULL || pstrOut == NULL) {
	  return -1;
	}
	strNode* temp = pstrIn;
	for (;temp != NULL; temp = temp->pstrNext) {
	  if (map.count(temp->data) == 0) {
			map[temp->data] = 1;
		} else {
			map[temp->data] ++;
		}
	}
  temp = pstrIn;
	for (;temp->pstrNext != NULL; temp = temp->pstrNext) {
	  if (map[temp->data] == 1) {
			strNode* node = new strNode();
		  node->data = temp->data;
		  node->pstrNext = pstrOut->pstrNext;
		  pstrOut->pstrNext = node;
		}
	}
  if (map[temp->data] == 1) {
	  pstrOut->data = temp->data;
	} else {
		pstrOut->data = (pstrOut->pstrNext)->data;
		pstrOut->pstrNext = (pstrOut->pstrNext)->pstrNext;
	}
	return 0;
}

/* 释放链表 */
void vFreeChan(strNode * pstrChan)
{
    strNode* p = pstrChan;
		while(p != NULL) {
		  strNode* node = p;
			p = p->pstrNext;
			delete node;
		}
    return;
}
