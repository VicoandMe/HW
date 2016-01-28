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
#include <cppunit/TextOutputter.h>
#include <cppunit/XmlOutputter.h>
#include <cppunit/BriefTestProgressListener.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/TestResult.h>
#include <cppunit/TestResultCollector.h>
#include <cppunit/TestRunner.h>
#include <string>
#include <windows.h>

using namespace std;
string g_strFilePath;

int main(int argc, char* argv[])
{
	TCHAR strExePath[MAX_PATH];  
	memset(strExePath, 0, MAX_PATH);    
	GetModuleFileName(NULL, strExePath, MAX_PATH); 

	string strExeFile;
	short*p = (short*)strExePath;
	while (*p)
	{
		strExeFile += (char)(*p);
		p++;
	}

	g_strFilePath = strExeFile.substr(0, strExeFile.find("project")) + "testcase\\";

	// Create the event manager and test controller
    CPPUNIT_NS::TestResult controller;

    // Add a listener that colllects test result
    CPPUNIT_NS::TestResultCollector result;
    controller.addListener( &result );

    // Add a listener that print dots as test run.
    CPPUNIT_NS::BriefTestProgressListener progress;
    controller.addListener( &progress );

    // Add the top suite to the test runner
    CPPUNIT_NS::TestRunner runner;
    runner.addTest( CPPUNIT_NS::TestFactoryRegistry::getRegistry("All Tests").makeTest() );
    runner.run( controller );

    // Print test in a text format.
    CPPUNIT_NS::TextOutputter outputter( &result, CPPUNIT_NS::stdCOut() );
    outputter.write();

    // This for XML output
    std::ofstream file( "TestResult.xml" );
    CPPUNIT_NS::XmlOutputter xml( &result, file );
    xml.setStyleSheet( "report.xsl" );
    xml.write();
    file.close();

    return result.wasSuccessful() ? 0 : 1;
}
