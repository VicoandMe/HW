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
#include <string.h>

extern unsigned int strlenth(char *s);
extern void strcopy(char **target, char *source);
extern int strcompare(char *s, char *t);
extern void strcombine(char **x, char *s, char *t);
extern void strcatch(char *s, unsigned int index, unsigned int lenth, char **t);
extern bool strsubstr(char *s, char *sub);

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


/* －－－－－－－－－－获取字符串长度类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase01_1()
{
	char s[] = "china";
	unsigned int lenth = 0;

	lenth = strlenth(s);

	CPPUNIT_ASSERT(lenth == 5);
}

void CExampleTest::TestCase01_2()
{
	char s[] = "";
	unsigned int lenth = 0;

	lenth = strlenth(s);

	CPPUNIT_ASSERT(lenth == 0);
}
/* －－－－－－－－－－获取字符串长度类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－字符串拷贝类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase02_1()
{
	char s[] = "china";
	char *t = 0;
	unsigned int lenth = 0;

	strcopy(&t, s);

	CPPUNIT_ASSERT(strcmp(s, t) == 0);

	free(t);
}
/* －－－－－－－－－－字符串拷贝类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－字符串比较类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase03_1()
{
	char s[] = "china";
	char t[] = "american";
	int result = 0;

	result = strcompare(s, t);

	CPPUNIT_ASSERT(result == 1);
}

void CExampleTest::TestCase03_2()
{
	char s[] = "China";
	char t[] = "china";
	int result = 0;

	result = strcompare(s, t);

	CPPUNIT_ASSERT(result == -1);
}

void CExampleTest::TestCase03_3()
{
	char s[] = "china";
	char t[] = "china";
	int result = 0;

	result = strcompare(s, t);

	CPPUNIT_ASSERT(result == 0);
}

void CExampleTest::TestCase03_4()
{
	char s[] = "china";
	char t[] = "chinagood";
	int result = 0;

	result = strcompare(s, t);

	CPPUNIT_ASSERT(result == -1);
}

void CExampleTest::TestCase03_5()
{
	char s[] = "chinagood";
	char t[] = "china";
	int result = 0;

	result = strcompare(s, t);

	CPPUNIT_ASSERT(result == 1);
}
/* －－－－－－－－－－字符串比较类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－字符串连接类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase04_1()
{
	char s[] = "chin";
	char t[] = "ese";
	char *x;

	strcombine(&x, s, t);

	char y[] = "chinese";
	CPPUNIT_ASSERT(strcmp(x, y) == 0);

	free(x);
}
/* －－－－－－－－－－字符串连接类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－字符串截取类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase05_1()
{
	char s[] = "chinese is great";
	char *x;

	strcatch(s, 8, 2, &x);

	char y[] = "is";
	CPPUNIT_ASSERT(strcmp(x, y) == 0);

	free(x);
}

void CExampleTest::TestCase05_2()
{
	char s[] = "chinese is great";
	char *x = 0;

	strcatch(s, 8, 0, &x);

	CPPUNIT_ASSERT(x == 0);
}

void CExampleTest::TestCase05_3()
{
	char s[] = "chinese is great";
	char *x = 0;

	strcatch(s, 8, 17, &x);

	CPPUNIT_ASSERT(x == 0);
}

void CExampleTest::TestCase05_4()
{
	char s[] = "chinese is great";
	char *x = 0;

	strcatch(s, 8, 9, &x);

	CPPUNIT_ASSERT(x == 0);
}
/* －－－－－－－－－－字符串截取类用例－－－－－－－－－－－－－ */

/* －－－－－－－－－－子串查找类用例－－－－－－－－－－－－－ */
void CExampleTest::TestCase06_1()
{
	char s[] = "chinese is good";
	char t[] = "ese";
	bool result = 0;

	result = strsubstr(s, t);

	CPPUNIT_ASSERT(result == 1);
}

void CExampleTest::TestCase06_2()
{
	char s[] = "chinese is good";
	char t[] = "chinese is good";
	bool result = 0;

	result = strsubstr(s, t);

	CPPUNIT_ASSERT(result == 1);
}

void CExampleTest::TestCase06_3()
{
	char s[] = "chinese is good";
	char t[] = "chinese is good!";
	bool result = 0;

	result = strsubstr(s, t);

	CPPUNIT_ASSERT(result == 0);
}

void CExampleTest::TestCase06_4()
{
	char s[] = "chinese is good";
	char t[] = "est";
	bool result = 0;

	result = strsubstr(s, t);

	CPPUNIT_ASSERT(result == 0);
}
/* －－－－－－－－－－子串查找类用例－－－－－－－－－－－－－ */