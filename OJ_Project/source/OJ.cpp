
#include "OJ.h"

/*
Description  
         ����һ���ַ��������ַ��������к�ǰ���ظ�������ַ�ɾ���������ַ�����������������ַ�������Ҫ��֤�ַ����ֵ��Ⱥ�˳��
Prototype
         int GetResult(const char *input, char *output)
Input Param 
         input     ������ַ���
Output Param 
         output    ������ַ���
Return Value
         0         �ɹ�
         -1        ʧ�ܼ��쳣
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
