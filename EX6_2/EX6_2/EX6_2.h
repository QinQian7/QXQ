
// EX6_2.h : EX6_2 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CEX6_2App:
// �йش����ʵ�֣������ EX6_2.cpp
//

class CEX6_2App : public CWinApp
{
public:
	CEX6_2App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEX6_2App theApp;
