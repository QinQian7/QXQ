
// EX1_3.h : EX1_3 Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CEX1_3App:
// �йش����ʵ�֣������ EX1_3.cpp
//

class CEX1_3App : public CWinAppEx
{
public:
	CEX1_3App();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CEX1_3App theApp;
