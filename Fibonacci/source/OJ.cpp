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
/*  输入扩展Fibonacci数列的前2个数字first和second，要得到的数字的序列号num  */
/*  输入：扩展Fibonacci数列对应的序号的数字                                 */
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
/*  输入扩展Fibonacci数列的前2个数字first和second，和数字的序列号num    */
/*  输出：扩展Fibonacci数列对应的序号的数列之前（包括这个数列本身）的所有的数列之和         */
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

