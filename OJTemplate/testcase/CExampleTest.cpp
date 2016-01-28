/******************************************************************************

  Copyright (C), 2001-2012, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     :
  Version       :
  Author        :
  Created       : 2010/9/1
  Last Modified :
  Description   :
  Function List :

  History       :
  1.Date        : 2010/9/1
    Author      :
    Modification: Created file

******************************************************************************/
#include <cppunit/config/SourcePrefix.h>
#include "CExampleTest.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

extern unsigned int Continumax(char** pOutputstr,  char* intputstr);

// 注册测试套到CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// 测试用例实现示例

// SetUp: 在每个用例前执行一次
void CExampleTest::setUp()
{

}

// tearDown: 在每个用例后执行一次
void CExampleTest::tearDown()
{

}

void CExampleTest::TestCase01()
{
	char* intputstr = "abcd12345ed125ss123456789" ;
	char *pOutputstr = NULL;
 	unsigned int nLength = Continumax(&pOutputstr, intputstr);
	CPPUNIT_ASSERT(nLength == 9);
	CPPUNIT_ASSERT((pOutputstr != NULL) && (strcmp(pOutputstr,"123456789") == 0));
	free(pOutputstr);
}