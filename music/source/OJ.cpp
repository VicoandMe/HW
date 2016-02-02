
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
����:	��������ѡ �ֵ�ƽ���÷֡�
    
���������ָ��ָ����ڴ�����֤��Ч����
	 	char* pInputString���ַ������飬������ĳɼ���������������0-10�����������ֵĳ��Ȳ�����30���ַ�
		int Num������������ѡ�ֵ�������2 <= Num <= 26��
���������ָ��ָ����ڴ�����֤��Ч����
	 	char* pResult��һ��buffer��������в����ߵ�������ƽ���֣�����2λС��������ʽҪ�����£�
			1��������ǰ��ƽ�����ں��м���һ���ո������
			2��ÿ�в����ߵĳɼ�ռһ�У����һ�������߳ɼ�֮��Ҫ���з�����
			3������ɼ�������˳������ 	
����ֵ��
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
