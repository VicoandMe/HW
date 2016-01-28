//#include <stdio.h>
//#include <iostream>
#include "OJ.h"

//using namespace std;
/*
功能: 求解放置8皇后方案的个数。
输入：
    无
返回：
    int：放置8皇后方案的个数
*/
void PlaceQueen(int n, int mid, int x, int x_mark, int y_mark, int z_mark, int t_mark, int *count) {
  for (int i = 0; i < n; i++) {
    if (((x_mark & (1 << x))==0) && ((y_mark & (1 << i)) == 0) && ((z_mark & (1 << (mid + x - i)))
				== 0) && ((t_mark & (1 << (x + i)))==0)) {
	  if (x != n-1) {
		PlaceQueen(n, mid, x + 1, (x_mark | (1 << x)), (y_mark | (1 << i)), 
				(z_mark | (1 << (mid + x - i))), (t_mark | (1 << (x + i))),count);
//	    cout<< x_mark << " "<< (x_mark | (1 << x)) << endl;
	  } else {
	    *count = *count + 1;
	  }
	}
  }
}

int PlaceQueenMethodNum(int n)
{
    /*在这里实现功能*/
    int x_mark = 0;
	int y_mark = 0;
	int z_mark = 0;
	int t_mark = 0;
	int count = 0;
	int mid = n - 1;
	for (int i = 0; i < n; i++) {
	  PlaceQueen(n, mid, 1, (x_mark | (1 << 0)), (y_mark | (1 << i)), (z_mark | (1 << (mid - i))), (t_mark | (1 << (0 + i))),&count);
	}
    return count;
}

//int main() {
//  printf("%d\n", PlaceQueenMethodNum(8));
//}
