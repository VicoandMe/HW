
#include "OJ.h"
#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

/*****************************************************************************
 Prototype    : multiply
 Description  : 两个任意长度的长整数相乘, 输出结果
 Input Param  : 
                const std::string strMultiplierA  乘数A
                const std::string strMultiplierB  乘数B
 Output       : 
                std::string strRst            乘法结果
 Return Value : 
                int                       0  正确  
                                         -1  异常
*****************************************************************************/

struct bignum {
  vector<int> a;
  vector<int> b;
};

void chartonum(string a,string b,bignum &num) {
  int size_a=a.length();
  int size_b=b.length();
  for (int i=size_a-1;i>=0;i--) {
    num.a.push_back(a[i] - '0');
	}
  for (int i=size_b-1;i>=0;i--) 
	{
    num.b.push_back(b[i] - '0');
	}
}

void doMultiply(struct bignum &num,vector<int> &result_num) {
  for (int i = 0; i < num.a.size(); i++) {
	  for (int j = 0; j < num.b.size(); j++) {
		  result_num[i+j] += (num.a[i])*(num.b[j]);
		}
	}

	for (int i = result_num.size() - 1; i >= 0; i--) {
	  if (result_num[i] != 0) {
		  break;
		} else {
		  result_num.pop_back();
		}
	}
	int c = 0;
	for (int i = 0; i < result_num.size();i++) {
	  result_num[i] += c;
		c=result_num[i]/10;
		result_num[i] = result_num[i]%10;
	}
	if (c!=0) {
	  result_num.push_back(c);
	}
}

void numtochar(std::string &strRst,vector<int> &result_num) {
  int size=result_num.size();
	for (int i = 0; i < size; i++) {
	  strRst.push_back(char(result_num[size-1-i]+'0'));
	}
}

int multiply (const std::string strMultiplierA,const std::string strMultiplierB, std::string &strRst) 
{
    if (strMultiplierA.length() == 0 || strMultiplierB.length() == 0) {
		  return -1;
		}
	  struct bignum tBigNum;
		chartonum(strMultiplierA, strMultiplierB, tBigNum);
		vector<int> resultNum(strMultiplierA.length() + strMultiplierB.length(), 0);
		doMultiply(tBigNum, resultNum);
    numtochar(strRst, resultNum);
    if (strRst.empty()) {
		  strRst = "0";
		}
		return 0;
}
