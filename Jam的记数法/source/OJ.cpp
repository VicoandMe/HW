
#include "OJ.h"
 
#include "OJ.h"
#include <stdio.h>
#include <string.h> 
  
/*
����:��������ַ������д����������Jam���������ַ���
    
���������
	 	Char InMinSeq��������С����ĸ�����
		char InMaxSeq: ����������ĸ�����
		int InNumbLen�� �����ַ���λ��
        char InChaStr: �������InNumbLen���ַ����ַ���
���������ָ��ָ����ڴ�����֤��Ч����
	 	char* pBufOutData�����ת������ַ��б��ԡ�\n������
����ֵ
		void

*/

char table[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o'
               ,'p','q','r','s','t','u','v','w','x','y','z'};
 
int Min,Max,Len;

bool findNext(char *str, const char *max) {
  int index = Len - 1;
	for (;index >= 0; index--) {
	  if (str[index] < max[index]) {
		  break;
		}
	}
	if (index < 0) {
	  return false;
	}
	int mark = str[index] - 'a';
	for (int i = 0; i + index < Len; i++) {
	  str[index + i] = table[mark + i + 1];
	}
	return true;
}

void GetResult(int InMinSeq, int InMaxSeq, int InNumbLen, char *InChaStr, char *pBufOutData)
{
	Min = InMinSeq;
	Max = InMaxSeq;
	Len = InNumbLen;
  char maxNum[30];
  for (int i = 0; i < InNumbLen; i++) {
	  maxNum[i] = table[InMaxSeq - InNumbLen + i];
	}
	maxNum[InNumbLen] = '\0';
  int count = 0;
	char store[30];
	for (int i = 0; i <= InNumbLen; i++) {
	  store[i] = InChaStr[i];
	}
  int index = 0;
	while(count < 5 && findNext(store, maxNum)) {
    for(int i = 0; i < Len; i++) {
      pBufOutData[index] = store[i];		
		  index++;
		}
		count++;
    pBufOutData[index] = '\n';
		index++;
	}
	if(count != 0) {
    pBufOutData[index-1] = '\0';
	}
}
/*
int main() {
  int InMinSeq = 2;
    int InMaxSeq = 10;
    int InNumbLen = 5;
	  char InChaStr[30] = "bdfij";

	  char pBufOutData[1024] = {0};

    GetResult(InMinSeq, InMaxSeq, InNumbLen, InChaStr, pBufOutData);
    printf("%s", pBufOutData);
}
*/
