
#include "OJ.h"
#include<iostream>
using namespace std;
/*
功能:找出1至n之间同构数的个数
输入：
    int n：查找1至n之间的全部同构数
返回：
    int：1至n之间同构数的个数
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
