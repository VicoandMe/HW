/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2009/10/10
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2009/10/10
    Author      : 
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>

#define MAXSIZE 5

struct strmatrix
{
	int rownum; /* 二维数组行数 */
	int columnnum; /* 二维数组行数 */
	int matrix[MAXSIZE][MAXSIZE];
};

extern void setnull(struct strmatrix *p);
extern int getelementnum(struct strmatrix *p);
extern int getxnum(struct strmatrix *p, int x);
extern void insertrow(struct strmatrix *p,int i,int *x);
extern void insertcolumn(struct strmatrix *p,int i,int *x);
extern void matrixtrans(struct strmatrix *p);
extern void matrixwhirl(struct strmatrix *p);
extern void matrixplus(struct strmatrix *plu, struct strmatrix *p, struct strmatrix *q);
extern void matrixmultiply(struct strmatrix *mul, struct strmatrix *p, struct strmatrix *q);


// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{
	return;
}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{
	return;
}


/* －－－－－－－－－－数组清空类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase01_1()
{
	int j = 0;
	int k = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  0,  0,
				    4,  5,  6,  0,  0,
				    7,  8,  9,  0,  0,
				    0,  0,  0,  0,  0,
			            0,  0,  0,  0,  0}; 
	struct strmatrix p = {0};
	p.rownum = 3;
	p.columnnum = 3;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	setnull(&p);

	CPPUNIT_ASSERT(p.rownum == 0);
	CPPUNIT_ASSERT(p.columnnum == 0);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(p.matrix[j][k] == 0);
		}
	}
}
/* －－－－－－－－－－数组清空类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－获取数组长度类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase02_1()
{
	int j = 0;
	int k = 0;
	int elementnum = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  5,
                                6,  7,  8,  9, 10,
                               11, 12, 13, 14, 15,
                               16, 17, 18, 19, 20,
                                0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 5;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	elementnum = getelementnum(&p);

	CPPUNIT_ASSERT(elementnum == 20);
}
/* －－－－－－－－－－获取数组长度类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－使用获取数组中某值的元素个数类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase03_1()
{
	int j = 0;
	int k = 0;
	int xnum = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  5,
				    6,  5,  8,  9, 10,
				    11, 12, 13, 14, 15,
				    16, 17, 18,  5, 20,
				    0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 5;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	xnum = getxnum(&p, 5);

	CPPUNIT_ASSERT(xnum == 3);
}
/* －－－－－－－－－－使用下标获取数组元素类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－矩阵中插入1行类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase04_1()
{
	int j = 0;
	int k = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  0,
                                5,  6,  7,  8,  0,
                                9, 10, 11, 12,  0,
                               13, 14, 15, 16,  0,
                                0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 4;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	int x[4] = {17,18,19,20};

	insertrow(&p, 2, x);

	int b[MAXSIZE][MAXSIZE] =   { 1,  2,  3,  4,  0,
                                      5,  6,  7,  8,  0,
			              7, 18, 19, 20,  0,
                                      9, 10, 11, 12,  0,
                                      13, 14, 15, 16, 0};

	CPPUNIT_ASSERT(p.rownum == 5);
	CPPUNIT_ASSERT(p.columnnum == 4);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(p.matrix[j][k] == b[j][k]);
		}
	}
}
/* －－－－－－－－－－矩阵中插入1行类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－矩阵中插入1列类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase05_1()
{
	int j = 0;
	int k = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  0,
				    5,  6,  7,  8,  0,
                		    9, 10, 11, 12,  0,
				    13, 14, 15, 16,  0,
				    0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 4;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	int x[4] = {17,18,19,20};

	insertcolumn(&p, 2, x);

	int b[MAXSIZE][MAXSIZE] =   { 1,  2, 17, 3,  4,
                                      5,  6, 18, 7,  8,
                                      9, 10, 19, 11, 12,
                                     13, 14, 20, 15, 16,
                                      0,  0,  0,  0,  0};

	CPPUNIT_ASSERT(p.rownum == 4);
	CPPUNIT_ASSERT(p.columnnum == 5);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(p.matrix[j][k] == b[j][k]);
		}
	}
}
/* －－－－－－－－－－矩阵中插入1列类用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－方矩阵置换类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase06_1()
{
	int j = 0;
	int k = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  0,
                                    5,  6,  7,  8,  0,
                                    9, 10, 11, 12,  0,
                                   13, 14, 15, 16,  0,
                                    0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 4;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	matrixtrans(&p);

	int b[MAXSIZE][MAXSIZE] =   { 1,  5,  9, 13,  0,
                                      2,  6, 10, 14,  0,
                                      3,  7, 11, 15,  0,
                                      4,  8, 12, 16,  0,
                                      0,  0,  0,  0,  0};

	CPPUNIT_ASSERT(p.rownum == 4);
	CPPUNIT_ASSERT(p.columnnum == 4);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(p.matrix[j][k] == b[j][k]);
		}
	}
}
/* －－－－－－－－－－方矩阵置换类用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－方矩顺时针旋转90度用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase07_1()
{
	int j = 0;
	int k = 0;
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  0,
                                    5,  6,  7,  8,  0,
                                    9, 10, 11, 12,  0,
                                    13, 14, 15, 16,  0,
                                    0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 4;
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
		}
	}

	matrixwhirl(&p);

	int b[MAXSIZE][MAXSIZE] =   { 13,  9,  5,  1,  0,
                                      14, 10,  6,  2,  0,
                                      15, 11,  7,  3,  0,
                                      16, 12,  8,  4,  0,
                                      0,  0,  0,  0,  0};

	CPPUNIT_ASSERT(p.rownum == 4);
	CPPUNIT_ASSERT(p.columnnum == 4);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(p.matrix[j][k] == b[j][k]);
		}
	}
}
/* －－－－－－－－－－方矩顺时针旋转90度用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－矩阵相加类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase08_1()
{
	int j = 0;
	int k = 0;
	struct strmatrix plu = {0};
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  0,  0,
                                4,  5,  6,  0,  0,
                                7,  8,  9,  0,  0,
                               10, 11, 12,  0,  0,
                                0,  0,  0,  0,  0};
	int b[MAXSIZE][MAXSIZE] = { 1,  2,  3,  0,  0,
                                4,  5,  6,  0,  0,
                                7,  8,  9,  0,  0,
                               10, 11, 12,  0,  0,
                                0,  0,  0,  0,  0};


	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 3;

	struct strmatrix q = {0};
	q.rownum = 4;
	q.columnnum = 3;

	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
			q.matrix[j][k] = b[j][k];
		}
	}

	matrixplus(&plu, &p, &q);

	int c[MAXSIZE][MAXSIZE] =   {  2,  4,  6,  0,  0,
                                   8, 10, 12,  0,  0,
                                  14, 16, 18,  0,  0,
                                  20, 22, 24,  0,  0,
                                   0,  0,  0,  0,  0};

	CPPUNIT_ASSERT(plu.rownum == 4);
	CPPUNIT_ASSERT(plu.columnnum == 3);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(plu.matrix[j][k] == c[j][k]);
		}
	}
}
/* －－－－－－－－－－矩阵相加类用例－－－－－－－－－－－－－ */


