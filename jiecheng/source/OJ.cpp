#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "OJ.h"
//#include<iostream>
//using namespace std;
void CalcNN(int n, char *pOut)
{
  int num[200] = {0};
	num[199] = 1;
	int carry = 0;
	if (n != 1) {
	  for (int i = 1; i <= n; i++) {
		  for (int j = 199; j > 0 ; j --) {
			  if (j == 199) {
				  carry = 0;
				}
				num[j] = num[j] * i + carry;
				carry = num[j] / 10;
				num[j] = num[j] % 10;
			}
		}
	}
	bool flag = 0;
	int index = 0;
	for (int i = 0; i < 200; i++) {
		if (num[i] != 0) {
		  flag = 1;
		}
		if (flag) {
		  pOut[index] = char(num[i] + '0');
			index++;
		}
	}
	pOut[index] = '\0';
  return;
}

//int main() {
 // char a[200];
//	CalcNN(100,a);
//	printf("%s\n",a);
//}
