/******************************************************************************

  Copyright (C), 2001-2011, Huawei Tech. Co., Ltd.

 ******************************************************************************
  File Name     : 
  Version       : 
  Author        : 
  Created       : 2009/6/1
  Last Modified :
  Description   : 
  Function List :
              
  History       :
  1.Date        : 2009/6/1
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
	CPPUNIT_TEST( TestCase02_1 );
	CPPUNIT_TEST( TestCase03_1 );
	CPPUNIT_TEST( TestCase04_1 );
	CPPUNIT_TEST( TestCase05_1 );
	CPPUNIT_TEST( TestCase06_1 );
	CPPUNIT_TEST( TestCase07_1 );
	CPPUNIT_TEST( TestCase08_1 );
	CPPUNIT_TEST( TestCase09_1 );
    // ��������Ӳ�����������, �������������������
    // CPPUNIT_TEST( TestCasexx );

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
    void TestCase01_1();
	void TestCase02_1();
	void TestCase03_1();
	void TestCase04_1();
	void TestCase05_1();
	void TestCase06_1();
	void TestCase07_1();
	void TestCase08_1();
	void TestCase09_1();
    // ��������Ӳ�����������, ����������ĳ�Ա����
    // void TestCasexx();

};
#endif /*_CEXAMPLE_TEST_H*/