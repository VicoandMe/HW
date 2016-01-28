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
#ifndef _CEXAMPLE_TEST_H
#define _CEXAMPLE_TEST_H

#include <cppunit/extensions/HelperMacros.h>
#include "OJ.h"

class CExampleTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CExampleTest );
	CPPUNIT_TEST( TestCase01 );
    // ��������Ӳ�����������, �������������������
    // CPPUNIT_TEST( TestCasexx );
    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
	void TestCase00();
    // ��������Ӳ�����������, ����������ĳ�Ա����
    // void TestCasexx();
    void TestCase01();
	void TestCase02();
	void TestCase03();
	void TestCase04();
	void TestCase05();

};

#endif /*_CEXAMPLE_TEST_H*/