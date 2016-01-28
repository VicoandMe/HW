#include <stdlib.h>
#include "PhoneBookProcess.h"


/*
功能: 检查是否有两个或多个公司拥有相同的电话号码,并统计输出

输入参数: inFileName  - 包含个性电话号码个数与列表的源文件名      [格式请见题目说明PPT]
        outFileName - 输出统计重复号码的结果的目标文件名                  [格式请见题目说明PPT]

输出参数: 无
返回: 0 - 成功
        1 - 其它各种错误，如文件不存在
*/

int trans[27];

int PhoneBookProcess(const char *inFileName,const char *outFileName) 
{
	trans['A' - 'A'] = 2;
	trans['B' - 'A'] = 2;
  trans['C' - 'A'] = 2;
  trans['D' - 'A'] = 3;
  trans['E' - 'A'] = 3;
  trans['F' - 'A'] = 3;
  trans['G' - 'A'] = 4;
  trans['H' - 'A'] = 4;
  trans['I' - 'A'] = 4;
  trans['J' - 'A'] = 5;
  trans['K' - 'A'] = 5;
  trans['L' - 'A'] = 5;
  trans['M' - 'A'] = 6;
  trans['N' - 'A'] = 6;
  trans['O' - 'A'] = 6;
  trans['P' - 'A'] = 7;
  trans['Q' - 'A'] = 7;
  trans['R' - 'A'] = 7;
  trans['S' - 'A'] = 7;
  trans['T' - 'A'] = 8;
  trans['U' - 'A'] = 8;
  trans['V' - 'A'] = 8;
  trans['W' - 'A'] = 9;
  trans['X' - 'A'] = 9;
  trans['Y' - 'A'] = 9;
  trans['Z' - 'A'] = 9;
	
	return 0;
}
