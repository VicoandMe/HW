#include <stdlib.h>
#include <iostream>
#include "OJ.h"

using namespace std;

// 功能：判断输入 nValue 是否为水仙花数
// 输入： nValue为正整数
// 输出：无
// 返回：如果输入为水仙花数，返回1，否则返回0
unsigned int IsDaffodilNum(unsigned int  nValue)
{
	unsigned int i=0,j,sum,tmp,tmp1;
	unsigned int n=nValue;

	while(n)
	{
		i++;
		n/=10;
	}
	if(i<3)return 0;

	n=nValue;
	sum=0;
	while(n)
	{
		tmp=n%10;
		tmp1=tmp;
		for(j=1;j<i;j++)
			tmp1*=tmp;
		sum+=tmp1;
		n/=10;
	}
	if(sum==nValue)return 1;
	return 0;
}


