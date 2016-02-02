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
//����һ���Ǹ��������ҵ�����Ǹ������а��������ݼ�����һ�����ֵĵݼ�����ָ���ڵ���λ�Ӵ�С���е����֡�
//�磺 95345323���ݼ����У�953,95,53,53,532,32, ��ô���ĵݼ���Ϊ953��
//������������Ϊ����������-1��
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
