/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

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
#ifndef _CEXAMPLE_TEST_H
#define _CEXAMPLE_TEST_H

#include <cppunit/extensions/HelperMacros.h>

class CExampleTest : public CPPUNIT_NS::TestFixture
{
    CPPUNIT_TEST_SUITE( CExampleTest );
	CPPUNIT_TEST( TestCase01_1 );
	CPPUNIT_TEST( TestCase01_2 );
	CPPUNIT_TEST( TestCase01_3 );

    // ��������Ӳ�����������, �������������������
    // CPPUNIT_TEST( TestCasexx );

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
	void TestCase01_1();
	void TestCase01_2();
	void TestCase01_3();

    // ��������Ӳ�����������, ����������ĳ�Ա����
    // void TestCasexx();
};

#endif /*_CEXAMPLE_TEST_H*/