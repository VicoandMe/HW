
#include "OJ.h"
#include <string.h>
//#include <stdio.h>

/*
功能:计算字符串的最小周期。
原型：
    int GetMinPeriod(char *string);

输入参数：
    char * string：字符串。

返回值：
    int 字符串最小周期。

*/

int GetMinPeriod(char *inputstring)
{
  
  int length = strlen(inputstring);
  for (int i = 1; i < length;i++) {
    bool flag = 0;
	if (length%i == 0) {
	  flag = 1;
	  for (int j = i; j < length; j++) {
	    if (inputstring[j] != inputstring[j-i]) {
		  flag = 0;
		  break;
		}
	  }
	  if(flag == 1) {
	    return i;
	  }
	}
  }
  return length;
}

//int main() {
//  char a[] = "abcabcabcabc....\0";
//  printf("%d\n",GetMinPeriod(a));
//}
