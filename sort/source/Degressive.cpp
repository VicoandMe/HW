/******************************************************************************

Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

******************************************************************************
File Name     :
Version       :
Author        :
Created       : 
Last Modified :
Description   :
Function List :

History       :
1.Date        : 
Author      :
Modification: Created file

******************************************************************************/
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;


bool cmp(int a ,int b) {
  return a > b;
}
//给出一个非负整数，找到这个非负整数中包含的最大递减数。一个数字的递减数是指相邻的数位从大到小排列的数字。
//如： 95345323，递减数有：953,95,53,53,532,32, 那么最大的递减数为953。
//如果输入的数字为负数，返回-1。
int getMaxDegressiveNum (int num)
{
    // your code here...
	if (num < 0) {
	  return -1;
	}
	if (num == 0) {
	  return 0;
	}
	int t = 0;
	int sign = 0;
	int carry = 0;
	int temp = 0;
	vector<int> deInt;
	while(num) {
		if (num % 10 > sign) {
			temp = num % 10;
			for(int i = 0; i < carry; i++) {
			  temp = temp * 10;
			}
		  t = t + temp;
			carry ++;
			sign  = num % 10;
			num = num / 10;
		} else {
		  deInt.push_back(t);
			carry = 0;
			t = 0;
			sign = 0;
		}
	}
	if (t != 0) {
	  deInt.push_back(t);
	}
	sort(deInt.begin(), deInt.end(), cmp);
	return deInt[0];
}

//int main () {
//  cout<< getMaxDegressiveNum(654321) << endl;
//}
