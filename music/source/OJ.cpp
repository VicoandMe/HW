
#include "OJ.h"
#include <stdio.h>
#include <string.h> 
#include <string>
#include <sstream>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
/*
功能:	计算所有选 手的平均得分。
    
输入参数（指针指向的内存区域保证有效）：
	 	char* pInputString：字符串数组，是输入的成绩和姓名。分数是0-10的整数，名字的长度不超过30个字符
		int Num：整数，参赛选手的数量，2 <= Num <= 26。
输出参数（指针指向的内存区域保证有效）：
	 	char* pResult：一块buffer，输出所有参赛者的姓名和平均分（保留2位小数）。格式要求如下：
			1、姓名在前，平均分在后，中间由一个空格隔开；
			2、每行参赛者的成绩占一行（最后一个参赛者成绩之后不要换行符）；
			3、输出成绩按输入顺序排序。 	
返回值：
		void

*/

struct part {
	vector<int> score;
	string result;
};

bool cmp(int a ,int b) {
  return a < b;
}

void GetResult(char* pInput[], int Num, char *pResult)
{
	int rLength = 0;
	for (int i = 0; i < Num; i++) {
    struct part t;
		int length = strlen(pInput[i]);
		int index = 0;
		int score = 0;
		int count = 0;
		for(;index < length; index++) {
		  if (pInput[i][index] != ' ') {
			  score = score*10 + (int)(pInput[i][index] - '0');
			} else {
			  count++;
				t.score.push_back(score);
				score = 0;
			}
			if (count == 7) {
			  break;
			}
		}
		index++;
		for(;index < length; index++) {
		  pResult[rLength] = pInput[i][index];
			rLength++;
		}
    pResult[rLength] = ' ';
		rLength++;
    sort(t.score.begin(),t.score.end(),cmp);
    double r = 0;
		for (int si = 1; si < 6; si++) {
			r += t.score[si];
		}
		r = r / 5;
		char buf[20];
		sprintf(buf, "%.2lf\n",r);
		for (int si = 0; si < strlen(buf); si++) {
		  pResult[rLength] = buf[si];
			rLength++;
		}
	}
  pResult[rLength-1] = '\0';
	return;
}

//int main() {
//	char *input[] = {"10 10 10 10 10 10 9 xiaoyuanwang"};
//	char result[100] = {0};
//	GetResult(input, 1, result);
//        printf("%s", result);
//}
