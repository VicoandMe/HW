
#include "OJ.h"

/*
Description  
         给定一个字符串，将字符串中所有和前面重复多余的字符删除，其余字符保留，输出处理后的字符串。需要保证字符出现的先后顺序。
Prototype
         int GetResult(const char *input, char *output)
Input Param 
         input     输入的字符串
Output Param 
         output    输出的字符串
Return Value
         0         成功
         -1        失败及异常
*/
int GetResult(const char *input, char *output)
{
  if (input == 0 || output == 0)
	  return -1;
  int rl = 0;
  int mark[300] = {0};
  for (int i = 0; input[i] != '\0'; i++) {
    if (mark[(int)(input[i])] == 0) {
      mark[(int)(input[i])]++;
      output[rl] = input[i];
      rl ++;
    }
  }
  output[rl] = '\0';
  return 0;
}
