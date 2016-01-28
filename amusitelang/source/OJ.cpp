
#include "OJ.h"
#include <vector>
using namespace std;
/*
功能: 求n(n ≤ 65536)以内的所有阿姆斯特朗数
原型：
    int CalcArmstrongNumber(int n);

输入参数：
    int n: n ≤ 65536

返回值：
    n以内的阿姆斯特朗数的数量。
*/
bool judge(int n) {
  int temp = n;
	int store[10] = {0};
	int index = 0;
	while(temp) {
		store[index++] = temp % 10;
		temp = temp/10;
	}
	int sum = 0;
	for (int i = 0; i < index; i++) {
	  sum = sum + store[i]*store[i]*store[i];
	}
	if(sum == n) {
	  return true;
	} else {
	  return false;
	}
}

int CalcArmstrongNumber(int n)
{
    int count = 0;
		if (n == 0 || n == 1) {
		  return 0;
		}
		for(int i = 2; i <= n; i++) {
		  if(judge(n)) {
			  count++;
			}
		}
    return count;
}
