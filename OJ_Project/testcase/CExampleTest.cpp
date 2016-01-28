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

// ע������׵�CppUnit
CPPUNIT_TEST_SUITE_REGISTRATION( CExampleTest );

// ��������ʵ��ʾ��

// SetUp: ��ÿ������ǰִ��һ��
void CExampleTest::setUp()
{

}

// tearDown: ��ÿ��������ִ��һ��
void CExampleTest::tearDown()
{

}

void CExampleTest::TestCase01()
{
    char result[1024] = {0};
    CPPUNIT_ASSERT(GetResult("abadcbad",result) == 0);
    CPPUNIT_ASSERT(strcmp(result, "abdc")==0);
}

void CExampleTest::TestCase02()
{
}

void CExampleTest::TestCase03()
{
}


// ��������Ӳ�������ʵ��
// void CExampleTest::TestCasexx()
// {
//
// }
