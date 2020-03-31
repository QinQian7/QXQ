
// EX4_2.h : EX4_2 应用程序的主头文件
//
#pragma once

#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// CEX4_2App:
// 有关此类的实现，请参阅 EX4_2.cpp
//

class CEX4_2App : public CWinAppEx
{
public:
	CEX4_2App();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEX4_2App theApp;
