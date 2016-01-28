
#include "OJ.h"
#include <vector>
using namespace std;
/*
����: ��n(n �� 65536)���ڵ����а�ķ˹������
ԭ�ͣ�
    int CalcArmstrongNumber(int n);

���������
    int n: n �� 65536

����ֵ��
    n���ڵİ�ķ˹��������������
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
