#include <stdlib.h>
#include <iostream>
#include "OJ.h"

using namespace std;

// ���ܣ��ж����� nValue �Ƿ�Ϊˮ�ɻ���
// ���룺 nValueΪ������
// �������
// ���أ��������Ϊˮ�ɻ���������1�����򷵻�0
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