/* －－－－－－－－－－矩阵相乘类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase09_1()
{
	int j = 0;
	int k = 0;
	struct strmatrix mul = {0};
	int a[MAXSIZE][MAXSIZE] = { 1,  2,  3,  0,  0,
                                4,  5,  6,  0,  0,
                                7,  8,  9,  0,  0,
                               10, 11, 12,  0,  0,
                                0,  0,  0,  0,  0};
	int b[MAXSIZE][MAXSIZE] = { 1,  2,  3,  4,  0,
                                5,  6,  7,  8,  0,
                                9, 10, 11, 12,  0,
                                0,  0,  0,  0,  0,
                                0,  0,  0,  0,  0};

	struct strmatrix p = {0};
	p.rownum = 4;
	p.columnnum = 3;

	struct strmatrix q = {0};
	q.rownum = 3;
	q.columnnum = 4;

	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			p.matrix[j][k] = a[j][k];
			q.matrix[j][k] = b[j][k];
		}
	}

	matrixmultiply(&mul, &p, &q);

	int c[MAXSIZE][MAXSIZE] =   {  38,  44,  50,  56,  0,
                                   83,  98, 113, 128,  0,
                                  128, 152, 176, 200,  0,
                                  173, 206, 239, 272,  0,
                                    0,   0,   0,   0,  0};

	CPPUNIT_ASSERT(mul.rownum == 4);
	CPPUNIT_ASSERT(mul.columnnum == 4);
	for(j = 0; j < MAXSIZE; j++)
	{
		for(k = 0; k < MAXSIZE; k++)
		{
			CPPUNIT_ASSERT(mul.matrix[j][k] == c[j][k]);
		}
	}
}
/* －－－－－－－－－－矩阵相乘类用例－－－－－－－－－－－－－ */
