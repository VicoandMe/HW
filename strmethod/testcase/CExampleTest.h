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
	CPPUNIT_TEST( TestCase01_2 );
	CPPUNIT_TEST( TestCase02_1 );
	CPPUNIT_TEST( TestCase03_1 );
	CPPUNIT_TEST( TestCase03_2 );
	CPPUNIT_TEST( TestCase03_3 );
	CPPUNIT_TEST( TestCase03_4 );
	CPPUNIT_TEST( TestCase03_5 );
	CPPUNIT_TEST( TestCase04_1 );
	CPPUNIT_TEST( TestCase05_1 );
	CPPUNIT_TEST( TestCase05_2 );
	CPPUNIT_TEST( TestCase05_3 );
	CPPUNIT_TEST( TestCase05_4 );
	CPPUNIT_TEST( TestCase06_1 );
	CPPUNIT_TEST( TestCase06_2 );
	CPPUNIT_TEST( TestCase06_3 );
	CPPUNIT_TEST( TestCase06_4 );

    // 在这里添加测试用例声明, 将测试用例加入测试套
    // CPPUNIT_TEST( TestCasexx );

    CPPUNIT_TEST_SUITE_END();

public:
    void setUp();
    void tearDown();
	void TestCase01_1();
	void TestCase01_2();
	void TestCase02_1();
	void TestCase03_1();
	void TestCase03_2();
	void TestCase03_3();
	void TestCase03_4();
	void TestCase03_5();
	void TestCase04_1();
	void TestCase05_1();
	void TestCase05_2();
	void TestCase05_3();
	void TestCase05_4();
	void TestCase06_1();
	void TestCase06_2();
	void TestCase06_3();
	void TestCase06_4();

    // 在这里添加测试用例声明, 声明测试类的成员函数
    // void TestCasexx();

};
#endif /*_CEXAMPLE_TEST_H*/