/******************************************************************************

  Copyright (C), 2001-2013, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2013/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2013/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

bool Calculate(int a, int b, int c, int d) {
    char sign[5] = "+-*/";
	for (int i = 0; i < 4; i++) {
	  for (int j = 0; j < 4; j++) {
	    for (int k = 0; k < 4; k++) {
			int count = 0;
			switch(sign[i]) {
				case '+':count = a + b;break;
				case '-':count = a - b;break;
				case '*':count = a * b;break;
				case '/':count = a / b;break;
			}
			switch(sign[j]) {
				case '+':count = count + c;break;
				case '-':count = count - c;break;
				case '*':count = count * c;break;
				case '/':count = count / c;break;
			}
			switch(sign[k]) {
				case '+':count = count + d;break;
				case '-':count = count - d;break;
				case '*':count = count * d;break;
				case '/':count = count / d;break;
			}
            if (count == 24)
				return true;
		}
	  }
	}
	return false;
}

bool Game24Points(int a, int b, int c, int d)
{
	int num[4];
	num[0] = a;
	num[1] = b;
	num[2] = c;
	num[3] = d;
	for (int i = 0; i < 4; i++) {
	  for (int j = 0; j < 4; j++) {
		if (i == j) 
		  continue;
	    for (int k = 0; k < 4; k++) {
		  if (k == j || k == i)
			continue;
		  for (int l = 0; l < 4; l++) {
		    if (l == k || l == j || l == i)
				continue;
		    if (Calculate(num[i],num[j],num[k],num[l]))
			  return true;
		  }
		}
	  }
	}
	return false;
}

//int main() {
//	if(Game24Points(1,1,1,1)) {
//	  printf("yes");
//	} else {
//	  printf("no");
//	}
//}
