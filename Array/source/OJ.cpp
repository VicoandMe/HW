#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include "OJ.h"
using namespace std;

// 功能：将输入的数组排成最小的数
// 输入： int a[]:整型数组
//        int nCount:数组长度
//        char * strRst 返回值
// 输出：
// 返回：成功返回0  异常返回-1
bool cmp(char* str1, char* str2) {
	return strcmp(str1, str2) < 0;
}

int  smallestDigit(int a[],int nCount,char * strRst)
{
	if (a == NULL || nCount <= 0 || strRst == NULL) {
		return -1;
	}
	char *strNumber;
	vector<char *> strNumbers;
	for (int i = 0; i < nCount; i++) {
		strNumber = new char[10];
		sprintf(strNumber, "%d", a[i]);
		strNumbers.push_back(strNumber);
	}
	int index = 0;
  sort(strNumbers.begin(), strNumbers.end(),cmp);
	for (int i = 0; i < nCount; i++) {
		for (int j = 0; j < strlen(strNumbers[i]); j++) {
			strRst[index++] = strNumbers[i][j];
		}
	}
	strRst[index] = '\0';
	return 1;
}
