
#include "OJ.h"
#include<iostream>
using namespace std;
/*
����:�ҳ�1��n֮��ͬ�����ĸ���
���룺
    int n������1��n֮���ȫ��ͬ����
���أ�
    int��1��n֮��ͬ�����ĸ���
*/
int SearchSameConstructNum(int n)
{
  int temp,sq;
	int count = 0;
	for(int i = 1; i <= n; i++) {
	  sq = i*i;
		temp = i;
		while(temp != 0) {
		  if (sq % 10 != temp % 10) {
			  break;
			}
			sq = sq / 10;
			temp = temp / 10;
		}
		if(temp == 0) {
		count++;
		}
	}
  return count;
}

//int main() {
//  int k =SearchSameConstructNum(5);
//	cout<< k <<endl;
//}
