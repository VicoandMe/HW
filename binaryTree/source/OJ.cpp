
#include "OJ.h"
#include <string.h>
#include <stdio.h>

/*
Description  
         给定一个二叉树，获取该二叉树的宽度深度。
Prototype
         int GetBiNodeInfo(BiNode &head, unsigned int *pulWidth, unsigned int *pulHeight)
Input Param 
         head   需要获取深度的二叉树头结点
Output Param 
         pulWidth   宽度
         pulHeight  高度
Return Value
         0          成功
         1          失败或其他异常
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
