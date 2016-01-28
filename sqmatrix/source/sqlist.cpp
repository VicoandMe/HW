/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2012/03/12
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2012/03/12
    Author      : 
    Modification: Created file

******************************************************************************/
#include <stdlib.h>
#include <iostream>
#define MAXSIZE 5
using namespace std;

struct strmatrix
{
	int rownum; /* ��ά�������� */
	int columnnum; /* ��ά�������� */
	int matrix[MAXSIZE][MAXSIZE];
};

void setnull(struct strmatrix *p)  /*���ÿ�*/
{
  int k,j;
  for(j = 0; j < MAXSIZE; j++) {
		for(k = 0; k < MAXSIZE; k++) {
			p->matrix[j][k] = 0;
		}
	}
	p->rownum = 0;
	p->columnnum = 0;
}

int getelementnum(struct strmatrix *p)  /*��ȡ����Ԫ�ظ���*/
{
	int elementnum = 0;

  elementnum = (p->rownum)*(p->columnnum);

	return elementnum;
}


int getxnum(struct strmatrix *p, int x) /*��������е���ĳ��ֵ��Ԫ�صĸ���*/
{
	int num = 0;

	int i,j;
	for(i = 0; i < p->rownum; i++) {
	  for(j = 0; j < p->columnnum; j++) {
		  if (p->matrix[i][j] == x) {
			  num++;
			}
		}
	}

	return num;
}

void insertrow(struct strmatrix *p,int k,int *x) /* ����1�� */
{
	if (p->rownum + 1 > MAXSIZE) {
	  return;
	}
	if (k >= MAXSIZE) {
	  return;
	}
	int i,j;
	p->rownum = p->rownum + 1;
	for(i = p->rownum-1; i > k; i--) {
	  for(j = 0; j < p->columnnum; j++) {
		  p->matrix[i][j] = p->matrix[i-1][j];
		}
	}
	for(j = 0; j < p->columnnum; j++) {
		  p->matrix[k][j] = x[j];
	}	
}

void insertcolumn(struct strmatrix *p,int i,int *x) /* ����1�� */
{
	if (p->columnnum + 1 > MAXSIZE) {
	  return;
	}
	if (i >= MAXSIZE) {
	  return;
	}
	int k,j;
	p->columnnum = p->columnnum + 1;
	for(k = 0; k < p->rownum; k++) {
	  for(j = p->columnnum-1; j > i ;j--) {
		  p->matrix[k][j] = p->matrix[k][j-1];
		}
	}
	for(j = 0; j < p->rownum; j++) {
		  p->matrix[j][i] = x[j];
	}
}


void matrixtrans(struct strmatrix *p) /* �������û� */
{
	if (p == 0) {
	  return;
	}
	for(int j = 0; j < MAXSIZE; j++) {
		for(int k = j; k < MAXSIZE; k++) {
		  int t;
			t = p->matrix[j][k];
			p->matrix[j][k] = p->matrix[k][j];
			p->matrix[k][j] = t;
		}
	}
	/* ����������ʵ�� */
}

void matrixwhirl(struct strmatrix *p) /* ������˳ʱ����ת90�� */
{
	if (p == 0) {
	  return;
	}
  int b[MAXSIZE][MAXSIZE] = {0};
  for(int j = 0; j < p->rownum; j++) {
		for(int k = 0; k < p->columnnum; k++) {
		  b[k][p->rownum - j - 1] = p->matrix[j][k];
		}
	}
  for(int j = 0; j < p->rownum; j++) {
		for(int k = 0; k < p->columnnum; k++) {
		  p->matrix[j][k] = b[j][k];
		}
	}
}

void matrixplus(struct strmatrix *plu, struct strmatrix *p, struct strmatrix *q) /* ����������� */
{
  if (plu == 0 || p == 0 || q == 0) {
	  return;
	}
	plu->rownum = p->rownum;
	plu->columnnum = p->columnnum;
	for(int j = 0; j < p->rownum; j++) {
		for(int k = 0; k < p->columnnum; k++) {
		  plu->matrix[j][k] = p->matrix[j][k] + q->matrix[j][k];
		}
	}
}

void matrixmultiply(struct strmatrix *mul, struct strmatrix *p, struct strmatrix *q) /* ����������� */
{
  if (mul == 0 || p == 0 || q == 0) {
	  return;
	}
	if (p->columnnum != q->rownum) {
	  return;
	}
	mul->rownum = p->rownum;
	mul->columnnum = q->columnnum;
	for (int i = 0; i < p->rownum; i++) {
	  for (int j = 0; j < q->columnnum; j++) {
		  int sum = 0;
			for (int k = 0; k < p->columnnum; k++) {
			  sum = sum + p->matrix[i][k] * q->matrix[k][j];
			}
			mul->matrix[i][j] = sum;
		}
	}
/* ����������ʵ�� */
}

