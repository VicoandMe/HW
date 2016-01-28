#include "OJ.h"
/*
功能: 矩阵相乘
    
输入: MatrixA,MatrixB
    
输出: MatrixC

返回: 0
     
*/

int matrix(int **MatrixA, int **MatrixB, int **MatrixC, int N)
{
  if(MatrixA == 0 || MatrixA == 0 || MatrixB == 0) {
	  return 0;
	}
	for (int i = 0; i < N; i++) {
	  for (int j = 0; j < N; j++) {
		  int sum = 0;
			for (int k = 0; k < N; k++) {
			  //sum = sum + MatrixA[i][k]*MatrixB[k][j];
			  sum = sum + (*((int*)MatrixA + i*N + k))*(*((int*)MatrixB + k*N + j));
			}
			//MatrixC[i][j] = sum;
		  (*((int*)MatrixC + i*N+j)) = sum;
		}
	}
	return 0;
}

