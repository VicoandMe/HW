#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "OJ.h"


/* 功能：在字符串中找出连续最长的数字串，并把这个串的长度返回
函数原型：
   unsigned int Continumax(char** pOutputstr,  char* intputstr)
输入参数：
   char* intputstr  输入字符串
输出参数：
   char** pOutputstr: 连续最长的数字串，如果连续最长的数字串的长度为0，应该返回空字符串
   pOutputstr 指向的内存应该在函数内用malloc函数申请，由调用处负责释放

返回值：
  连续最长的数字串的长度

 */
unsigned int Continumax(char** pOutputstr,  char* intputstr)
{
	*pOutputstr = (char *)malloc(sizeof(char)*1000);
	(*pOutputstr)[0] = '\0';
	if (intputstr == 0) {
	  return 0;
	}	
  int length = strlen(intputstr);
	int sign[1000] = {0};	
	int max_length = 0;
	if (intputstr[0] >= '0' && intputstr[0] <= '9') {
	  sign[0] = 1;
		max_length = 1;
	}
  for (int i = 1; i < length; i++) {
	  if (intputstr[i] >= '0' && intputstr[i] <= '9') {
	    sign[i] = sign[i-1] + 1;
	    if (sign[i] > max_length) {
			  max_length = sign[i];
			}
		} else {
		  sign[i] = 0;
		}
	}
	if (max_length != 0) {
	  for (int i = length - 1; i >= 0; i--) {
	    if (sign[i] == max_length) {
		    int indexO = 0;
			  for (int index = i - max_length + 1; index < i + 1; index++) {
			    (*pOutputstr)[indexO] = intputstr[index];
				  indexO++;
			  }
			  (*pOutputstr)[indexO] = '\0';
			  return max_length;
			  break;
		  }
	  }
	}
	return 0;
}

//int main() {
//  char a[] = "abcd12345ed125ss123058789";
//	char **p; 
//	p = (char **)malloc(sizeof(char *));
//	printf("%d\n",Continumax(p,a));
//	printf("%s\n",*p);
//}
