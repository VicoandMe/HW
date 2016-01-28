
#include "OJ.h"
#include <string.h>
#include <stdio.h>

/*
Description  
         ����һ������������ȡ�ö������Ŀ����ȡ�
Prototype
         int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
Input Param 
         head   ��Ҫ��ȡ��ȵĶ�����ͷ���
Output Param 
         pulWidth   ���
         pulHeight  �߶�
Return Value
         0          �ɹ�
         1          ʧ�ܻ������쳣
*/
int width[1000];
int DEEP;

void DFS(int deep, BiNode *n) {
  if (n != 0) {
	  if (deep > DEEP) {
		  DEEP = deep;
		}
		width[deep] ++;
		DFS(deep+1, n->left);
		DFS(deep+1, n->right);
	}
}
int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
{
	for(int i = 0; i < 1000; i++) {
	  width[i] = 0;
	}
	DEEP = 0;
  DFS(DEEP, &head);
	DEEP++;
  *pulHeight = DEEP;
	*pulWidth = 1;
	for(int i = 0; i < 1000; i++) {
	  if (*pulWidth < width[i]) {
		  *pulWidth = width[i];
		}
	}
	return 0;
}
