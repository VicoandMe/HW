/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2012/07/18
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2012/07/18
    Author      : 
    Modification: Created file

******************************************************************************/


/************************************************************************/
/*  GetExtFibonacci                                                         */
/*  ������չFibonacci���е�ǰ2������first��second��Ҫ�õ������ֵ����к�num  */
/*  ���룺��չFibonacci���ж�Ӧ����ŵ�����                                 */
/************************************************************************/
int GetExtFibonacci(int first , int second, int num)
{
  int Fib[100] = {0};
	Fib[0] = first;
	Fib[1] = second;
	for (int i = 2; i < num; i++) {
	  Fib[i] = Fib[i-1] + Fib[i-2];
	}
	return Fib[num-1];
}

/************************************************************************/
/*  CalcTotalValueOfExtFibonacci                                        */
/*  ������չFibonacci���е�ǰ2������first��second�������ֵ����к�num    */
/*  �������չFibonacci���ж�Ӧ����ŵ�����֮ǰ������������б��������е�����֮��         */
/************************************************************************/
int CalcTotalValueOfExtFibonacci(int first , int second, int num)
{
  int Fib[100] = {0};
	Fib[0] = first;
	Fib[1] = second;
	for (int i = 2; i < num; i++) {
	  Fib[i] = Fib[i-1] + Fib[i-2];
	}

	int sumFib[100] = {0};
	sumFib[0] = first;
	sumFib[1] = first + second;
	for (int i = 2; i < num; i++) {
	  sumFib[i] = sumFib[i-1] + Fib[i];
	}
	return sumFib[num-1];
}

