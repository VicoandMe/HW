/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/08/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/08/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/*
详细描述：   
int JudgeTrainSequence (int maxNum, char *pOutSeq);
输入参数：
	 	int maxNum：进站的火车最大编号
	 	char* pOutSeq：使用字符串表示火车出站序列
输出参数（指针指向的内存区域保证有效）：
	 	无。
返回值：
		Int: 根据输入的进站序列判断，如果输入的出战序列是可能的，返回1，否则返回0；

*/

int JudgeTrainSequence (int maxNum, char *pOutSeq)
{
	int length = strlen(pOutSeq);
	for (int i = 0; i < length - 1; i++) {
	  char last = pOutSeq[i];
		for (int j = i + 1; j < length; j++) {
			if ((int)(pOutSeq[i] - '0') > maxNum || (int)(pOutSeq[j] - '0') > maxNum) {
				return 0;
			}
		  if (pOutSeq[i] > pOutSeq[j]) {
			  if (pOutSeq[j] > last) {
					return 0;
				} else {
				  last = pOutSeq[j];
				}
			}
		}
	}
	return 1;
}

//int main() {
//  char a[] = "43512";
//	printf("%d\n",JudgeTrainSequence(5, a));
//}



