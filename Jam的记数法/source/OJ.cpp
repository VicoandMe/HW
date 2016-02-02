
#include "OJ.h"
 
#include "OJ.h"
#include <stdio.h>
#include <string.h> 
  
/*
功能:对输入的字符串进行处理，输出符合Jam记数法的字符串
    
输入参数：
	 	Char InMinSeq：输入最小的字母的序号
		char InMaxSeq: 输入最大的字母的序号
		int InNumbLen： 输入字符的位数
        char InChaStr: 输入具有InNumbLen个字符的字符串
输出参数（指针指向的内存区域保证有效）：
	 	char* pBufOutData：输出转换后的字符列表，以‘\n’区分
返回值
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
