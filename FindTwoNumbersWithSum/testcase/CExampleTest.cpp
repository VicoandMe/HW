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
#include "OJ.h"

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
	int  aData[] = {1, 2, 4, 7, 11, 15};
	int  iNum1, iNum2;
	bool bReturn;

	bReturn = FindTwoNumbersWithSum(aData, 6, 15, &iNum1, &iNum2);
	
	CPPUNIT_ASSERT(true == bReturn);
	CPPUNIT_ASSERT(4  == iNum1);
	CPPUNIT_ASSERT(11 == iNum2);
}

void CExampleTest::TestCase02()
{
	
}

void CExampleTest::TestCase03()
{
    
}

// 在这里添加测试用例实现
// void CExampleTest::TestCasexx()
// {
//
// }
