#ifdef OS_WINCE

// testa.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "testa.h"
#include "log4cxx/log4cxx.h"
#include "log4cxx/logger.h"
#include "log4cxx/propertyconfigurator.h"
//#pragma comment(lib , "log4cxx.lib")
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 唯一的应用程序对象

CWinApp theApp;

using namespace std;

int main(int argc, char** argv)
{
	int nRetCode = 0;
	printf("ok\n");
	// 初始化 MFC 并在失败时显示错误
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: 更改错误代码以符合您的需要
		_tprintf(_T("错误: MFC 初始化失败\n"));
		nRetCode = 1;
	}
	else
	{
		// TODO: 在此处为应用程序的行为编写代码。
	}
	log4cxx::PropertyConfigurator::configure("log4cxx.properties");
	log4cxx::LoggerPtr logger = log4cxx::LoggerPtr(
		log4cxx::Logger::getLogger("appMain"));
	
	std::string data = "world1";
	log4cxx::helpers::MessageBuffer oss_; 

	//std::basic_ostringstream<char>* stream = new std::basic_ostringstream<char>();
	//*stream << data;
	//std::basic_string<char> buf;
	//buf.append(data);

	printf("Hello world\n");
	if (logger->isInfoEnabled()) {
		::log4cxx::helpers::MessageBuffer oss_; 
		logger->forcedLog(::log4cxx::Level::getInfo(), oss_.str(oss_ << "Hello " << data), LOG4CXX_LOCATION); 
	}
	int t=100;
	while (t)
	{
		Sleep(1000);
		t--;
	}

	return nRetCode;
}


#endif