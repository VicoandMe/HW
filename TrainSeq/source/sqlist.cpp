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
��ϸ������   
int JudgeTrainSequence (int maxNum, char *pOutSeq);
���������
	 	int maxNum����վ�Ļ������
	 	char* pOutSeq��ʹ���ַ�����ʾ�𳵳�վ����
���������ָ��ָ����ڴ�����֤��Ч����
	 	�ޡ�
����ֵ��
		Int: ��������Ľ�վ�����жϣ��������ĳ�ս�����ǿ��ܵģ�����1�����򷵻�0��

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



